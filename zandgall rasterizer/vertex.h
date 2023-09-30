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

typedef struct vertex {
    vec4 pos;
    vec4 *vec4_a;
    unsigned char vec4_n;
    vec3 *vec3_a;
    unsigned char vec3_n;
    vec2 *vec2_a;
    unsigned char vec2_n;
} vertex;

// Basic vector operations
vec4 v4add(const vec4 a, const vec4 b) {
    return (vec4) { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}
vec3 v3add(const vec3 a, const vec3 b) {
    return (vec3) { a.x + b.x, a.y + b.y, a.z + b.z };
}
vec2 v2add(const vec2 a, const vec2 b) {
    return (vec2) { a.x + b.x, a.y + b.y };
}

vec4 v4scale(const vec4 a, const float s) {
    return (vec4) { a.x * s, a.y * s, a.z * s, a.w * s };
}
vec3 v3scale(const vec3 a, const float s) {
    return (vec3) { a.x * s, a.y * s, a.z * s };
}
vec2 v2scale(const vec2 a, const float s) {
    return (vec2) { a.x * s, a.y * s };
}

// Vector special operations

float v3dot(const vec3 a, const vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 v3cross(const vec3 a, const vec3 b) {
    return (vec3){a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}

vec3 v3normalize(const vec3 a) {
    return v3scale(a, 1.f/sqrtf(a.x*a.x + a.y*a.y + a.z*a.z));
}

vec3 v3reflect(const vec3 a, const vec3 n) {
    return v3add(a, v3scale(n, -2*v3dot(a, n))); // a - 2(a dot n)n
}

// https://registry.khronos.org/OpenGL-Refpages/gl4/html/refract.xhtml
vec3 v3refract(const vec3 a, const vec3 n, const float eta) {
    float k = 1.f - eta * eta * (1.f - v3dot(n, a)*v3dot(n, a));
    if(k < 0)
        return (vec3){0,0,0};
    else return v3add(v3scale(a, eta), v3scale(n, eta * v3dot(n, a)+sqrtf(k)));
}

// Matrix section

typedef struct matrix {
    struct vec4 a, b, c, d;
} matrix;

struct matrix identity() {
    return (struct matrix) { (vec4) { 1, 0, 0, 0 }, (vec4) { 0, 1, 0, 0 }, (vec4) { 0, 0, 1, 0 }, (vec4) { 0, 0, 0, 1 } };
};

vec3 transform3x3(const matrix a, const vec3 b) {
    vec4 out4 = v4add(v4add(v4scale(a.a, b.x), v4scale(a.b, b.y)), v4scale(a.c, b.z));
    vec3 out = (vec3){ out4.x, out4.y, out4.z };
    return out;
}

// Used for normals correcting when shading
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

vec4 transform(const matrix a, const vec4 b) {
    return v4add(v4add(v4add(v4scale(a.a, b.x), v4scale(a.b, b.y)), v4scale(a.c, b.z)), v4scale(a.d, b.w));
}

void m_translate(struct matrix* m, const vec3 translation) {
    m->d.x += translation.x;
    m->d.y += translation.y;
    m->d.z += translation.z;
}

void m_scale(matrix* m, const vec3 scalar) {
    m->a = v4scale(m->a, scalar.x);
    m->b = v4scale(m->b, scalar.y);
    m->c = v4scale(m->c, scalar.z);
}

// Translated from https://github.com/g-truc/glm/blob/master/glm/ext/matrix_transform.inl
void m_rotate(matrix* m, const float angle, const vec3 axis) {
    const float c = cos(angle);
    const float s = sin(angle);
    struct vec3 temp = v3scale(axis, 1 - c);
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
    m->a = v4add(v4add(v4scale(t.a, r.a.x), v4scale(t.b, r.a.y)), v4scale(t.c, r.a.z));
    m->b = v4add(v4add(v4scale(t.a, r.b.x), v4scale(t.b, r.b.y)), v4scale(t.c, r.b.z));
    m->c = v4add(v4add(v4scale(t.a, r.c.x), v4scale(t.b, r.c.y)), v4scale(t.c, r.c.z));
};

matrix m_mult(const matrix a, const matrix b) {
    matrix out = identity();
    out.a = transform(a, b.a);
    out.b = transform(a, b.b);
    out.c = transform(a, b.c);
    out.d = transform(a, b.d);
    return out;
}

matrix transpose(const matrix* const a) {
    matrix out = identity();
    out.a = (vec4){a->a.x, a->b.x, a->c.x, a->d.x};
    out.b = (vec4){a->a.y, a->b.y, a->c.y, a->d.y};
    out.c = (vec4){a->a.z, a->b.z, a->c.z, a->d.z};
    out.d = (vec4){a->a.w, a->b.w, a->c.w, a->d.w};
    return out;
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

matrix camera(const vec3 pos, const vec3 forward, const vec3 up) { // "up" will most certainly be <0, 1, 0>
    vec3 f = v3normalize(v3scale(forward, -1));
    vec3 s = v3normalize(v3cross(up, f));
    vec3 u = v3cross(f, s);
    matrix out = identity();
    
    out.a.x = s.x;
    out.b.x = s.y;
    out.c.x = s.z;
    out.a.y = u.x;
    out.b.y = u.y;
    out.c.y = u.z;
    out.a.z = f.x;
    out.b.z = f.y;
    out.c.z = f.z;
    
    out.d.x =-v3dot(s, pos);
    out.d.y =-v3dot(u, pos);
    out.d.z =-v3dot(f, pos);
    
    return out;
}