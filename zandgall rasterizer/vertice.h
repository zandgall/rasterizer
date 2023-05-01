#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vec4 {
    float x, y, z, w;
} vec4;

typedef struct vec3 {
    float x, y, z;
} vec3;

typedef struct vec2 {
    float x, y;
} vec2;

typedef struct vertice {
    vec4 pos;
    vec4 *vec4_a;
    unsigned char vec4_n;
    vec3 *vec3_a;
    unsigned char vec3_n;
    vec2 *vec2_a;
    unsigned char vec2_n;
} vertice;

vec4 v_add(const vec4 a, const vec4 b) {
    return (vec4) { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}
vec3 v_add3(const vec3 a, const vec3 b) {
    return (vec3) { a.x + b.x, a.y + b.y, a.z + b.z };
}
vec2 v_add2(const vec2 a, const vec2 b) {
    return (vec2) { a.x + b.x, a.y + b.y };
}

vec4 v_mult(const vec4 a, const vec4 b) {
    return (vec4) { a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}
vec3 v_mult3(const vec3 a, const vec3 b) {
    return (vec3) { a.x * b.x, a.y * b.y, a.z * b.z };
}
vec2 v_mult2(const vec2 a, const vec2 b) {
    return (vec2) { a.x * b.x, a.y * b.y };
}

vec4 v_scale(const vec4 a, const float s) {
    return (vec4) { a.x * s, a.y * s, a.z * s, a.w * s };
}
vec3 v_scale3(const vec3 a, const float s) {
    return (vec3) { a.x * s, a.y * s, a.z * s };
}
vec2 v_scale2(const vec2 a, const float s) {
    return (vec2) { a.x * s, a.y * s };
}

float v_dot(const vec3 a, const vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 v_cross(const vec3 a, const vec3 b) {
    return (vec3){a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}

vec3 v_normalize(const vec3 a) {
    return v_scale3(a, 1.f/sqrtf(a.x*a.x + a.y*a.y + a.z*a.z));
}

vec3 v_reflect(const vec3 a, const vec3 n) {
    return v_add3(a, v_scale3(n, -2*v_dot(a, n))); // a - 2(a dot n)n
}

// https://registry.khronos.org/OpenGL-Refpages/gl4/html/refract.xhtml
vec3 v_refract(const vec3 a, const vec3 n, const float eta) {
    float k = 1.f - eta * eta * (1.f - v_dot(n, a)*v_dot(n, a));
    if(k < 0)
        return (vec3){0,0,0};
    else return v_add3(v_scale3(a, eta), v_scale3(n, eta * v_dot(n, a)+sqrtf(k)));
}

typedef struct matrix {
    struct vec4 a, b, c, d;
} matrix;

struct matrix identity() {
    return (struct matrix) { (vec4) { 1, 0, 0, 0 }, (vec4) { 0, 1, 0, 0 }, (vec4) { 0, 0, 1, 0 }, (vec4) { 0, 0, 0, 1 } };
};

vec3 transform3x3(const matrix a, const vec3 b) {
    //a.a*b.x + a.b*b.y + a.c*b.z + a.d*b.w
    vec4 out4 = v_add(v_add(v_scale(a.a, b.x), v_scale(a.b, b.y)), v_scale(a.c, b.z));
    vec3 out = (vec3){ out4.x, out4.y, out4.z };
    return out;
}

matrix inverseTranspose3x3(const matrix* const a) {
    matrix out = identity();
    float determinant = 
        + a->a.x * (a->b.y * a->c.z - a->b.z * a->c.y)
        - a->a.y * (a->b.x * a->c.z - a->b.z * a->c.x)
        + a->a.z * (a->b.x * a->c.y - a->b.y * a->c.x);

    out.a.x = + (a->b.y * a->c.z - a->c.y * a->b.z) / determinant;
    out.a.y = - (a->b.x * a->c.z - a->c.x * a->b.z) / determinant;
    out.a.z = + (a->b.x * a->c.y - a->c.x * a->b.y) / determinant;
    out.b.x = - (a->a.y * a->c.z - a->c.y * a->a.z) / determinant;
    out.b.y = + (a->a.x * a->c.z - a->c.x * a->a.z) / determinant;
    out.b.z = - (a->a.x * a->c.y - a->c.x * a->a.y) / determinant;
    out.c.x = + (a->a.y * a->b.z - a->b.y * a->a.z) / determinant;
    out.c.y = - (a->a.x * a->b.z - a->b.x * a->a.z) / determinant;
    out.c.z = + (a->a.x * a->b.y - a->b.x * a->a.y) / determinant;

    return out;
}

// vertice transform(const matrix a, const vertice b) {
//     //a.a*b.x + a.b*b.y + a.c*b.z + a.d*b.w
//     vertice out;
//     out.pos = v_add(v_add(v_add(v_scale(a.a, b.pos.x), v_scale(a.b, b.pos.y)), v_scale(a.c, b.pos.z)), v_scale(a.d, b.pos.w));
//     out.uv = b.uv;
//     out.norm = transform3x3(inverseTranspose3x3(&a), b.norm);
//     return out;
// }

vec4 transform(const matrix a, const vec4 b) {
    //a.a*b.x + a.b*b.y + a.c*b.z + a.d*b.w
    return v_add(v_add(v_add(v_scale(a.a, b.x), v_scale(a.b, b.y)), v_scale(a.c, b.z)), v_scale(a.d, b.w));
}

void m_translate(struct matrix* m, const vec3 translation) {
    m->d.x += translation.x;
    m->d.y += translation.y;
    m->d.z += translation.z;
}

void m_scale(matrix* m, const vec3 scalar) {
    m->a = v_scale(m->a, scalar.x);
    m->b = v_scale(m->b, scalar.y);
    m->c = v_scale(m->c, scalar.z);
}

// Translated from https://github.com/g-truc/glm/blob/master/glm/ext/matrix_transform.inl
void m_rotate(matrix* m, const float angle, const vec3 axis) {
    const float c = cos(angle);
    const float s = sin(angle);
    struct vec3 temp = v_scale3(axis, 1 - c);
    struct matrix r;
    r.a.x = c + temp.x * axis.x;
    r.b.x = temp.x * axis.y + s * axis.z;
    r.c.x = temp.x * axis.z - s * axis.y;

    r.a.y = temp.y * axis.x - s * axis.z;
    r.b.y = c + temp.y * axis.y;
    r.c.y = temp.y * axis.z + s * axis.x;

    r.a.z = temp.z * axis.x + s * axis.y;
    r.b.z = temp.z * axis.y - s * axis.x;
    r.c.z = c + temp.z * axis.z;

    struct matrix t = *m;
    m->a = v_add(v_add(v_scale(t.a, r.a.x), v_scale(t.b, r.a.y)), v_scale(t.c, r.a.z));
    m->b = v_add(v_add(v_scale(t.a, r.b.x), v_scale(t.b, r.b.y)), v_scale(t.c, r.b.z));
    m->c = v_add(v_add(v_scale(t.a, r.c.x), v_scale(t.b, r.c.y)), v_scale(t.c, r.c.z));
};

matrix m_mult(const matrix a, const matrix b) {
    matrix out = identity();
    out.a = v_add(v_scale(a.a, b.a.x), v_add(v_scale(a.b, b.a.y), v_add(v_scale(a.c, b.a.z), v_scale(a.d, b.a.w))));
    out.b = v_add(v_scale(a.a, b.b.x), v_add(v_scale(a.b, b.b.y), v_add(v_scale(a.c, b.b.z), v_scale(a.d, b.b.w))));
    out.c = v_add(v_scale(a.a, b.c.x), v_add(v_scale(a.b, b.c.y), v_add(v_scale(a.c, b.c.z), v_scale(a.d, b.c.w))));
    out.d = v_add(v_scale(a.a, b.d.x), v_add(v_scale(a.b, b.d.y), v_add(v_scale(a.c, b.d.z), v_scale(a.d, b.d.w))));
    return out;
}

matrix transpose(const matrix* const a) {
    matrix out = identity();
    out.a = (vec4){a->a.x, a->b.x, a->c.x, a->d.x};
    out.b = (vec4){a->a.y, a->b.y, a->c.y, a->d.y};
    out.c = (vec4){a->a.z, a->b.z, a->c.z, a->d.z};
    out.d = (vec4){a->a.w, a->b.w, a->c.w, a->d.w};
}

matrix perspective(float FOV, float aspect, float znear, float zfar) {
    const float tan_half_fov = tanf(FOV / 2.f);
    struct matrix out = identity();
    out.a.x = 1 / (aspect * tan_half_fov);
    out.b.y = 1 / tan_half_fov;
    out.c.z = zfar / (znear - zfar);
    out.c.w = -1;
    out.d.z = -(zfar * znear) / (zfar - znear);
    out.d.w = 0;
    return out;
}

matrix lookAt(const vec3 eye, const vec3 center, const vec3 up) {
    vec3 f = v_normalize(v_add3(center, v_scale3(eye, -1)));
    vec3 s = v_normalize(v_cross(f, up));
    vec3 u = v_cross(s,f);

    matrix out = identity();
    out.a.x = s.x;
    out.b.x = s.y;
    out.c.x = s.z;
    out.a.y = u.x;
    out.b.y = u.y;
    out.c.y = u.z;
    out.a.z =-f.x;
    out.b.z =-f.y;
    out.c.z =-f.z;
    out.d.x =center.x+v_dot(s, eye);
    out.d.y =center.y+v_dot(u, eye);
    out.d.z =center.z+v_dot(f, eye);
    return out;
}

matrix orbitView(const vec3 dir, const float dist, const vec3 center, const vec3 up) {
    vec3 f = v_normalize(v_scale3(dir, -1));
    vec3 s = v_normalize(v_cross(f, up));
    vec3 u = v_cross(s, f);
    matrix out = identity();
    out.a.x = s.x;
    out.b.x = s.y;
    out.c.x = s.z;
    out.a.y = u.x;
    out.b.y = u.y;
    out.c.y = u.z;
    out.a.z =-f.x;
    out.b.z =-f.y;
    out.c.z =-f.z;
    vec3 d = center;
    out.d.x = d.x;
    out.d.y = d.y;
    out.d.z = d.z;
    return out;
}