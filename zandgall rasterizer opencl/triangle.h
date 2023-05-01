#pragma once

#include <math.h>

#include "shading.h"

#ifndef WIDTH
#define WIDTH 512
#endif
#ifndef HEIGHT
#define HEIGHT 512
#endif

void (*tri_draw_func)(int, int, float, vec4);

void shade_triangle(const struct vertice* const args, vec4 (*fs)(const vertice* const, const uniforms), const uniforms f_uni) { 
    /**
     * args can be given to us in any order here. What we need to do, is find the top, bottom, and middle points (in terms of y).
     * It doesn't have to be in terms of y, but that's what we chose, arbitrarily
     * We will use pointers to each vertice, as there is no new data being created. We're just sorting points
    */
    const struct vertice* t, * m, * b;

    // Calculate screenspace y-position of each arg, in order to compare them and find the top, middle, and bottom point
    const float a0y = args[0].pos.y / args[0].pos.w;
    const float a1y = args[1].pos.y / args[1].pos.w;
    const float a2y = args[2].pos.y / args[2].pos.w;

    // Find the top point
    if (a0y <= a1y && a0y <= a2y) {
        t = args;

        m = args + 1;
        b = args + 2;
    } else if (a1y <= a2y && a1y <= a0y) {
        t = args + 1;

        m = args + 2;
        b = args;
    } else {
        t = args + 2;

        m = args;
        b = args + 1;
    }

    // If middle and bottom aren't set correctly yet, swap them
    if (m->pos.y/m->pos.w > b->pos.y/b->pos.w) {
        const struct vertice* _ = b;
        b = m;
        m = _;
    }

    /**
     * We now have the top, middle and bottom points.
     * We will now create new vertices to represent the screen position.
     * We only need 6 values, the on-screen (x, y) positions of each of the 3 points
     * We will store as a float because we do exclusively floating point math with them
    */

    const float st_x = floorf(WIDTH * 0.5 * (t->pos.x/t->pos.w+1));
    const float st_y = floorf(HEIGHT * 0.5 * (t->pos.y/t->pos.w + 1));

    const float sm_x = floorf(WIDTH * 0.5 * (m->pos.x/m->pos.w + 1));
    const float sm_y = floorf(HEIGHT * 0.5 * (m->pos.y/m->pos.w + 1));

    const float sb_x = floorf(WIDTH * 0.5 * (b->pos.x/b->pos.w + 1));
    const float sb_y = floorf(HEIGHT * 0.5 * (b->pos.y/b->pos.w + 1));

    /**
     * We use barycentric coordinates to aide in shading our triangles.
     * Barycentric calculations require "/ area of full triangle"
     * So we will compute 1 over the area of the triangle
    */
    const float inv_area = 1 / ((sb_x - st_x) * (sm_y - st_y) - (sb_y - st_y) * (sm_x - st_x));
    if (inv_area == INFINITY || inv_area == -INFINITY || inv_area == 0) // If this triangle is impossible to draw, (or infinitesmal) then just return
        return;

    /**
     * Now, we shall calculate the slopes of each line.
     * tb being top->bottom slope, tm = top->middle slope, mb = middle->bottom slope
     * 
     * KEEP NOTE:
     * These slopes are X / Y, so they are technically "inverse slopes", but for every y+=1, we will increase x values by these slopes.
     * They are the change in x over the change in y
    */
    const float tb = (sb_x - st_x) / (sb_y - st_y);
    const float tm = (sm_x - st_x) / (sm_y - st_y);
    const float mb = (sb_x - sm_x) / (sb_y - sm_y);

    /**
     * During the rasterization, we will have one point that travels from the top to the bottom, and one that travels from the top to the middle
     * We will call them ants, and they only need to be represented by their x-position
     * As we scan down from y=st_y to y=sm_y, the "straight_ant" will be updated by the top->bottom slope
     * and the "switch_ant" will be updated by the top->middle slope
     * Once we hit y=sm_y, the straight_ant will continue to be updated by top->bottom, but
     * switch_ant will be updated by middle->bottom slope
    */
    float straight_ant = st_x, switch_ant = st_x;

    /**
     * In order to scan from left to right, we need to know which ant is to the left, and which is to the right.
     * We could call min() every loop, but we camiddleost ant
     * If the slope from top->middle is greater than the slope from top->middle, then the left-most ant is the one that goes from top->middle (switch_ant)
    */
    float* minm = &straight_ant;
    if (tb > tm)
        minm = &switch_ant;

    
    /**
     * If the top of the triangle is flat, (i.e. the top->middle slope is +- infinity)
     * then we need to skip directly to the middle->bottom half of the triangle.
     * In this instance, switch_ant needs to have the x-position of the middle point at the beginning
    */
    if (tm == INFINITY || tm == -INFINITY) // Flat top
        switch_ant = sm_x;

    // The y-loop. Loop from y = st_y, to sm_y. Along the way, increment straight and switch ant by their respective slopes
    for (int y = st_y; y < sm_y; y++, straight_ant += tb, switch_ant += tm)
        if (y >= 0 && y < HEIGHT) { // only procede if inside the screen. (In case of clip failure, or rounding errors that cause a point to exist off screen)
            // The x-loop, loop from the minimum x, to either straight_ant or switch_ant (continue until x is smaller than neither of them)
            for (int x = *minm; x < straight_ant || x < switch_ant; x++)
                if (x >= 0 && x < WIDTH) { // only procede if inside the screen
                    // Calculate UVW (barycentric) coordinates.
                    float u = ((sb_x - x) * (sm_y - y) - (sb_y - y) * (sm_x - x)) * inv_area;
                    float v = ((sb_x - st_x) * (y - st_y) - (sb_y - st_y) * (x - st_x)) * inv_area;
                    float w = ((x - st_x) * (sm_y - st_y) - (y - st_y) * (sm_x - st_x)) * inv_area;

                    // Calculate current point's distance from the "camera"
                    float d = 1.f / (u / t->pos.w + v / m->pos.w + w / b->pos.w);

                    // Get a physical representation of the on-screen point, interpolating vertice attributes for shading
                    struct vertice current_vertice;
                    current_vertice.pos = v_scale(v_add(v_add(v_scale(t->pos, u / t->pos.w), v_scale(m->pos, v / m->pos.w)), v_scale(b->pos, w / b->pos.w)), d);
                    
                    current_vertice.vec2_n = t->vec2_n;
                    current_vertice.vec2_a = (vec2*)malloc(t->vec2_n*sizeof(vec2));
                    for(int i = 0; i < t->vec2_n; i++)
                        current_vertice.vec2_a[i] = v_scale2(v_add2(v_add2(v_scale2(t->vec2_a[i], u / t->pos.w), v_scale2(m->vec2_a[i], v / m->pos.w)), v_scale2(b->vec2_a[i], w / b->pos.w)), d);

                    current_vertice.vec3_n = t->vec3_n;
                    current_vertice.vec3_a = (vec3*)malloc(t->vec3_n*sizeof(vec3));
                    for(int i = 0; i < t->vec3_n; i++)
                        current_vertice.vec3_a[i] = v_scale3(v_add3(v_add3(v_scale3(t->vec3_a[i], u / t->pos.w), v_scale3(m->vec3_a[i], v / m->pos.w)), v_scale3(b->vec3_a[i], w / b->pos.w)), d);
                    
                    current_vertice.vec4_n = t->vec4_n;
                    current_vertice.vec4_a = (vec4*)malloc(t->vec4_n*sizeof(vec4));
                    for(int i = 0; i < t->vec4_n; i++)
                        current_vertice.vec4_a[i] = v_scale(v_add(v_add(v_scale(t->vec4_a[i], u / t->pos.w), v_scale(m->vec4_a[i], v / m->pos.w)), v_scale(b->vec4_a[i], w / b->pos.w)), d);

                    // Call the given shade function with the interpolated vertice attributes, x and y screen position, and draw function
                    // shade(&current_vertice, x, y, current_vertice.pos.z/current_vertice.pos.w, draw);
                    tri_draw_func(x, y, current_vertice.pos.z / current_vertice.pos.w, fs(&current_vertice, f_uni));

                    free(current_vertice.vec2_a);
                    free(current_vertice.vec3_a);
                    free(current_vertice.vec4_a);
                }
        }

    // See previous loop. Only difference hear is y looping from sm_y to sb_y, and switch_ant being incremented by mb
    for (int y = sm_y; y < sb_y; y++, straight_ant += tb, switch_ant += mb)
        if (y >= 0 && y < HEIGHT) {
            for (int x = *minm; x < straight_ant || x < switch_ant; x++)
                if (x >= 0 && x < WIDTH) {
                    float u = ((sb_x - x) * (sm_y - y) - (sb_y - y) * (sm_x - x)) * inv_area;
                    float v = ((sb_x - st_x) * (y - st_y) - (sb_y - st_y) * (x - st_x)) * inv_area;
                    float w = ((x - st_x) * (sm_y - st_y) - (y - st_y) * (sm_x - st_x)) * inv_area;
                    float d = 1.f / (u / t->pos.w + v / m->pos.w + w / b->pos.w);

                    struct vertice current_vertice;
                    current_vertice.pos = v_scale(v_add(v_add(v_scale(t->pos, u / t->pos.w), v_scale(m->pos, v / m->pos.w)), v_scale(b->pos, w / b->pos.w)), d);
                    current_vertice.vec2_n = t->vec2_n;
                    current_vertice.vec2_a = (vec2*)malloc(t->vec2_n*sizeof(vec2));
                    for(int i = 0; i < t->vec2_n; i++)
                        current_vertice.vec2_a[i] = v_scale2(v_add2(v_add2(v_scale2(t->vec2_a[i], u / t->pos.w), v_scale2(m->vec2_a[i], v / m->pos.w)), v_scale2(b->vec2_a[i], w / b->pos.w)), d);

                    current_vertice.vec3_n = t->vec3_n;
                    current_vertice.vec3_a = (vec3*)malloc(t->vec3_n*sizeof(vec3));
                    for(int i = 0; i < t->vec3_n; i++)
                        current_vertice.vec3_a[i] = v_scale3(v_add3(v_add3(v_scale3(t->vec3_a[i], u / t->pos.w), v_scale3(m->vec3_a[i], v / m->pos.w)), v_scale3(b->vec3_a[i], w / b->pos.w)), d);
                    
                    current_vertice.vec4_n = t->vec4_n;
                    current_vertice.vec4_a = (vec4*)malloc(t->vec4_n*sizeof(vec4));
                    for(int i = 0; i < t->vec4_n; i++)
                        current_vertice.vec4_a[i] = v_scale(v_add(v_add(v_scale(t->vec4_a[i], u / t->pos.w), v_scale(m->vec4_a[i], v / m->pos.w)), v_scale(b->vec4_a[i], w / b->pos.w)), d);
                    
                    // shade(&current_vertice, x, y, current_vertice.pos.z/current_vertice.pos.w, draw);
                    tri_draw_func(x, y, current_vertice.pos.z / current_vertice.pos.w, fs(&current_vertice, f_uni));

                    free(current_vertice.vec2_a);
                    free(current_vertice.vec3_a);
                    free(current_vertice.vec4_a);
                }
        }
}