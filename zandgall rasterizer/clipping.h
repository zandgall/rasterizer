#pragma once
#include "triangle.h"
#define THRESHOLD 0.001 // Account for floating point errors

char ZG_DISABLE_CULLING = 0;

void shade_clip_tri(const struct vertice* const args, vec4 (*fs)(const struct vertice* const, const uniforms), const uniforms);

unsigned char shade_clip_plane_augment(const struct vertice* const a, const struct vertice* const b, const struct vertice* const c, float a_coord, float b_coord, float c_coord, vec4 (*fs)(const struct vertice* const, const uniforms), const uniforms f_uni) {
	float ratio_ac = a_coord / (a_coord - c_coord);
	float ratio_bc = b_coord / (b_coord - c_coord);
	struct vertice seg1;
	seg1.vec2_n = a->vec2_n;
	seg1.vec2_a = (vec2*)malloc(seg1.vec2_n*sizeof(vec2));
	seg1.vec3_n = a->vec3_n;
	seg1.vec3_a = (vec3*)malloc(seg1.vec3_n*sizeof(vec3));
	seg1.vec4_n = a->vec4_n;
	seg1.vec4_a = (vec4*)malloc(seg1.vec4_n*sizeof(vec4));
	struct vertice seg2;
	seg2.vec2_n = a->vec2_n;
	seg2.vec2_a = (vec2*)malloc(seg2.vec2_n*sizeof(vec2));
	seg2.vec3_n = a->vec3_n;
	seg2.vec3_a = (vec3*)malloc(seg2.vec3_n*sizeof(vec3));
	seg2.vec4_n = a->vec4_n;
	seg2.vec4_a = (vec4*)malloc(seg2.vec4_n*sizeof(vec4));
	
	// Clip a->c
	seg1.pos = v_add(v_scale(a->pos, 1-ratio_ac), v_scale(c->pos, ratio_ac));
	for (int i = 0; i < seg1.vec2_n; i++)
		seg1.vec2_a[i] = v_add2(v_scale2(a->vec2_a[i], 1-ratio_ac), v_scale2(c->vec2_a[i], ratio_ac));
	for (int i = 0; i < seg1.vec3_n; i++)
		seg1.vec3_a[i] = v_add3(v_scale3(a->vec3_a[i], 1-ratio_ac), v_scale3(c->vec3_a[i], ratio_ac));
	for (int i = 0; i < seg1.vec4_n; i++)
		seg1.vec4_a[i] = v_add(v_scale(a->vec4_a[i], 1-ratio_ac), v_scale(c->vec4_a[i], ratio_ac));
	
	// Clip b->c
	seg2.pos = v_add(v_scale(b->pos, 1-ratio_bc), v_scale(c->pos, ratio_bc));
	for (int i = 0; i < seg2.vec2_n; i++)
		seg2.vec2_a[i] = v_add2(v_scale2(b->vec2_a[i], 1-ratio_bc), v_scale2(c->vec2_a[i], ratio_bc));
	for (int i = 0; i < seg2.vec3_n; i++)
		seg2.vec3_a[i] = v_add3(v_scale3(b->vec3_a[i], 1-ratio_bc), v_scale3(c->vec3_a[i], ratio_bc));
	for (int i = 0; i < seg2.vec4_n; i++)
		seg2.vec4_a[i] = v_add(v_scale(b->vec4_a[i], 1-ratio_bc), v_scale(c->vec4_a[i], ratio_bc));
	
	struct vertice drawable[3] = { seg1, seg2, *c };
	shade_clip_tri(drawable, fs, f_uni);

	// Free used memory
	free(seg1.vec2_a);
	free(seg1.vec3_a);
	free(seg1.vec4_a);
	free(seg2.vec2_a);
	free(seg2.vec3_a);
	free(seg2.vec4_a);
	return 1;
}

