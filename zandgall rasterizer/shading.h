#pragma once
#include "vertice.h"

typedef struct sampler2D {
	unsigned char* data;
	int w, h;
} sampler2D;

typedef struct cubemap {
	// Right, left, top, bottom, front, back
	sampler2D sides[6]; 
} cubemap;

typedef struct uniforms {
	matrix* m;
	vec4* v4;
	vec3* v3;
	vec2* v2;
	float* f;
	sampler2D* s;
	cubemap* c;
} uniforms;

// VERTEX SHADERS

vertice vs_mvp(const vertice* input, const uniforms uni) {
	vertice out;
	out.vec4_n = 0;
	out.vec4_a = (vec4*)malloc(out.vec4_n*sizeof(vec4));
	out.vec3_n = 2;
	out.vec3_a = (vec3*)malloc(out.vec3_n*sizeof(vec3));
	out.vec2_n = 1;
	out.vec2_a = (vec2*)malloc(out.vec2_n*sizeof(vec2));

	out.pos = transform(uni.m[2], input->pos);
	out.vec3_a[0] = transform3x3(inverseTranspose3x3(uni.m + 2), input->vec3_a[0]);
	out.vec3_a[1] = (vec3){out.pos.x, out.pos.y, out.pos.z};
	out.pos = transform(uni.m[0], transform(uni.m[1], out.pos));
	out.vec2_a[0] = input->vec2_a[0];
	return out;
}

vertice vs_skybox(const vertice* input, const uniforms uni) {
	vertice out;
	out.vec4_n = 0;
	out.vec4_a = (vec4*)malloc(out.vec4_n*sizeof(vec4));
	out.vec3_n = 2;
	out.vec3_a = (vec3*)malloc(out.vec3_n*sizeof(vec3));
	out.vec2_n = 1;
	out.vec2_a = (vec2*)malloc(out.vec2_n*sizeof(vec2));

	out.pos = transform(uni.m[0], input->pos);
	out.pos.z = out.pos.w;
	out.vec3_a[0] = transform3x3(inverseTranspose3x3(uni.m), input->vec3_a[0]);
	out.vec3_a[1] = (vec3){input->pos.x, input->pos.y, input->pos.z};
	out.vec2_a[0] = input->vec2_a[0];
	return out;
}

// FRAGMENT SHADERS

float MAGENTA_CHECKER_TEXTURE_8x8[8 * 8 * 3] = {
    1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,
    0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,
    1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,
    0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,
    1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,
    0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,
    1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,
    0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,  0,0,0,  1,0,1,
};
float RY_CHECKER_TEXTURE_8x8[8 * 8 * 3] = {
    1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,
    1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,
    1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,
    1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,
    1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,
    1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,
    1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,
    1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,  1,1,0,  1,0,0,
};

float *CURR_TXTR = 0;
int CURR_TXTR_W = 1;
int CURR_TXTR_H = 1;

float *CURR_CUBEMAP[6];
int CURR_CUBEMAP_W[6], CURR_CUBEMAP_H[6];

vec4 texture2D(sampler2D* s, float x, float y) {
	if(s->data==0)
		return (vec4){0, 0, 0, 1};
	unsigned char* t;
	// if (s->sampleRule == CLAMP)
	t = s->data + ((int)(fmaxf(fminf(x, 1), 0) * s->w) + (int)(fmaxf(fminf(y, 1), 0) * s->h) * s->w) * 3;
	return (vec4){t[0]/255.f, t[1]/255.f, t[2]/255.f, 1};
}

vec4 textureCubemap(cubemap* s, float x, float y, float z) {
	// return texture2D(s->sides, u, v);
	float m = fmaxf(fmaxf(fabsf(x), fabsf(y)), fabsf(z));
	if(x/m==-1)
		// return texture2D(s->sides, u, v);
		return texture2D(s->sides, 0.5-z/m*0.5, 0.5+y/m*0.5);
	else if(x/m==1)
		// return texture2D(s->sides+1, u, v);
		return texture2D(s->sides+1, 0.5+z/m*0.5, 0.5+y/m*0.5);
	else if(y/m==-1)
		// return texture2D(s->sides+2, u, v);
		return texture2D(s->sides+2, 0.5+z/m*0.5, 0.5+x/m*0.5);
	else if(y/m==1)
		// return texture2D(s->sides+3, u, v);
		return texture2D(s->sides+3, 0.5+z/m*0.5, 0.5-x/m*0.5);
	else if(z/m==-1)
		// return texture2D(s->sides+4, u, v);
		return texture2D(s->sides+4, 0.5+x/m*0.5, 0.5+y/m*0.5);
	// else return texture2D(s->sides+5, u, v);
	else return texture2D(s->sides+5, 0.5-x/m*0.5, 0.5+y/m*0.5);
}

