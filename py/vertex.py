import math
import copy

class vec2:
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y
    def __str__(self):
        return "("+str(self.x)+", "+str(self.y)+")"

class vec3:
    def __init__(self, x: float, y:float, z:float):
        self.x = x
        self.y = y
        self.z = z
    def __str__(self):
        return "("+str(self.x)+", "+str(self.y)+", "+str(self.z)+")"

class vec4:
    def __init__(self, x:float, y:float, z:float, w:float):
        self.x = x
        self.y = y
        self.z = z
        self.w = w
    def __str__(self):
        return "("+str(self.x)+", "+str(self.y)+", "+str(self.z)+", "+str(self.w)+")"

class vertex:
    def __init__(self):
        self.pos = vec4(0, 0, 0, 1)
        self.vec4s = []
        self.vec3s = []
        self.vec2s = []

def v4add(a: vec4, b: vec4) -> vec4:
    return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w)

def v3add(a: vec3, b: vec3) -> vec3: 
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z)

def v2add(a: vec2, b: vec2) -> vec2:
    return vec2(a.x + b.x, a.y + b.y)

def v4scale(a: vec4, s: float) -> vec4:
    return vec4(a.x * s, a.y * s, a.z * s, a.w * s)

def v3scale(a: vec3, s: float) -> vec3:
    return vec3(a.x * s, a.y * s, a.z * s)

def v2scale(a: vec2, s: float) -> vec2:
    return vec2(a.x * s, a.y * s)

def v3dot(a: vec3, b: vec3) -> float:
    return a.x * b.x + a.y * b.y + a.z * b.z

def v3cross(a: vec3, b: vec3) -> vec3:
    return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x)

def v3normalize(a: vec3) -> vec3:
    if a.x == 0 and a.y == 0 and a.z == 0:
        return vec3(math.inf, math.inf, math.inf)
    return v3scale(a, 1.0/math.sqrt(a.x*a.x + a.y * a.y + a.z * a.z))

def v3reflect(a: vec3, n: vec3) -> vec3:
    return v3add(a, v3scale(n, -2*v3dot(a,n))) # a - 2(a dot n)n

# https://registry.khronos.org/OpenGL-Refpages/gl4/html/refract.xhtml
def v3refract(a: vec3, n: vec3, eta: float) -> vec3:
    k = 1.0 - eta * eta * (1.0 - v3dot(n, a)*v3dot(n, a))
    if k < 0:
        return vec3(0,0,0)
    return v3add(v3scale(a,eta), v3scale(n, eta * v3dot(n,a)+math.sqrt(k)))

# Matrix section

class matrix:
    def __init__(self, a: vec4, b: vec4, c: vec4, d: vec4):
        self.a = a
        self.b = b
        self.c = c
        self.d = d

    def __str__(self):
        return "[" + str(self.a) + ", " +str(self.b) + ", " +str(self.c) + ", " +str(self.d) + "]"

    def translate(self, translation: vec3):
        self.d.x += translation.x
        self.d.y += translation.y
        self.d.z += translation.z

    def scale(self, scalar: vec3):
        self.a = v4scale(self.a, scalar.x)
        self.b = v4scale(self.b, scalar.y)
        self.c = v4scale(self.c, scalar.z)

    # Translated from https://github.com/g-truc/glm/blob/master/glm/ext/matrix_transform.inl
    def rotate(self, angle: float, axis: vec3):
        c = math.cos(angle)
        s = math.sin(angle)

        temp = v3scale(axis, 1 - c)
        r = identity()
        r.a.x = c + temp.x * axis.x
        r.b.x = temp.x * axis.y + s * axis.z
        r.c.x = temp.x * axis.z - s * axis.y

        r.a.y = temp.y * axis.x - s * axis.z
        r.b.y = c + temp.y * axis.y
        r.c.y = temp.y * axis.z + s * axis.x

        r.a.z = temp.z * axis.x + s * axis.y
        r.b.z = temp.z * axis.y - s * axis.x
        r.c.z = c + temp.z * axis.z

        t = copy.copy(self)
        self.a = v4add(v4add(v4scale(t.a, r.a.x), v4scale(t.b, r.a.y)), v4scale(t.c, r.a.z))
        self.b = v4add(v4add(v4scale(t.a, r.b.x), v4scale(t.b, r.b.y)), v4scale(t.c, r.b.z))
        self.c = v4add(v4add(v4scale(t.a, r.c.x), v4scale(t.b, r.c.y)), v4scale(t.c, r.c.z))

