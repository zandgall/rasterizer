import triangle
import vertex as vt
import constants
THRESHOLD = 0.001

def shade_clip_plane_augment(a, b, c, a_coord, b_coord, c_coord, fs, f_uni, tri_draw_func):
    ratio_ac = a_coord / (a_coord - c_coord)
    ratio_bc = b_coord / (b_coord - c_coord)
    
    seg1 = vt.vertex()
    seg1.vec2s = a.vec2s[:]
    seg1.vec3s = a.vec3s[:]
    seg1.vec4s = a.vec4s[:]
    
    seg2 = vt.vertex()
    seg2.vec2s = a.vec2s[:]
    seg2.vec3s = a.vec3s[:]
    seg2.vec4s = a.vec4s[:]
    
    # Clip a->c
    seg1.pos = vt.v4add(vt.v4scale(a.pos, 1-ratio_ac), vt.v4scale(c.pos, ratio_ac))
    for i in range(len(seg1.vec2s)):
        seg1.vec2s[i] = vt.v2add(vt.v2scale(a.vec2s[i], 1-ratio_ac), vt.v2scale(c.vec2s[i], ratio_ac))
    for i in range(len(seg1.vec3s)):
        seg1.vec3s[i] = vt.v3add(vt.v3scale(a.vec3s[i], 1-ratio_ac), vt.v3scale(c.vec3s[i], ratio_ac))
    for i in range(len(seg1.vec4s)):
        seg1.vec4s[i] = vt.v4add(vt.v4scale(a.vec4s[i], 1-ratio_ac), vt.v4scale(c.vec4s[i], ratio_ac))
        
    # Clip b->c
    seg2.pos = vt.v4add(vt.v4scale(b.pos, 1-ratio_bc), vt.v4scale(c.pos, ratio_bc))
    for i in range(len(seg2.vec2s)):
        seg2.vec2s[i] = vt.v2add(vt.v2scale(b.vec2s[i], 1-ratio_bc), vt.v2scale(c.vec2s[i], ratio_bc))
    for i in range(len(seg2.vec3s)):
        seg2.vec3s[i] = vt.v3add(vt.v3scale(b.vec3s[i], 1-ratio_bc), vt.v3scale(c.vec3s[i], ratio_bc))
    for i in range(len(seg2.vec4s)):
        seg2.vec4s[i] = vt.v4add(vt.v4scale(b.vec4s[i], 1-ratio_bc), vt.v4scale(c.vec4s[i], ratio_bc))
    
    drawable = [seg1, seg2, c]
    shade_clip_tri(drawable, fs, f_uni, tri_draw_func)
    
    return True

def shade_clip_plane_create(a, b, c, a_coord, b_coord, c_coord, fs, f_uni, tri_draw_func):
    ratio_ab = b_coord / (b_coord - a_coord)
    ratio_ac = c_coord / (c_coord - a_coord)
    
    seg1 = vt.vertex()
    seg1.vec2s = a.vec2s[:]
    seg1.vec3s = a.vec3s[:]
    seg1.vec4s = a.vec4s[:]
    
    seg2 = vt.vertex()
    seg2.vec2s = a.vec2s[:]
    seg2.vec3s = a.vec3s[:]
    seg2.vec4s = a.vec4s[:]
    
    # Clip a->b    
    seg1.pos = vt.v4add(vt.v4scale(b.pos, 1-ratio_ab), vt.v4scale(a.pos, ratio_ab))
    for i in range(len(seg1.vec2s)):
        seg1.vec2s[i] = vt.v2add(vt.v2scale(b.vec2s[i], 1-ratio_ab), vt.v2scale(a.vec2s[i], ratio_ab))
    for i in range(len(seg1.vec3s)):
        seg1.vec3s[i] = vt.v3add(vt.v3scale(b.vec3s[i], 1-ratio_ab), vt.v3scale(a.vec3s[i], ratio_ab))
    for i in range(len(seg1.vec4s)):
        seg1.vec4s[i] = vt.v4add(vt.v4scale(b.vec4s[i], 1-ratio_ab), vt.v4scale(a.vec4s[i], ratio_ab))
        
    drawable = [seg1, b, c]
    shade_clip_tri(drawable, fs, f_uni, tri_draw_func)
        
    # Clip a->c
    seg2.pos = vt.v4add(vt.v4scale(c.pos, 1-ratio_ac), vt.v4scale(a.pos, ratio_ac))
    for i in range(len(seg2.vec2s)):
        seg2.vec2s[i] = vt.v2add(vt.v2scale(c.vec2s[i], 1-ratio_ac), vt.v2scale(a.vec2s[i], ratio_ac))
    for i in range(len(seg2.vec3s)):
        seg2.vec3s[i] = vt.v3add(vt.v3scale(c.vec3s[i], 1-ratio_ac), vt.v3scale(a.vec3s[i], ratio_ac))
    for i in range(len(seg2.vec4s)):
        seg2.vec4s[i] = vt.v4add(vt.v4scale(c.vec4s[i], 1-ratio_ac), vt.v4scale(a.vec4s[i], ratio_ac))
    
    drawable[1] = c
    drawable[2] = seg2
    shade_clip_tri(drawable, fs, f_uni, tri_draw_func)
    
    return True

