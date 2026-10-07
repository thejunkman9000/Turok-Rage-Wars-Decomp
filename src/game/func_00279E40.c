#include "b17_types.h"

extern f32 D_800C9C30;
extern f32 D_800C9C34;
extern f32 D_800C9C38;
extern f32 D_800D2988;
f32 sinf(f32 x);
void func_00271FA4(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00271FD8(Vec3f *d, Vec3f *a, Vec3f *b);
void func_0027200C(Vec3f *d, Vec3f *a, f32 s);
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);

void func_00279E40(ActorX *a, f32 scale) {
    Vec3f up, axis, dir, t1, t2, t3;
    s32 n;
    f32 f, tmp;

    n = a->ch118->p2C->b18;
    f = D_800C9C30;
    if (n != 0) {
        if (a->f140 < (f32)n) {
            f = a->f140 / (f32)n;
        }
    }
    f = f * scale;
    dir = a->v174;
    if (a->f1AC > 0.0f) {
        up.x = 0.0f;
        up.z = 0.0f;
        up.y = D_800C9C34;
        func_00272088(&axis, &up, &dir);
        func_0027200C(&t1, &axis, sinf(a->f19C) * a->f1AC * f);
        a->f19C += a->f1A4 * f * D_800D2988;
        tmp = a->f19C;
        func_0027200C(&t2, &axis, sinf(tmp) * a->f1AC * f);
        func_00271FD8(&a->vel, &a->vel, &t1);
        func_00271FA4(&a->vel, &a->vel, &t2);
    } else {
        a->f19C = a->f19C + a->f1A4 * f * D_800D2988;
    }
    if (a->f1B0 > 0.0f) {
        up.x = 0.0f;
        up.z = 0.0f;
        up.y = D_800C9C38;
        func_00272088(&t3, &up, &dir);
        func_00272088(&axis, &t3, &dir);
        func_0027200C(&t1, &axis, sinf(a->f1A0) * a->f1B0 * f);
        a->f1A0 += a->f1A8 * f * D_800D2988;
        tmp = a->f1A0;
        func_0027200C(&t2, &axis, sinf(tmp) * a->f1B0 * f);
        func_00271FD8(&a->vel, &a->vel, &t1);
        func_00271FA4(&a->vel, &a->vel, &t2);
    } else {
        a->f1A0 = a->f1A0 + a->f1A8 * f * D_800D2988;
    }
}
