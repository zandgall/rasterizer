#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clipping.h"

typedef struct face {
    int a_v, a_vt, a_vn;
    int b_v, b_vt, b_vn;
    int c_v, c_vt, c_vn;
} face;

typedef struct object {
    vec4* vertices;
    int n_vertices;
    vec2* uvs;
    int n_uvs;
    vec3* normals;
    int n_normals;
    face* faces;
    int n_faces;
} object;

// https://en.wikipedia.org/wiki/Wavefront_.obj_file
object* load_obj(const char* filepath) {
    FILE *file = fopen(filepath, "r");

    char line[255];
    vec4 verts[3000]; // Supports up to 1000 vertices
    int nverts = 0;
    vec2 uvs[3000];
    int nuvs = 0;
    vec3 norms[3000];
    int nnorms = 0;
    
    face faces[6000];
    int nfaces = 0;

    while (fgets(line, 255, file)) {
        if (line[0] == 'v') {
            if (line[1] == ' ') {
                // Vertice
                char* end, * end2;
                verts[nverts].x = strtod(line + 2, &end);
                verts[nverts].y = strtod(end, &end2);
                verts[nverts].z = strtod(end2, NULL);
                verts[nverts].w = 1;
                nverts++;
            }
            if (line[1] == 't') {
                // UV
                char* end;
                uvs[nuvs].x = strtod(line + 3, &end);
                uvs[nuvs].y = strtod(end, NULL);
                nuvs++;
            }
            if (line[1] == 'n') {
                // Normal
                char* end, * end2;
                norms[nnorms].x = strtod(line + 3, &end);
                norms[nnorms].y = strtod(end, &end2);
                norms[nnorms].z = strtod(end2, NULL);
                nnorms++;
            }
        }
        else if (line[0] == 'f') {
            char* _0, * _1;

            // Need to -1 every read index, to convert from 1-index to 0-indexed
            if (nuvs + nnorms == 0) { // Only vertices
                faces[nfaces].a_v = strtol(line + 2, &_0, 10)-1;
                faces[nfaces].b_v = strtol(_0, &_1, 10)-1;
                faces[nfaces].c_v = strtol(_1, NULL, 10)-1;

                faces[nfaces].a_vt = -1;
                faces[nfaces].b_vt = -1;
                faces[nfaces].c_vt = -1;

                faces[nfaces].a_vn = -1;
                faces[nfaces].b_vn = -1;
                faces[nfaces].c_vn = -1;

            }
            else if (nnorms == 0) { // Vertices + UV
                faces[nfaces].a_v = strtol(line + 2, &_0, 10)-1;
                faces[nfaces].a_vt = strtol(_0+1, &_1, 10)-1;
                faces[nfaces].b_v = strtol(_1+1, &_0, 10)-1;
                faces[nfaces].b_vt = strtol(_0+1, &_1, 10)-1;
                faces[nfaces].c_v = strtol(_1+1, &_0, 10)-1;
                faces[nfaces].c_vt = strtol(_0, NULL, 10)-1;

                faces[nfaces].a_vn = -1;
                faces[nfaces].b_vn = -1;
                faces[nfaces].c_vn = -1;
            }
            else if (nuvs == 0) { // Vertices + Normals
                faces[nfaces].a_v = strtol(line + 2, &_0, 10)-1;
                faces[nfaces].a_vn = strtol(_0+2, &_1, 10)-1;
                faces[nfaces].b_v = strtol(_1+1, &_0, 10)-1;
                faces[nfaces].b_vn = strtol(_0+2, &_1, 10)-1;
                faces[nfaces].c_v = strtol(_1+1, &_0, 10)-1;
                faces[nfaces].c_vn = strtol(_0+2, NULL, 10)-1;

                faces[nfaces].a_vt = -1;
                faces[nfaces].b_vt = -1;
                faces[nfaces].c_vt = -1;
            }
            else { // Vertices, uvs, and normals
                faces[nfaces].a_v = strtol(line + 2, &_0, 10)-1;
                faces[nfaces].a_vt = strtol(_0+1, &_1, 10)-1;
                faces[nfaces].a_vn = strtol(_1+1, &_0, 10)-1;
                faces[nfaces].b_v = strtol(_0+1, &_1, 10)-1;
                faces[nfaces].b_vt = strtol(_1+1, &_0, 10)-1;
                faces[nfaces].b_vn = strtol(_0+1, &_1, 10)-1;
                faces[nfaces].c_v = strtol(_1+1, &_0, 10)-1;
                faces[nfaces].c_vt = strtol(_0+1, &_1, 10)-1;
                faces[nfaces].c_vn = strtol(_1+1, NULL, 10)-1;
            }
            nfaces++;
        }
    }

