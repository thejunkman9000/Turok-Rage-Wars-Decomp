#include "b17_types.h"

extern f32 D_800C9CB8;
f32 Trunc16ToF32(u16 v);
f32 func_002BC380(f32); /* sqrtf */
void func_0027A9B8(ActorX *a, u8 *p);
void func_0027200C(Vec3f *d, Vec3f *a, f32 s);
void func_00271FA4(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00279E40(ActorX *a, f32 s);

void func_0027AC64(ActorX *a) {
    Vec3f d, t;
    Vec3f *v;
    f32 s, lim, len;

    if (a->p134 != 0 && a->f140 > D_800C9CB8) {
        func_0027A9B8(a, a->p134 + 8);
        return;
    }
    s = Trunc16ToF32(a->ch118->p30->w10);
    if (s != 0.0f) {
        t = a->v174;
        func_0027200C(&d, &t, s);
        func_00271FA4(&a->vel, &a->vel, &d);
        v = &a->vel;
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