unsigned char shade_clip_plane_create(const struct vertice* const a, const struct vertice* const b, const struct vertice* const c, float a_coord, float b_coord, float c_coord, vec4 (*fs)(const struct vertice* const, const uniforms), const uniforms f_uni) {
	float ratio_ab = b_coord / (b_coord - a_coord);
	float ratio_ac = c_coord / (c_coord - a_coord);

	vertice seg1;
	seg1.vec2_n = a->vec2_n;
	seg1.vec2_a = (vec2*)malloc(seg1.vec2_n*sizeof(vec2));
	seg1.vec3_n = a->vec3_n;
	seg1.vec3_a = (vec3*)malloc(seg1.vec3_n*sizeof(vec3));
	seg1.vec4_n = a->vec4_n;
	seg1.vec4_a = (vec4*)malloc(seg1.vec4_n*sizeof(vec4));

	vertice seg2;
	seg2.vec2_n = a->vec2_n;
	seg2.vec2_a = (vec2*)malloc(seg2.vec2_n*sizeof(vec2));
	seg2.vec3_n = a->vec3_n;
	seg2.vec3_a = (vec3*)malloc(seg2.vec3_n*sizeof(vec3));
	seg2.vec4_n = a->vec4_n;
	seg2.vec4_a = (vec4*)malloc(seg2.vec4_n*sizeof(vec4));

	// Clip a->b
	seg1.pos = v_add(v_scale(b->pos, 1-ratio_ab), v_scale(a->pos, ratio_ab));
	for (int i = 0; i < seg1.vec2_n; i++)
		seg1.vec2_a[i] = v_add2(v_scale2(b->vec2_a[i], 1-ratio_ab), v_scale2(a->vec2_a[i], ratio_ab));
	for (int i = 0; i < seg1.vec3_n; i++)
		seg1.vec3_a[i] = v_add3(v_scale3(b->vec3_a[i], 1-ratio_ab), v_scale3(a->vec3_a[i], ratio_ab));
	for (int i = 0; i < seg1.vec4_n; i++)
		seg1.vec4_a[i] = v_add(v_scale(b->vec4_a[i], 1-ratio_ab), v_scale(a->vec4_a[i], ratio_ab));

	struct vertice drawable[3] = { seg1, *b, *c };
	shade_clip_tri(drawable, fs, f_uni);

	// Clip a->c
	seg2.pos = v_add(v_scale(c->pos, 1-ratio_ac), v_scale(a->pos, ratio_ac));
	for (int i = 0; i < seg2.vec2_n; i++)
		seg2.vec2_a[i] = v_add2(v_scale2(c->vec2_a[i], 1-ratio_ac), v_scale2(a->vec2_a[i], ratio_ac));
	for (int i = 0; i < seg2.vec3_n; i++)
		seg2.vec3_a[i] = v_add3(v_scale3(c->vec3_a[i], 1-ratio_ac), v_scale3(a->vec3_a[i], ratio_ac));
	for (int i = 0; i < seg2.vec4_n; i++)
		seg2.vec4_a[i] = v_add(v_scale(c->vec4_a[i], 1-ratio_ac), v_scale(a->vec4_a[i], ratio_ac));
	
	drawable[1] = *c;
	drawable[2] = seg2;
	shade_clip_tri(drawable, fs, f_uni);

	// Free memory
	free(seg1.vec2_a);
	free(seg1.vec3_a);
	free(seg1.vec4_a);
	free(seg2.vec2_a);
	free(seg2.vec3_a);
	free(seg2.vec4_a);
	return 1;
}

