#include "b17_types.h"

extern f32 D_800C9C98;
extern f32 D_800C9C9C;
extern f32 D_800C9CA0;
extern f32 D_800C9CA4;
extern f32 D_800C9CA8;
extern f32 D_800C9CAC;
extern f32 D_800C9CB0;
extern f32 D_800C9CB4;
f32 Trunc16ToF32(u16 v);
f32 func_002BC380(f32); /* sqrtf */
void func_00270D40(Quat *out, f32 t, Quat *a, Quat *b);
void func_00271888(Quat *q, Vec3f *v);
void func_00271FA4(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00271FD8(Vec3f *d, Vec3f *a, Vec3f *b);
void func_0027200C(Vec3f *d, Vec3f *a, f32 s);
void func_002720EC(Vec3f *v);
void func_00272908(Mat4F *m, Vec3f *in, Vec3f *out);
void func_002742B4(Quat *q, Mat4F *m);
void func_00279E40(ActorX *a, f32 s);

static inline void vel_tail(ActorX *a) {
    Vec3f d, t;
    Vec3f *v = &a->vel;
    f32 s, lim, len;

    s = Trunc16ToF32(a->ch118->p30->w10);
    if (s != 0.0f) {
        t = a->v174;
        func_0027200C(&d, &t, s);
        func_00271FA4(v, v, &d);
        len = func_002BC380(a->vel.x * a->vel.x + a->vel.y * a->vel.y + a->vel.z * a->vel.z);
        lim = Trunc16ToF32(a->ch118->p30->w12);
        if (s > 0.0f) {
            if (!(lim < len)) goto skip;
        } else {
            if (!(len < lim)) goto skip;
        }
        func_0027200C(v, &t, lim);
skip:;
    }
    func_00279E40(a, 1.0f);
}

void func_0027A9B8(ActorX *a, Vec3f *target) {
    Vec3f d, v20;
    Quat q30, q40, q50;
    Mat4F m60;
    f32 dist, speed, k, t;

    func_00271FD8(&d, target, &a->pos);
    dist = func_002BC380(d.x * d.x + d.y * d.y + d.z * d.z);
    if (dist <= D_800C9C98) {
        a->pos = *target;
        return;
    }
    func_002720EC(&d);
    func_00271888(&q40, &d);
    func_00271888(&q30, &a->v174);
    speed = func_002BC380(a->vel.x * a->vel.x + a->vel.y * a->vel.y + a->vel.z * a->vel.z);
    if (dist < D_800C9C9C) {
        t = dist - D_800C9CA0;
        if (t < 0.0f) {
            t = 0.0f;
        } else {
            t = t * D_800C9CA4;
        }
        k = D_800C9CAC - t * D_800C9CA8;
    } else {
        k = D_800C9CB0;
    }
    func_00270D40(&q50, k, &q30, &q40);
    func_002742B4(&q50, &m60);
    v20.x = 0;
    v20.y = 0;
    v20.z = D_800C9CB4;
    func_00272908(&m60, &v20, &a->v174);
    func_0027200C(&a->vel, &a->v174, speed);
    vel_tail(a);
}
