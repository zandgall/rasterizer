import vertex as vt 
import math

class sampler2D:
    def __init__(self):
        self.data = []
        self.w = 0
        self.h = 0
    
class cubemap:
    def __init__(self):
        self.sides = [sampler2D(), sampler2D(), sampler2D(), sampler2D(), sampler2D(), sampler2D()]

class uniforms:
    def __init__(self):
        self.m = [] # matrices
        self.v4 = [] # vec4s
        self.v3 = [] # vec3s
        self.v2 = [] # vec2s
        self.f = [] # floats
        self.s = [] # sampler2Ds
        self.c = [] # cubemaps

def vs_mvp(input: vt.vertex, uni: uniforms):
    out = vt.vertex()
    out.pos = vt.transform(uni.m[2], input.pos)
    out.vec3s.append(vt.transform3x3(vt.inverseTranspose3x3(uni.m[2]), input.vec3s[0]))
    out.vec3s.append(vt.vec3(out.pos.x, out.pos.y, out.pos.z))
    out.pos = vt.transform(uni.m[0], vt.transform(uni.m[1], out.pos))
    out.vec2s.append(input.vec2s[0])
    return out

def vs_skybox(input: vt.vertex, uni: uniforms):
    out = vt.vertex()
    out.pos = vt.transform(uni.m[0], input.pos)
    out.pos.z = out.pos.w
    out.vec3s.append(vt.transform3x3(vt.inverseTranspose3x3(uni.m[0]), input.vec3s[0]))
    out.vec3s.append(vt.vec3(input.pos.x, input.pos.y, input.pos.z))
    out.vec2s.append(input.vec2s[0])
    return out

# FRAGMENT SHADERS

def texture2D(s: sampler2D, x: float, y: float):
    # i = (int(max(min(x,1), 0) * (s.w-1)) + int(max(min(y,1), 0)*(s.h-1))*s.w)*3
    xi = int(max(min(x,1),0)*(s.w-1))
    yi = int(max(min(y,1),0)*(s.h-1))
    return vt.vec4(s.data[xi, yi][0]/255, s.data[xi, yi][1]/255, s.data[xi, yi][2]/255, 1)

def textureCubemap(s: cubemap, x: float, y: float, z: float):
    m = max(max(abs(x), abs(y)), abs(z))

    if x/m == -1:
       return texture2D(s.sides[0], 0.5-z/m*0.5, 0.5+y/m*0.5)
    elif x/m == 1:
        return texture2D(s.sides[1], 0.5+z/m*0.5, 0.5+y/m*0.5)
    elif y/m == -1:
        return texture2D(s.sides[2], 0.5+z/m*0.5, 0.5+x/m*0.5)
    elif y/m == 1:
        return texture2D(s.sides[3], 0.5+z/m*0.5, 0.5-x/m*0.5)
    elif z/m == -1:
        return texture2D(s.sides[4], 0.5+x/m*0.5, 0.5+y/m*0.5)
    else:
        return texture2D(s.sides[5], 0.5-x/m*0.5, 0.5+y/m*0.5)

def fs_red(input: vt.vertex, uni: uniforms):
    return vt.vec4(1,0,0,1)

def fs_depth(input: vt.vertex, uni: uniforms):
    return vt.vec4(input.pos.z, input.pos.z, input.pos.z, 1)

def fs_pos(input: vt.vertex, uni: uniforms):
    return vt.vec4(input.pos.x, input.pos.y, input.pos.z, 1)

def fs_norm(input: vt.vertex, uni: uniforms):
    return vt.vec4(input.vec3s[0].x, input.vec3s[0].y, input.vec3s[0].z, 1)

def fs_uv(input: vt.vertex, uni: uniforms):
    return vt.vec4(input.vec2s[0].x, input.vec2s[0].y, 1, 1)

def fs_texture(input: vt.vertex, uni: uniforms):
    return texture2D(uni.s[0], input.vec2s[0].x, input.vec2s[0].y)

def fs_monkey(input: vt.vertex, uni: uniforms):
    nnorm = vt.v3normalize(input.vec3s[0])
    light_pos = uni.v3[0]
    ambient_color = uni.v3[1]
    diffuse_color = uni.v3[2]
    specular_color = uni.v3[3]
    cam_pos = uni.v3[4]

    light_dir = vt.v3normalize(vt.vec3(light_pos.x - input.vec3s[1].x, light_pos.y - input.vec3s[1].y, light_pos.z - input.vec3s[1].z))
    view_dir = vt.v3normalize(vt.v3add(input.vec3s[1], vt.v3scale(cam_pos, -1)))
    reflection = vt.v3reflect(view_dir, nnorm)
    reflect_sample = textureCubemap(uni.c[0], reflection.x, reflection.y, reflection.z)
    sky_bright = math.sqrt(reflect_sample.x * reflect_sample.x + reflect_sample.y * reflect_sample.y + reflect_sample.z * reflect_sample.z)
    diff = max(vt.v3dot(nnorm, light_dir) + sky_bright*0.2, 0)
    diffuse = vt.vec3(0,0,0)
    ambient = vt.vec3(0,0,0)
    if uni.s[0].w==0 or uni.s[0].h == 0:
        diffuse = vt.v3scale(diffuse_color, diff)
        ambient = ambient_color
    else:
        s = texture2D(uni.s[0], input.vec2s[0].x, input.vec2s[0].y)
        diffuse = vt.vec3(diff*s.x, diff*s.y, diff*s.z)
        ambient = vt.v3add(vt.vec3(0.1*s.x, 0.1*s.y, 0.1*s.z), ambient_color)
    
    spec_reflect = vt.v3reflect(vt.v3scale(light_dir, -1), nnorm)
    spec = pow(max(vt.v3dot(vt.v3scale(view_dir, -1), spec_reflect), 0.0), 32)

    specular = vt.v3scale(specular_color, spec*0.5)

    base = vt.vec4(ambient.x + diffuse.x + specular.x, ambient.y + diffuse.y + specular.y, ambient.z + diffuse.z + specular.z, 1)
    return vt.v4add(vt.v4scale(base, 1-uni.f[0]), vt.v4scale(reflect_sample, uni.f[0]))

def fs_refract(input: vt.vertex, uni: uniforms):
    nnorm = vt.v3normalize(input.vec3s[0])
    cam_pos = uni.v3[0]
    view_dir = vt.v3normalize(vt.v3add(input.vec3s[1], vt.v3scale(cam_pos, -1)))

    # Air -> Glass IR = 0.658
    refraction = vt.v3refract(view_dir, nnorm, 0.658)
    refract_sample = textureCubemap(uni.c[0], refraction.x, refraction.y, refraction.z)
    reflection = vt.v3reflect(view_dir, nnorm)
    reflect_sample = textureCubemap(uni.c[0], reflection.x, reflection.y, reflection.z)

    d = vt.v3cross(view_dir, nnorm)
    reflection_amount = d.x * d.x + d.y * d.y + d.z * d.z

    return vt.v4add(vt.v4scale(vt.v4add(vt.v4scale(reflect_sample, reflection_amount), vt.v4scale(refract_sample, 1-reflection_amount)), 0.25*reflection_amount+0.75), vt.vec4(0.25*reflection_amount+0.25, 0.25*reflection_amount+0.25, 0.25*reflection_amount+0.25, 0.25*reflection_amount+0.25))

def fs_skybox(input: vt.vertex, uni: uniforms):
    return textureCubemap(uni.c[0], input.vec3s[1].x, input.vec3s[1].y, input.vec3s[1].z)