unsigned char shade_clip_plane(const struct vertice* const a, const struct vertice* const b, const struct vertice* const c, float a_coord, float b_coord, float c_coord, vec4 (*fs)(const struct vertice* const, const uniforms), const uniforms f_uni) {
	if (a_coord < -THRESHOLD && b_coord < -THRESHOLD && c_coord < -THRESHOLD)
		return 1; // Reject triangle, all points are outside clipping plane
	if (a_coord >= -THRESHOLD && b_coord >= -THRESHOLD && c_coord >= -THRESHOLD)
		return 0; // Draw as is, all points are inside clipping plane
	if (a_coord < 0 && b_coord < 0 && c_coord >= 0) // Two points are outside, no new geometry is needed, just augment the given triangle
		return shade_clip_plane_augment(a, b, c, a_coord, b_coord, c_coord, fs, f_uni); // Done with this triangle
	if (b_coord < 0 && c_coord < 0 && a_coord >= 0)
		return shade_clip_plane_augment(b, c, a, b_coord, c_coord, a_coord, fs, f_uni);
	if (c_coord < 0 && a_coord < 0 && b_coord >= 0)
		return shade_clip_plane_augment(c, a, b, c_coord, a_coord, b_coord, fs, f_uni);

	if (a_coord < 0 && b_coord >= 0 && c_coord >= 0) // One point is outside, requires new geometry to be constructed
		return shade_clip_plane_create(a, b, c, a_coord, b_coord, c_coord, fs, f_uni); // Done with this triangle
	if (b_coord < 0 && c_coord >= 0 && a_coord >= 0)
		return shade_clip_plane_create(b, c, a, b_coord, c_coord, a_coord, fs, f_uni);
	if (c_coord < 0 && a_coord >= 0 && b_coord >= 0)
		return shade_clip_plane_create(c, a, b, c_coord, a_coord, b_coord, fs, f_uni);
	return 0;
}

void shade_clip_tri(const struct vertice* const args, vec4 (*fs)(const struct vertice* const, const uniforms), const uniforms f_uni) {
	int out = 0;
	if (shade_clip_plane(args, args + 1, args + 2, args[0].pos.w + args[0].pos.x, args[1].pos.w + args[1].pos.x, args[2].pos.w + args[2].pos.x, fs, f_uni))
		return; // Left
	if (shade_clip_plane(args, args + 1, args + 2, args[0].pos.w - args[0].pos.x, args[1].pos.w - args[1].pos.x, args[2].pos.w - args[2].pos.x, fs, f_uni))
		return; // Right
	if (shade_clip_plane(args, args + 1, args + 2, args[0].pos.w + args[0].pos.y, args[1].pos.w + args[1].pos.y, args[2].pos.w + args[2].pos.y, fs, f_uni))
		return; // Bottom
	if (shade_clip_plane(args, args + 1, args + 2, args[0].pos.w - args[0].pos.y, args[1].pos.w - args[1].pos.y, args[2].pos.w - args[2].pos.y, fs, f_uni))
		return; // Top
	if (shade_clip_plane(args, args + 1, args + 2, args[0].pos.z, args[1].pos.z, args[2].pos.z, fs, f_uni))
		return; // Near
	if (shade_clip_plane(args, args + 1, args + 2, args[0].pos.w - args[0].pos.z, args[1].pos.w - args[1].pos.z, args[2].pos.w - args[2].pos.z, fs, f_uni))
		return; // Far

	if(!ZG_DISABLE_CULLING)
	if((args[1].pos.x/args[1].pos.w - args[0].pos.x/args[0].pos.w)*(args[2].pos.y/args[2].pos.w - args[0].pos.y/args[0].pos.w)
	 - (args[1].pos.y/args[1].pos.w - args[0].pos.y/args[0].pos.w)*(args[2].pos.x/args[2].pos.w - args[0].pos.x/args[0].pos.w) < 0)
		return;	// Face must be clockwise, or facing away from camera

	shade_triangle(args, fs, f_uni);
}

void draw(const struct vertice* const args, vertice (*vs)(const struct vertice* const, const uniforms), const uniforms v_uni, vec4 (*fs)(const struct vertice* const, const uniforms), const uniforms f_uni) {
	struct vertice a = vs(args+0, v_uni);
	struct vertice b = vs(args+1, v_uni);
	struct vertice c = vs(args+2, v_uni);

	struct vertice trans[3] = { a, b, c };
	shade_clip_tri(trans, fs, f_uni);

	free(a.vec2_a);
	free(a.vec3_a);
	free(a.vec4_a);
}