def shade_clip_plane(a, b, c, a_coord, b_coord, c_coord, fs, f_uni, tri_draw_func):
    if a_coord < -THRESHOLD and b_coord < -THRESHOLD and c_coord < -THRESHOLD:
        return True # Reject triangle, all points are outside clipping plane
    if a_coord >= -THRESHOLD and b_coord >= -THRESHOLD and c_coord >= -THRESHOLD:
        return False # Draw as is, all points are inside clipping plane
    if a_coord < 0 and b_coord < 0 and c_coord >= 0: # Two points are outside, no new geometry is needed, just augment the given triangle
        return shade_clip_plane_augment(a, b, c, a_coord, b_coord, c_coord, fs, f_uni, tri_draw_func) # Done with this triangle
    if b_coord < 0 and c_coord < 0 and a_coord >= 0:
        return shade_clip_plane_augment(b, c, a, b_coord, c_coord, a_coord, fs, f_uni, tri_draw_func)
    if c_coord < 0 and a_coord < 0 and b_coord >= 0:
        return shade_clip_plane_augment(c, a, b, c_coord, a_coord, b_coord, fs, f_uni, tri_draw_func)

    if a_coord < 0 and b_coord >= 0 and c_coord >= 0: # One point is outside, requires new geometry to be constructed
        return shade_clip_plane_create(a, b, c, a_coord, b_coord, c_coord, fs, f_uni, tri_draw_func) # Done with this triangle
    if b_coord < 0 and c_coord >= 0 and a_coord >= 0:
        return shade_clip_plane_create(b, c, a, b_coord, c_coord, a_coord, fs, f_uni, tri_draw_func)
    if c_coord < 0 and a_coord >= 0 and b_coord >= 0:
        return shade_clip_plane_create(c, a, b, c_coord, a_coord, b_coord, fs, f_uni, tri_draw_func)
    return False
    

def shade_clip_tri(args, fs, f_uni, tri_draw_func):
    if shade_clip_plane(args[0], args[1], args[2], args[0].pos.w + args[0].pos.x, args[1].pos.w + args[1].pos.x, args[2].pos.w + args[2].pos.x, fs, f_uni, tri_draw_func):
        return # Left
    if shade_clip_plane(args[0], args[1], args[2], args[0].pos.w - args[0].pos.x, args[1].pos.w - args[1].pos.x, args[2].pos.w - args[2].pos.x, fs, f_uni, tri_draw_func):
        return # Right 
    if shade_clip_plane(args[0], args[1], args[2], args[0].pos.w + args[0].pos.y, args[1].pos.w + args[1].pos.y, args[2].pos.w + args[2].pos.y, fs, f_uni, tri_draw_func):
        return # Bottom
    if shade_clip_plane(args[0], args[1], args[2], args[0].pos.w - args[0].pos.y, args[1].pos.w - args[1].pos.y, args[2].pos.w - args[2].pos.y, fs, f_uni, tri_draw_func):
        return # Top
    if shade_clip_plane(args[0], args[1], args[2], args[0].pos.z, args[1].pos.z, args[2].pos.z, fs, f_uni, tri_draw_func):
        return # Near
    if shade_clip_plane(args[0], args[1], args[2], args[0].pos.w - args[0].pos.z, args[1].pos.w - args[1].pos.z, args[2].pos.w - args[2].pos.z, fs, f_uni, tri_draw_func):
        return # Far
    
    if not constants.ZG_DISABLE_CULLING:
        if (args[1].pos.x/args[1].pos.w - args[0].pos.x/args[0].pos.w)*(args[2].pos.y/args[2].pos.w - args[0].pos.y/args[0].pos.w) - (args[1].pos.y/args[1].pos.w - args[0].pos.y/args[0].pos.w)*(args[2].pos.x/args[2].pos.w - args[0].pos.x/args[0].pos.w) < 0:
            return
        
    triangle.shade_triangle(args, fs, f_uni, tri_draw_func)
    
def draw(args, vs, v_uni, fs, f_uni, tri_draw_func):
    a = vs(args[0], v_uni)
    b = vs(args[1], v_uni)
    c = vs(args[2], v_uni)
    
    trans = [ a, b, c ]
    shade_clip_tri(trans, fs, f_uni, tri_draw_func)
