import math

import shading
import vertex as vt
import constants
from typing import Callable

def shade_triangle(args: list, fragment_shader: Callable[[vt.vertex, shading.uniforms], vt.vec4], f_uni: shading.uniforms, tri_draw_func: Callable[[int, int, float, vt.vec4], None]) -> None:
    # Creating variables that will represent the "top", "middle", and "bottom" vertices of the triangle
    
    t = vt.vertex()
    m = vt.vertex()
    b = vt.vertex()

    # calculate screenspace y-position of each argument, in order to compare them
    a0y = args[0].pos.y / args[0].pos.w
    a1y = args[1].pos.y / args[1].pos.w
    a2y = args[2].pos.y / args[2].pos.w

    # find top point
    if a0y <= a1y and a0y <= a2y:
        t = args[0]
        
        m = args[1]
        b = args[2]
    elif a1y <= a2y and a1y <= a0y:
        t = args[1]
        
        m = args[2]
        b = args[0]
    else:
        t = args[2]
        
        m = args[0]
        b = args[1]
        
    # if middle and bottom aren't set correctly, swap them
    if m.pos.y / m.pos.w > b.pos.y / b.pos.w:
        _ = b
        b = m
        m = _
    
    # We now have the top, middle, and bottom points.
    # We will now create new vertices in to represent the screen position.
    # We only need 6 values, the on-screen (x,y) positions of each of the 3 points

    st_x = math.floor(constants.WIDTH * 0.5 * (t.pos.x/t.pos.w + 1))
    if st_x <= -constants.LARGE or st_x >= constants.LARGE:
        return
    st_y = math.floor(constants.HEIGHT * 0.5 * (t.pos.y/t.pos.w + 1))
    if st_y <= -constants.LARGE or st_y >= constants.LARGE:
        return
    
    sm_x = math.floor(constants.WIDTH * 0.5 * (m.pos.x/m.pos.w + 1))
    if sm_x <= -constants.LARGE or sm_x >= constants.LARGE:
        return
    sm_y = math.floor(constants.HEIGHT * 0.5 * (m.pos.y/m.pos.w + 1))
    if sm_y <= -constants.LARGE or sm_y >= constants.LARGE:
        return
    
    sb_x = math.floor(constants.WIDTH * 0.5 * (b.pos.x/b.pos.w + 1))
    if sb_x <= -constants.LARGE or sb_x >= constants.LARGE:
        return
    sb_y = math.floor(constants.HEIGHT * 0.5 * (b.pos.y/b.pos.w + 1))
    if sb_y <= -constants.LARGE or sb_y >= constants.LARGE:
        return
    
    # We use barycentric coordinates to aide in shading our triangles.
    # Barycentric calculations require "/ area of full triangle"
    # So we will compute 1 over the area of the triangle
    
    if ((sb_x - st_x) * (sm_y - st_y) - (sb_y - st_y) * (sm_x - st_x)) == 0:
        return
    inv_area = 1 / ((sb_x - st_x) * (sm_y - st_y) - (sb_y - st_y) * (sm_x - st_x))
    if inv_area == 0:
        return
    
    # Now, we shall calculate the slopes of each line
    # tb being top->bottom slope, tm = top->middle slope, mb = middle->bottom slope
    #
    # KEEP NOTE:
    # These slopes are X / Y so they are technically "inverse slopes", but for every y+=1, we will increase x values by these slopes
    # They are the change in x, over the change in y
    
    if sb_y - st_y == 0:
        tb = math.inf
    else:
        tb = (sb_x - st_x) / (sb_y - st_y)
    if sm_y - st_y == 0:
        tm = math.inf
    else:
        tm = (sm_x - st_x) / (sm_y - st_y)
    if sb_y - sm_y == 0:
        mb = math.inf
    else:
        mb = (sb_x - sm_x) / (sb_y - sm_y)
    
    # During the rasterization, we will have one point that travels from the top to the bottom, and one that travels from the top to the middle
    # We will call them ants, and they only need to be represented by their x-position
    # As we scan down from y=st_y to y=sm_y, the "straight_ant" will be updated by the top->bottom slope
    # and the "switch_ant" will be updated by the top->middle slope
    # Once we hit y=sm_y, the straight_ant will continue to be updated by top->bottom, but
    # switch_ant will be updated by middle->bottom slope
    
    straight_ant = st_x
    switch_ant = st_x
        
    # If the top of the triangle is flat, (i.e. the top->middle slope is +- infinity)
    # then we need to skip directly to the middle->bottom half of the triangle.
    # In this instance, switch_ant needs to have the x-position of the middle point at the beginning

    if math.isinf(tm):
        switch_ant = sm_x
        
    current_vertice = vt.vertex()
    current_vertice.vec2s = t.vec2s[:]
    current_vertice.vec3s = t.vec3s[:]
    current_vertice.vec4s = t.vec4s[:]
    
    # The y-loop. Loop from y = st_y, to sm_y. Along the way, increment straight and switch ant by their respective slopes
    for y in range(st_y, sm_y):
        if y >= 0 and y < constants.HEIGHT:
            # The x-loop, loop from the minimum x to either straight_ant or switch_ant (continue until x is smaller than neither of them)
            for x in range(int(min(straight_ant, switch_ant)), math.ceil(max(straight_ant, switch_ant))):
                if x >= 0 and x < constants.WIDTH:
                    # Calculate UVW (barycentric) coordinates.
                    u = ((sb_x - x) * (sm_y - y) - (sb_y - y) * (sm_x - x)) * inv_area
                    v = ((sb_x - st_x) * (y - st_y) - (sb_y - st_y) * (x - st_x)) * inv_area
                    w = ((x - st_x) * (sm_y - st_y) - (y - st_y) * (sm_x - st_x)) * inv_area

                    # Calculate current point's distance from the "camera"
                    d = 1.0 / (u / t.pos.w + v / m.pos.w + w / b.pos.w)

                    # Get a physical representation of the on-screen point, interpolating vertex attributes for shading
                    current_vertice.pos = vt.v4scale(vt.v4add(vt.v4add(vt.v4scale(t.pos, u / t.pos.w), vt.v4scale(m.pos, v / m.pos.w)), vt.v4scale(b.pos, w / b.pos.w)), d)
                    
                    for i in range(len(t.vec2s)):
                        current_vertice.vec2s[i] = vt.v2scale(vt.v2add(vt.v2add(vt.v2scale(t.vec2s[i], u / t.pos.w), vt.v2scale(m.vec2s[i], v / m.pos.w)), vt.v2scale(b.vec2s[i], w / b.pos.w)), d)

                    for i in range(len(t.vec3s)):
                        current_vertice.vec3s[i] = vt.v3scale(vt.v3add(vt.v3add(vt.v3scale(t.vec3s[i], u / t.pos.w), vt.v3scale(m.vec3s[i], v / m.pos.w)), vt.v3scale(b.vec3s[i], w / b.pos.w)), d)
                    
                    for i in range(len(t.vec4s)):
                        current_vertice.vec4s[i] = vt.v4scale(vt.v4add(vt.v4add(vt.v4scale(t.vec4s[i], u / t.pos.w), vt.v4scale(m.vec4s[i], v / m.pos.w)), vt.v4scale(b.vec4s[i], w / b.pos.w)), d)

                    # Call the given shade function with the interpolated vertex attributes, x and y screen position, and draw function
                    tri_draw_func(x, y, current_vertice.pos.z / current_vertice.pos.w, fragment_shader(current_vertice, f_uni))
                            
        straight_ant+=tb
        switch_ant+=tm
        
    for y in range(sm_y, sb_y):
        if y >= 0 and y < constants.HEIGHT:
            for x in range(int(min(straight_ant, switch_ant)), math.ceil(max(straight_ant, switch_ant))):
                if x >= 0 and x < constants.WIDTH:
                    # Calculate UVW (barycentric) coordinates.
                    u = ((sb_x - x) * (sm_y - y) - (sb_y - y) * (sm_x - x)) * inv_area
                    v = ((sb_x - st_x) * (y - st_y) - (sb_y - st_y) * (x - st_x)) * inv_area
                    w = ((x - st_x) * (sm_y - st_y) - (y - st_y) * (sm_x - st_x)) * inv_area

                    # Calculate current point's distance from the "camera"
                    d = 1.0 / (u / t.pos.w + v / m.pos.w + w / b.pos.w)

                    # Get a physical representation of the on-screen point, interpolating vertex attributes for shading
                    current_vertice.pos = vt.v4scale(vt.v4add(vt.v4add(vt.v4scale(t.pos, u / t.pos.w), vt.v4scale(m.pos, v / m.pos.w)), vt.v4scale(b.pos, w / b.pos.w)), d)
                    
                    for i in range(len(t.vec2s)):
                        current_vertice.vec2s[i] = vt.v2scale(vt.v2add(vt.v2add(vt.v2scale(t.vec2s[i], u / t.pos.w), vt.v2scale(m.vec2s[i], v / m.pos.w)), vt.v2scale(b.vec2s[i], w / b.pos.w)), d)

                    for i in range(len(t.vec3s)):
                        current_vertice.vec3s[i] = vt.v3scale(vt.v3add(vt.v3add(vt.v3scale(t.vec3s[i], u / t.pos.w), vt.v3scale(m.vec3s[i], v / m.pos.w)), vt.v3scale(b.vec3s[i], w / b.pos.w)), d)
                    
                    for i in range(len(t.vec4s)):
                        current_vertice.vec4s[i] = vt.v4scale(vt.v4add(vt.v4add(vt.v4scale(t.vec4s[i], u / t.pos.w), vt.v4scale(m.vec4s[i], v / m.pos.w)), vt.v4scale(b.vec4s[i], w / b.pos.w)), d)

                    # Call the given shade function with the interpolated vertex attributes, x and y screen position, and draw function
                    tri_draw_func(x, y, current_vertice.pos.z / current_vertice.pos.w, fragment_shader(current_vertice, f_uni))
                            
        straight_ant+=tb
        switch_ant+=mb
