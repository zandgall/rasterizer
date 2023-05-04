#define WIDTH (1000)
#define HEIGHT (1000)
__constant uint SCREEN[WIDTH*HEIGHT];
__constant uchar FRAME_BUFF[WIDTH*HEIGHT];
__constant float DEPTH_BUFFER[WIDTH*HEIGHT];
__constant uchar FRAME = 1;

void draw_func(int x, int y, float z, float4 in) {
    if(y<=0 || y > HEIGHT || x < 0 || x >= WIDTH)
        return;
    SCREEN[(HEIGHT-y)*WIDTH + x] = ((uchar)(max(min(in.x, 1), 0)*255)<<16) + ((uchar)(max(min(in.y, 1), 0)*255) << 8) + (uchar)(max(min(in.y, 1), 0)*255) + 255<<24;
    // FRAME_BUFF[(HEIGHT-y)*WIDTH + x] = FRAME;
    // DEPTH_BUFF[(HEIGHT-y)*WIDTH + x] = FRAME;
}