def identity():
    return matrix(vec4(1,0,0,0), vec4(0,1,0,0), vec4(0,0,1,0), vec4(0,0,0,1))

def transform3x3(a: matrix, b: vec3):
    out4 = v4add(v4add(v4scale(a.a, b.x), v4scale(a.b, b.y)), v4scale(a.c, b.z))
    return vec3(out4.x, out4.y, out4.z)

def transform(a:matrix, b: vec4):
    return v4add(v4add(v4add(v4scale(a.a, b.x), v4scale(a.b, b.y)), v4scale(a.c, b.z)), v4scale(a.d, b.w))

def inverseTranspose3x3(a:matrix):
    out = identity()
    determinant = + a.a.x * (a.b.y * a.c.z - a.b.z * a.c.y) - a.a.y * (a.b.x * a.c.z - a.b.z * a.c.x) + a.a.z * (a.b.x * a.c.y - a.b.y * a.c.x)

    out.a.x = + (a.b.y * a.c.z - a.c.y * a.b.z) / determinant
    out.a.y = - (a.b.x * a.c.z - a.c.x * a.b.z) / determinant
    out.a.z = + (a.b.x * a.c.y - a.c.x * a.b.y) / determinant
    out.b.x = - (a.a.y * a.c.z - a.c.y * a.a.z) / determinant
    out.b.y = + (a.a.x * a.c.z - a.c.x * a.a.z) / determinant
    out.b.z = - (a.a.x * a.c.y - a.c.x * a.a.y) / determinant
    out.c.x = + (a.a.y * a.b.z - a.b.y * a.a.z) / determinant
    out.c.y = - (a.a.x * a.b.z - a.b.x * a.a.z) / determinant
    out.c.z = + (a.a.x * a.b.y - a.b.x * a.a.y) / determinant

    return out

def m_mult(a:matrix, b:matrix):
    out = identity()
    out.a = transform(a, b.a)
    out.b = transform(a, b.b)
    out.c = transform(a, b.c)
    out.d = transform(a, b.d)
    return out

def transpose(a:matrix):
    out = identity()
    out.a = vec4(a.a.x, a.b.x, a.c.x, a.d.x)
    out.b = vec4(a.a.y, a.b.y, a.c.y, a.d.y)
    out.c = vec4(a.a.z, a.b.z, a.c.z, a.d.z)
    out.d = vec4(a.a.w, a.b.w, a.c.w, a.d.w)
    return out

def perspective(FOV: float, aspect: float, znear: float, zfar: float):
    tan_half_fov = math.tan(FOV / 2.0)
    out = identity()
    out.a.x = 1 / (aspect * tan_half_fov)
    out.b.y = 1 / tan_half_fov
    out.c.z = zfar / (znear - zfar)
    out.c.w = -1
    out.d.z = -(zfar * znear) / (zfar - znear)
    out.d.w = 0
    return out

def camera(pos: vec3, forward: vec3, up: vec3): #"up" will most certainly be <0, 1, 0>
    f = v3normalize(v3scale(forward, -1))
    s = v3normalize(v3cross(up, f))
    u = v3cross(f, s)
    out = identity()
    
    out.a.x = s.x
    out.b.x = s.y
    out.c.x = s.z
    out.a.y = u.x
    out.b.y = u.y
    out.c.y = u.z
    out.a.z = f.x
    out.b.z = f.y
    out.c.z = f.z
    
    out.d.x =-v3dot(s, pos)
    out.d.y =-v3dot(u, pos)
    out.d.z =-v3dot(f, pos)
    
    return out