vec4 fs_red(const vertice* const in, const uniforms uni) {
	return (vec4){1, 0, 0, 1};
}

vec4 fs_depth(const vertice* const in, const uniforms uni) {
	return (vec4){in->pos.z, in->pos.z, in->pos.z, 1};
}

vec4 fs_pos(const vertice* const in, const uniforms uni) {
	return (vec4){in->pos.x, in->pos.y, in->pos.z, 1};
}

vec4 fs_norm(const vertice* const in, const uniforms uni) {
	return (vec4){in->vec3_a[0].x, in->vec3_a[0].y, in->vec3_a[0].z, 1};
}

vec4 fs_uv(const vertice* const in, const uniforms uni) {
	return (vec4){in->vec2_a[0].x, in->vec2_a[0].y, 1, 1};
}

vec4 fs_texture(const struct vertice* const in, const uniforms uni) {
	return texture2D(uni.s, in->vec2_a[0].x, in->vec2_a[0].y);
}

vec4 fs_monkey(const struct vertice* const in, const uniforms uni) {
	vec3 nnorm = v_normalize(in->vec3_a[0]);

	vec3 light_pos = uni.v3[0];
	vec3 ambient_color = uni.v3[1];
	vec3 diffuse_color = uni.v3[2];
	vec3 specular_color = uni.v3[3];
	vec3 cam_pos = uni.v3[4];
	
	vec3 light_dir = v_normalize((vec3){light_pos.x-in->vec3_a[1].x, light_pos.y-in->vec3_a[1].y, light_pos.z-in->vec3_a[1].z});
	vec3 viewDir = v_normalize(v_add3(in->vec3_a[1], v_scale3(cam_pos, -1)));
	vec3 reflection = v_reflect(viewDir, nnorm);
	vec4 reflect_sample = textureCubemap(uni.c, reflection.x, reflection.y, reflection.z);
	float sky_bright = sqrtf(reflect_sample.x*reflect_sample.x + reflect_sample.y * reflect_sample.y + reflect_sample.z * reflect_sample.z);
	float diff = fmaxf(v_dot(nnorm, light_dir) + sky_bright*0.2f, 0);
	vec3 diffuse, ambient;
	if (uni.s == 0) {
		diffuse = v_scale3(diffuse_color, diff);
		ambient = ambient_color;
	} else {
		vec4 s = texture2D(uni.s, in->vec2_a[0].x, in->vec2_a[0].y);
		diffuse = (vec3){diff*s.x, diff*s.y, diff*s.z};
		ambient = v_add3((vec3){0.1*s.x, 0.1*s.y, 0.1*s.z}, ambient_color);
	}

	vec3 spec_reflect = v_reflect(v_scale3(light_dir, -1), nnorm);
	float spec = powf(fmaxf(v_dot(v_scale3(viewDir, -1), spec_reflect), 0.0), 32);
	
	vec3 specular = v_scale3(specular_color, spec*0.5f);
	// vec3 specular = (vec3){0,0,0};

	vec4 base = (vec4){ambient.x + diffuse.x + specular.x, ambient.y + diffuse.y + specular.y, ambient.z + diffuse.z + specular.z, 1};
	return v_add(v_scale(base, 1-uni.f[0]), v_scale(reflect_sample, uni.f[0]));
}

vec4 fs_refract(const struct vertice* in, const uniforms uni) {
	vec3 nnorm = v_normalize(in->vec3_a[0]);
	vec3 cam_pos = uni.v3[0];
	vec3 viewDir = v_normalize(v_add3(in->vec3_a[1], v_scale3(cam_pos, -1)));
	// Air -> Glass IR = 0.658
	vec3 refraction = v_refract(viewDir, nnorm, 0.658);
	vec4 refract_sample = textureCubemap(uni.c, refraction.x, refraction.y, refraction.z);
	vec3 reflection = v_reflect(viewDir, nnorm);
	vec4 reflect_sample = textureCubemap(uni.c, reflection.x, reflection.y, reflection.z);

	vec3 d = v_cross(viewDir, nnorm);
	float reflection_amount = d.x*d.x+d.y*d.y+d.z*d.z;
	return v_add(v_scale(v_add(v_scale(reflect_sample, reflection_amount), v_scale(refract_sample, 1-reflection_amount)), 0.25*reflection_amount+0.75), (vec4){0.25*reflection_amount+0.25, 0.25*reflection_amount+0.25, 0.25*reflection_amount+0.25, 0.25*reflection_amount+0.25});
}

vec4 fs_skybox(const struct vertice* const in, const uniforms uni) {
	vec3 s = v_normalize(in->vec3_a[1]);
	return textureCubemap(uni.c, s.x, s.y, s.z);
}