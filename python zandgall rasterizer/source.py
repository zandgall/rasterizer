import object as obj
import shading as sh
import vertex as vt
import math
import copy

from sdl2 import *

import ctypes
from PIL import Image, ImageOps
import constants

frame_buff = [0] * constants.HEIGHT*constants.WIDTH
depth_buff = [0] * constants.HEIGHT*constants.WIDTH
frame = 1
surf = None

def draw_func(x, y, z, input):
    global surf, frame_buff, depth_buff, frame
    if y < 0 or y >= constants.HEIGHT or x < 0 or x >= constants.HEIGHT:
        return
    # If the current pixel (x,y) was drawn this frame, and is closer to the camera, don't draw over it
    if frame_buff[y*constants.WIDTH + x] == frame and depth_buff[y*constants.WIDTH + x] < z:
        return
    
    surf[(constants.HEIGHT-1-y) * constants.WIDTH + x] = (int(min(max(input.x, 0),1)*255) << 16) + (int(min(max(input.y, 0), 1)*255) << 8) + int(min(max(input.z, 0), 1)*255) + (255<<24)
    
    frame_buff[y*constants.WIDTH + x] = frame
    depth_buff[y*constants.WIDTH + x] = z

def main():
    global surf, frame_buff, depth_buff, frame
    
    SDL_Init(SDL_INIT_VIDEO)
    
    IMG = ImageOps.flip(Image.open("monkey.png"))
    monkey_image = sh.sampler2D()
    monkey_image.w = IMG.width
    monkey_image.h = IMG.height
    monkey_image.data = IMG.load()
    
    skybox = sh.cubemap()
    # In C we are loading the images vertically flipped, as that's how we do it in c
    IMG = ImageOps.flip(Image.open("skybox/back.jpg"))
    skybox.sides[0].w = IMG.width
    skybox.sides[0].h = IMG.height
    skybox.sides[0].data = IMG.load()
    IMG = ImageOps.flip(Image.open("skybox/front.jpg"))
    skybox.sides[1].w = IMG.width
    skybox.sides[1].h = IMG.height
    skybox.sides[1].data = IMG.load()
    IMG = ImageOps.flip(Image.open("skybox/bottom.jpg"))
    skybox.sides[2].w = IMG.width
    skybox.sides[2].h = IMG.height
    skybox.sides[2].data = IMG.load()
    IMG = ImageOps.flip(Image.open("skybox/top.jpg"))
    skybox.sides[3].w = IMG.width
    skybox.sides[3].h = IMG.height
    skybox.sides[3].data = IMG.load()
    IMG = ImageOps.flip(Image.open("skybox/left.jpg"))
    skybox.sides[4].w = IMG.width
    skybox.sides[4].h = IMG.height
    skybox.sides[4].data = IMG.load()
    IMG = ImageOps.flip(Image.open("skybox/right.jpg"))
    skybox.sides[5].w = IMG.width
    skybox.sides[5].h = IMG.height
    skybox.sides[5].data = IMG.load()
    
    monkey = obj.load_obj("monkey.obj")
    cube = obj.load_obj("cube.obj")
    plane = obj.load_obj("plane.obj")
    pawn = obj.load_obj("pawn.obj")
    
    persp = vt.perspective(3.14159265/2, constants.WIDTH / constants.HEIGHT, 0.1, 100.0)
    
    tf_monkey = vt.identity()
    tf_monkey.rotate(0.72, vt.vec3(0, 1, 0))
    tf_monkey.rotate(0.6, vt.vec3(1, 0, 0))
    tf_monkey.translate(vt.vec3(0, 0.5, 0))
    
    tf_monkey2 = vt.identity()
    tf_monkey2.rotate(2.72, vt.vec3(0, 1, 0))
    tf_monkey2.rotate(0.6, vt.vec3(1, 0, 0))
    tf_monkey2.translate(vt.vec3(-3, 0.5, -2))
    
    tf_plane = vt.identity()
    tf_plane.scale(vt.vec3(5, 1, 5))
    tf_plane.rotate(0.72, vt.vec3(0, 1, 0))
    tf_plane.translate(vt.vec3(0,0,0))
    
    tf_cube2 = vt.identity()
    tf_cube2.rotate(-1.22, vt.vec3(1, 0, 0))
    tf_cube2.rotate(0.72, vt.vec3(0, 1, 0))
    tf_cube2.translate(vt.vec3(-4, 4.5, 0))
    
    tf_cube3 = vt.identity()
    tf_cube3.rotate(-0.42, vt.vec3(0, 1, 0))
    tf_cube3.scale(vt.vec3(0.5, 0.5, 1.7))
    tf_cube3.translate(vt.vec3(3, 0.5, 2))
    
    tf_pawn = vt.identity()
    tf_pawn.translate(vt.vec3(3, 1, -6))
    
    tf_skybox = vt.identity()

    mvp_uni = sh.uniforms()
    mvp_uni.m.append(persp)
    mvp_uni.m.append(vt.identity())
    mvp_uni.m.append(vt.identity())
    
    skybox_uni = sh.uniforms()
    skybox_uni.v3.append(vt.vec3(0, 0, 0))
    skybox_uni.f.append(0.0)
    skybox_uni.c.append(skybox)
    
    monkey_uni = sh.uniforms()
    monkey_uni.v3.append(vt.vec3(-10000, 20000, -10000))
    monkey_uni.v3.append(vt.vec3(0, 0, 0.1))
    monkey_uni.v3.append(vt.vec3(0, 0.5, 1))
    monkey_uni.v3.append(vt.vec3(1, 1, 0.9))
    monkey_uni.v3.append(vt.vec3(0,0,0))
    monkey_uni.f.append(0.0)
    monkey_uni.s.append(monkey_image)
    monkey_uni.c.append(skybox)
    
    cam_center = vt.vec3(0,0,0)
    cam_dir = vt.v3normalize(vt.vec3(1,1,1))
    cam_dist = 5
    
    cam = vt.camera(vt.v3add(cam_center, vt.v3scale(cam_dir, cam_dist)), vt.v3scale(cam_dir, -1), vt.vec3(0, 1, 0))
    running = True
    
    
    window = SDL_CreateWindow(b"Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, constants.WIDTH, constants.HEIGHT, SDL_WINDOW_SHOWN)
    surface = SDL_GetWindowSurface(window)
    surf = ctypes.cast(surface[0].pixels, ctypes.POINTER(ctypes.c_uint32))
    
    event = SDL_Event()
    SDL_UpdateWindowSurface(window, surface)
    while running:
        while SDL_PollEvent(ctypes.byref(event))!=0:
            if event.type == SDL_QUIT:
                running = False
                break
            if event.type == SDL_MOUSEMOTION and event.motion.state & SDL_BUTTON_MMASK:
                f = vt.v3scale(vt.v3normalize(cam_dir), -1)
                r = vt.v3cross(f, vt.vec3(0, 1, 0))
                u = vt.v3cross(r, f)
                cam_center = vt.v3add(cam_center, vt.v3add(vt.v3scale(r, event.motion.xrel*0.01), vt.v3scale(u, -event.motion.yrel*0.01)))
                cam = vt.camera(vt.v3add(cam_center, vt.v3scale(cam_dir, cam_dist)), vt.v3scale(cam_dir, -1), vt.vec3(0, 1, 0))
            elif event.type == SDL_MOUSEMOTION and event.motion.state & SDL_BUTTON_LMASK:
                m = vt.identity()
                m.rotate(event.motion.xrel*0.01, vt.vec3(0,1,0))
                cam_dir = vt.transform3x3(m, cam_dir)
                m = vt.identity()
                m.rotate(event.motion.yrel*0.01, vt.v3cross(vt.vec3(0, 1, 0), cam_dir))
                cam_dir = vt.transform3x3(m, cam_dir)
                cam = vt.camera(vt.v3add(cam_center, vt.v3scale(cam_dir, cam_dist)), vt.v3scale(cam_dir, -1), vt.vec3(0, 1, 0))
            elif event.type==SDL_MOUSEWHEEL:
                cam_dist -= cam_dist * 0.1*event.wheel.preciseY
                cam = vt.camera(vt.v3add(cam_center, vt.v3scale(cam_dir, cam_dist)), vt.v3scale(cam_dir, -1), vt.vec3(0, 1, 0))
            
        SDL_FillRect(surface, None, 0)
        constants.ZG_DISABLE_CULLING = False
        skybox_uni.v3[0] = vt.v3add(cam_center, vt.v3scale(cam_dir, cam_dist))
        monkey_uni.v3[4] = vt.v3add(cam_center, vt.v3scale(cam_dir, cam_dist))
        monkey_uni.s[0] = copy.copy(monkey_image)
        mvp_uni.m[0] = persp
        mvp_uni.m[1] = cam
        mvp_uni.m[2] = tf_monkey
        monkey_uni.f[0] = 0.1
        monkey_uni.v3[2] = vt.vec3(0, 0.5, 1)
        obj.draw_object(monkey, sh.vs_mvp, mvp_uni, sh.fs_monkey, monkey_uni, draw_func)
        monkey_uni.s[0].w = 0
        monkey_uni.s[0].h = 0
        mvp_uni.m[2] = tf_plane
        obj.draw_object(plane, sh.vs_mvp, mvp_uni, sh.fs_monkey, monkey_uni, draw_func)
        mvp_uni.m[2] = tf_cube2
        obj.draw_object(cube, sh.vs_mvp, mvp_uni, sh.fs_monkey, monkey_uni, draw_func)

        a = frame*2*3.14159265/256
        c = math.cos(a)
        s = math.sin(a)
        rotation = vt.matrix(vt.vec4(c, 0, -s, 0), vt.vec4(0, 1, 0, 0), vt.vec4(s, 0, c, 0), vt.vec4(0, 0, 0, 1))
        rotation.translate(vt.vec3(-3, -6, 2))
        mvp_uni.m[2] = rotation
        obj.draw_object(cube, sh.vs_mvp, mvp_uni, sh.fs_monkey, monkey_uni, draw_func)

        monkey_uni.f[0] = 0.8
        monkey_uni.v3[2] = vt.vec3(1.0, 0.9, 0.8)
        mvp_uni.m[2] = tf_cube3
        obj.draw_object(cube, sh.vs_mvp, mvp_uni, sh.fs_monkey, monkey_uni, draw_func)



        mvp_uni.m[2] = tf_monkey2
        obj.draw_object(monkey, sh.vs_mvp, mvp_uni, sh.fs_refract, skybox_uni, draw_func)
        mvp_uni.m[2] = tf_pawn
        obj.draw_object(pawn, sh.vs_mvp, mvp_uni, sh.fs_refract, skybox_uni, draw_func)
        
        tf_skybox = copy.copy(cam)
        tf_skybox.d = vt.vec4(0,0,0,1)
        mvp_uni.m[0] = vt.m_mult(persp, tf_skybox)
        constants.ZG_DISABLE_CULLING = True
        obj.draw_object(cube, sh.vs_skybox, mvp_uni, sh.fs_skybox, skybox_uni, draw_func)

        SDL_UpdateWindowSurface(window, surface)

        frame+=1
        print(str.format("Frame: {frame}, {cam_dist}", frame=int(frame), cam_dist=cam_dist))
    
    SDL_FreeSurface(surface)
    SDL_DestroyWindow(window)
    SDL_Quit()
    

if __name__ == "__main__":
    main()