#include <stdio.h>
#include <stdlib.h>

#define CL_TARGET_OPENCL_VERSION 210
#include <CL/cl.h>

#include <time.h>

#define MAX_SOURCE_SIZE (0x100000)
#define LOG_SIZE (100000)

int main(void) {
    int *A = (int*)malloc(sizeof(int)*1024);
    int *B = (int*)malloc(sizeof(int)*1024);
    for(int i = 0; i < 1024; i++) {
        A[i] = i;
        B[i] = 1024-i;
    }

    FILE *fp;
    char* source;
    size_t source_size;

    fp = fopen("kernel.cl", "r");
    if(!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(1);
    }

    source = (char*)malloc(MAX_SOURCE_SIZE);
    source_size = fread(source, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);
    char logging[LOG_SIZE];
    size_t log_size = 0;
    struct timespec tstart = {0, 0}, tend = {0, 0};
    timespec_get(&tstart, TIME_UTC);
    // CL Start
    cl_platform_id platform_id = NULL;
    cl_platform_id* platform_ids = (cl_platform_id*)malloc(2*sizeof(cl_platform_id));
    cl_device_id device_id = NULL;
    cl_uint num_platforms;
    cl_uint num_devices;
    cl_int ret = clGetPlatformIDs(2, platform_ids, &num_platforms);
    platform_id = platform_ids[1]; // Need second platform cause I'm an idiot
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &num_devices);

    // Create OpenCL context
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &num_devices);

    // Command queue    
    cl_command_queue command_queue = clCreateCommandQueueWithProperties(context, device_id, NULL, &ret);
    
    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%ldns Setup\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // Memory buffers
    cl_mem a_mem = clCreateBuffer(context, CL_MEM_READ_ONLY, 1024 * sizeof(int), NULL, &ret);
    cl_mem b_mem = clCreateBuffer(context, CL_MEM_READ_ONLY, 1024 * sizeof(int), NULL, &ret);
    cl_mem c_mem = clCreateBuffer(context, CL_MEM_WRITE_ONLY, 1024 * sizeof(int), NULL, &ret);

    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns create memory\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);

    // Write to mem bufs
    ret = clEnqueueWriteBuffer(command_queue, a_mem, CL_TRUE, 0, 1024*sizeof(int), A, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, b_mem, CL_TRUE, 0, 1024*sizeof(int), B, 0, NULL, NULL);

    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns write memory\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);

    // Set up program from kernel source
    cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source, (const size_t*)&source_size, &ret);
    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns create program\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // Build program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    if(ret!=CL_BUILD_SUCCESS) {
        char* out = (char*)malloc(sizeof(char)*0x1000000);
        size_t out_len;
        ret = clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, 0x1000000, out, &out_len);
        printf("%.*s\n", (int)out_len, out);
    }

    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns build program\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // Create kernel
    cl_kernel kernel = clCreateKernel(program, "vector_add", &ret);
    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns create kernel\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // Set args
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&b_mem);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&c_mem);
    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns set up args\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // EXECUTE!!
    size_t items_size = 1024;
    size_t local_size = 64;
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &items_size, &local_size, 0, NULL, NULL);
    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns run program\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // Get result
    int *C = (int*)malloc(sizeof(int)*1024);
    ret = clEnqueueReadBuffer(command_queue, c_mem, CL_TRUE, 0, 1024*sizeof(int), C, 0, NULL, NULL);
    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns query result\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // Display
    for(int i = 0; i < 1024; i++)
        printf("%d + %d = %d\n", A[i], B[i], C[i]);
    timespec_get(&tend, TIME_UTC);
    log_size += snprintf(logging + log_size, LOG_SIZE, "%luns print result\n", tend.tv_nsec - tstart.tv_nsec);
    timespec_get(&tstart, TIME_UTC);
    // Clean
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(a_mem);
    ret = clReleaseMemObject(b_mem);
    ret = clReleaseMemObject(c_mem);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    free(A);
    free(B);
    free(C);
    puts(logging);
    return 0;
}