    object* out = (object*) malloc(sizeof(object));
    out->n_faces = nfaces;
    out->faces = (face*)malloc(nfaces*sizeof(face));
    memcpy(out->faces, faces, nfaces*sizeof(face));
    out->n_vertices = nverts;
    out->vertices = (vec4*)malloc(nverts*sizeof(vec4));
    memcpy(out->vertices, verts, nverts*sizeof(vec4));
    out->n_normals = nnorms;
    out->normals = (vec3*)malloc(nnorms*sizeof(vec3));
    memcpy(out->normals, norms, nnorms*sizeof(vec3));
    out->n_uvs = nuvs;
    out->uvs = (vec2*)malloc(nuvs*sizeof(vec2));
    memcpy(out->uvs, uvs, nuvs*sizeof(vec2));

    fclose(file);
    return out;
}

void draw_object(const object* const obj, vertex (*vs)(const struct vertex* const, const uniforms), const uniforms v_uni, vec4(*fs)(const struct vertex* const, const uniforms), const uniforms f_uni) {
    vertex verts[3]; 

    verts[0].vec4_n = 0;
    verts[0].vec4_a = NULL;
    verts[0].vec3_n = 1;
    verts[0].vec3_a = (vec3*)malloc(sizeof(vec3));
    verts[0].vec2_n = 1;
    verts[0].vec2_a = (vec2*)malloc(sizeof(vec2));

    verts[1].vec4_n = 0;
    verts[1].vec4_a = NULL;
    verts[1].vec3_n = 1;
    verts[1].vec3_a = (vec3*)malloc(sizeof(vec3));
    verts[1].vec2_n = 1;
    verts[1].vec2_a = (vec2*)malloc(sizeof(vec2));

    verts[2].vec4_n = 0;
    verts[2].vec4_a = NULL;
    verts[2].vec3_n = 1;
    verts[2].vec3_a = (vec3*)malloc(sizeof(vec3));
    verts[2].vec2_n = 1;
    verts[2].vec2_a = (vec2*)malloc(sizeof(vec2));
    
    for(int i = 0; i < obj->n_faces; i++) {
        verts[0].pos = obj->vertices[obj->faces[i].a_v];
        verts[1].pos = obj->vertices[obj->faces[i].b_v];
        verts[2].pos = obj->vertices[obj->faces[i].c_v];

        if(obj->faces[i].a_vt==-1) {
            verts[0].vec2_a[0] = (vec2){0, 0};
            verts[1].vec2_a[0] = (vec2){0, 0};
            verts[2].vec2_a[0] = (vec2){0, 0};
        } else {
            verts[0].vec2_a[0] = obj->uvs[obj->faces[i].a_vt];
            verts[1].vec2_a[0] = obj->uvs[obj->faces[i].b_vt];
            verts[2].vec2_a[0] = obj->uvs[obj->faces[i].c_vt];
        }

        if(obj->faces[i].a_vn == -1) {
            verts[0].vec3_a[0] = (vec3){0, 0, 0};
            verts[1].vec3_a[0] = (vec3){0, 0, 0};
            verts[2].vec3_a[0] = (vec3){0, 0, 0};
        } else {
            verts[0].vec3_a[0] = obj->normals[obj->faces[i].a_vn];
            verts[1].vec3_a[0] = obj->normals[obj->faces[i].b_vn];
            verts[2].vec3_a[0] = obj->normals[obj->faces[i].c_vn];
        }

        draw(verts, vs, v_uni, fs, f_uni);
    }

    free(verts[0].vec2_a);
    free(verts[0].vec3_a);
    free(verts[1].vec2_a);
    free(verts[1].vec3_a);
    free(verts[2].vec2_a);
    free(verts[2].vec3_a);
}