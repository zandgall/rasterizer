#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <SDL2/SDL.h>
#undef main
#include "conf.h"
#include "shading.h"
#include "clipping.h"
#include "object.h"

SDL_Renderer* rend;
SDL_Surface* surf;

unsigned char frame_buff[WIDTH*HEIGHT], frame = 1;
float depth_buff[WIDTH*HEIGHT];

void draw_func(int x, int y, float z, vec4 in) {
    // If the current pixel (x, y) was drawn this frame, and is closer to the camera, don't draw over it
    if(y <= 0 || y > HEIGHT || x < 0 || x >= WIDTH)
        return;
    if(frame_buff[(HEIGHT-y) * WIDTH + x] == frame && depth_buff[(HEIGHT-y) * WIDTH + x] < z)
        return;
    Uint32* targ = (Uint32*)((Uint8*)surf->pixels + (HEIGHT-y) * surf->pitch + x * surf->format->BytesPerPixel);
    *targ = (((Uint8)(fminf(fmaxf(in.x, 0), 1)*255)) << 16) + (((Uint8)(fminf(fmaxf(in.y, 0), 1)*255)) << 8) + (Uint8)(fminf(fmaxf(in.z, 0), 1)*255) + (255<<24);
    frame_buff[(HEIGHT-y) * WIDTH + x] = frame;
    depth_buff[(HEIGHT-y) * WIDTH + x] = z;
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* wind = SDL_CreateWindow("Zandgall Rasterizing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    // rend = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    surf = SDL_GetWindowSurface(wind);
    printf("%d", surf->format->format);
    SDL_Event ev;
    char running = 1;
    tri_draw_func = &draw_func;

    const struct SDL_FPoint verts[4] = {
        {400, 150},
        {200, 450},
        {600, 450},
        {400, 150}
    };

    int c;
    stbi_set_flip_vertically_on_load(1);
    sampler2D monkey_image;
    monkey_image.data = stbi_load("monkey.png", &monkey_image.w, &monkey_image.h, &c, 3);

    cubemap skybox;
    skybox.sides[0].data = stbi_load("skybox/back.jpg", &skybox.sides[0].w, &skybox.sides[0].h, &c, 3);
    skybox.sides[1].data = stbi_load("skybox/front.jpg", &skybox.sides[1].w, &skybox.sides[1].h, &c, 3);
    skybox.sides[2].data = stbi_load("skybox/bottom.jpg", &skybox.sides[2].w, &skybox.sides[2].h, &c, 3);
    skybox.sides[3].data = stbi_load("skybox/top.jpg", &skybox.sides[3].w, &skybox.sides[3].h, &c, 3);
    skybox.sides[4].data = stbi_load("skybox/left.jpg", &skybox.sides[4].w, &skybox.sides[4].h, &c, 3);
    skybox.sides[5].data = stbi_load("skybox/right.jpg", &skybox.sides[5].w, &skybox.sides[5].h, &c, 3);

    object* monkey = load_obj("monkey.obj");
    object* cube = load_obj("cube.obj");
    object* plane = load_obj("plane.obj");
    object* pawn = load_obj("pawn.obj");

    matrix persp = perspective(3.14159265f/2.f, WIDTH / HEIGHT, 0.1, 100.0);
    matrix tf_monkey = identity();
    m_rotate(&tf_monkey, 0.72, (vec3){0, 1, 0});
    m_rotate(&tf_monkey, 0.6, (vec3){1, 0, 0});
    m_translate(&tf_monkey, (vec3){0, 0.5, 0});

    matrix tf_monkey2 = identity();
    m_rotate(&tf_monkey2, 2.72, (vec3){0, 1, 0});
    m_rotate(&tf_monkey2, 0.6, (vec3){1, 0, 0});
    m_translate(&tf_monkey2, (vec3){-3, 0.5, -2});

    matrix tf_plane = identity();
    m_scale(&tf_plane, (vec3){5, 1, 5});
    m_rotate(&tf_plane, 0.72, (vec3){0, 1, 0});
    m_translate(&tf_plane, (vec3){0, 0, 0});

    matrix tf_cube2 = identity();
    m_rotate(&tf_cube2, -1.22, (vec3){1, 0, 0});
    m_rotate(&tf_cube2, 0.72, (vec3){0, 1, 0});
    m_translate(&tf_cube2, (vec3){-4, 4.5, 0});

    matrix tf_cube3 = identity();
    // m_scale(&tf_cube3, (vec3){0.5, 0.5, 0.5});
    m_rotate(&tf_cube3, -0.42, (vec3){0, 1, 0});
    m_scale(&tf_cube3, (vec3){0.5, 0.5, 1.7});
    // tf_cube3 = m_mult(tf_cube3, (matrix){(vec4){0.5, 0, 0, 0}, (vec4){0, 0.5, 0, 0}, (vec4){0, 0, 1.7, 0}, (vec4){0, 0, 0, 1}});
    m_translate(&tf_cube3, (vec3){3, 0.5, 2});

    matrix tf_pawn = identity();
    m_translate(&tf_pawn, (vec3){3, 1, -6});

    matrix tf_skybox = identity();

    uniforms mvp_uni;
    mvp_uni.m = (matrix*)malloc(3*sizeof(matrix));
    mvp_uni.m[0] = persp;

    uniforms skybox_uni;
    skybox_uni.v3 = (vec3*)malloc(sizeof(vec3));
    skybox_uni.f = (float*)malloc(sizeof(float));
    skybox_uni.c = &skybox;

    uniforms monkey_uni;
    monkey_uni.v3 = (vec3*)malloc(5*sizeof(vec3));
    monkey_uni.f = (float*)malloc(sizeof(float));    
    monkey_uni.s = &monkey_image;
    monkey_uni.c = &skybox;

    monkey_uni.v3[0] = (vec3){-10000, 20000, -10000};

    monkey_uni.v3[1] = (vec3){0.0, 0.0, 0.1};
    monkey_uni.v3[2] = (vec3){0, 0.5, 1};
    monkey_uni.v3[3] = (vec3){1, 1, 0.9};

    vec3 cam_center = (vec3){0, 0, 0};
    vec3 cam_dir = v_normalize((vec3){1, 1, 1});
    float cam_dist = 5;

    matrix cam = lookAt(v_scale3(cam_dir, cam_dist), (vec3){0, 0, 0}, (vec3){0, 1, 0});
    while(running) {
        while(SDL_PollEvent(&ev)){
            if(ev.type == SDL_QUIT) {
                running = 0;
                break;
            }
            if(ev.type==SDL_MOUSEMOTION && ev.motion.state & SDL_BUTTON_MMASK) {
                vec3 f = v_scale3(v_normalize(cam_dir), -1);
                vec3 r = v_cross(f, (vec3){0, 1, 0});
                vec3 u = v_cross(r, f);
                cam_center = v_add3(cam_center, v_add3(v_scale3(r, ev.motion.xrel*0.01f), v_scale3(u, -ev.motion.yrel*0.01f)));
                cam = identity();
                m_translate(&cam, cam_center);
                cam = m_mult(lookAt(v_scale3(cam_dir, cam_dist), (vec3){0, 0, 0}, (vec3){0, 1, 0}), cam);
                // cam = orbitView(cam_dir, cam_dist, cam_center, (vec3){0,1,0});
            } else if(ev.type == SDL_MOUSEMOTION && ev.motion.state & SDL_BUTTON_LMASK) {
                matrix m = identity();
                m_rotate(&m, ev.motion.xrel*0.01f, (vec3){0,1,0});
                cam_dir = transform3x3(m, cam_dir);
                m = identity();
                m_rotate(&m, ev.motion.yrel*0.01f, v_cross((vec3){0, 1, 0}, cam_dir));
                cam_dir = transform3x3(m, cam_dir);

                cam = identity();
                m_translate(&cam, cam_center);
                cam = m_mult(lookAt(v_scale3(cam_dir, cam_dist), (vec3){0, 0, 0}, (vec3){0, 1, 0}), cam);
                // cam = lookAt(v_add3(cam_center, v_scale3(cam_dir, cam_dist)), cam_center, (vec3){0, 1, 0});
                // cam = orbitView(cam_dir, cam_dist, cam_center, (vec3){0,1,0});
            }
            if(ev.type==SDL_MOUSEWHEEL) {
                cam_dist -= cam_dist * 0.1f*ev.wheel.preciseY;
                cam = identity();
                m_translate(&cam, cam_center);
                cam = m_mult(lookAt(v_scale3(cam_dir, cam_dist), (vec3){0, 0, 0}, (vec3){0, 1, 0}), cam);
                // cam = lookAt(v_add3(cam_center, v_scale3(cam_dir, cam_dist)), cam_center, (vec3){0, 1, 0});
                // cam = orbitView(cam_dir, cam_dist, cam_center, (vec3){0,1,0});
            }
        }

        SDL_FillRect(surf, NULL, 0x000000);

        ZG_DISABLE_CULLING = 0;
        skybox_uni.v3[0] = v_add3(v_scale3(cam_center, -1), v_scale3(cam_dir, cam_dist));
        monkey_uni.v3[4] = v_add3(v_scale3(cam_center, -1), v_scale3(cam_dir, cam_dist));
        monkey_uni.s = &monkey_image;
        mvp_uni.m[0] = persp;
        mvp_uni.m[1] = cam;
        mvp_uni.m[2] = tf_monkey;
        monkey_uni.f[0] = 0.1;
        monkey_uni.f[1] = 0;
        monkey_uni.v3[2] = (vec3){0, 0.5, 1};
        draw_object(monkey, &vs_mvp, mvp_uni, &fs_monkey, monkey_uni);
        monkey_uni.s = 0;
        mvp_uni.m[2] = tf_plane;
        draw_object(plane, &vs_mvp, mvp_uni, &fs_monkey, monkey_uni);
        mvp_uni.m[2] = tf_cube2;
        draw_object(cube, &vs_mvp, mvp_uni, &fs_monkey, monkey_uni);

        float a = frame*2*3.14159265f/256.f;
        float c = cosf(a), s = sinf(a);
        matrix rotation = (matrix){
            (vec4){c, 0, -s, 0},
            (vec4){0, 1, 0, 0},
            (vec4){s, 0, c, 0},
            (vec4){0, 0, 0, 1}
        };
        m_translate(&rotation, (vec3){-3, -6, 2});
        mvp_uni.m[2] = rotation;
        draw_object(cube, &vs_mvp, mvp_uni, &fs_monkey, monkey_uni);

        monkey_uni.f[0] = 0.8;
        monkey_uni.v3[2] = (vec3){1.0, 0.9, 0.8};
        mvp_uni.m[2] = tf_cube3;
        draw_object(cube, &vs_mvp, mvp_uni, &fs_monkey, monkey_uni);



        mvp_uni.m[2] = tf_monkey2;
        draw_object(monkey, &vs_mvp, mvp_uni, &fs_refract, skybox_uni);
        mvp_uni.m[2] = tf_pawn;
        draw_object(pawn, &vs_mvp, mvp_uni, &fs_refract, skybox_uni);
        
        tf_skybox = cam;
        tf_skybox.d = (vec4){0,0,0,1};
        mvp_uni.m[0] = m_mult(persp, tf_skybox);
        ZG_DISABLE_CULLING = 1;
        draw_object(cube, &vs_skybox, mvp_uni, &fs_skybox, skybox_uni);

        SDL_UpdateWindowSurface(wind);

        frame++;
        printf("Frame: %d, %f\n", (int)frame, cam_dist);
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(wind);
    SDL_Quit();

    return 0;
}