#include "b17_types.h"

extern f32 D_800C9AE4;
extern f32 D_800C9AE8;
extern Tri3 *D_800D2638;
extern Tri3 *D_800D263C;
extern Vec3f D_80115E10;
extern Vec3f D_80115E20;
void func_00271FD8(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);

static inline Vec3f *tri_normal(Vec3f *out, Tri3 *t) {
    Vec3f e0, e1;

    if (t == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C9AE8;
    } else if (t != D_800D2638) {
        func_00271FD8(&e0, t->v[1], t->v[0]);
        func_00271FD8(&e1, t->v[2], t->v[1]);
        func_00272088(&D_80115E10, &e0, &e1);
    }
    D_800D2638 = t;
    *out = D_80115E10;
    return out;
}

Vec3f *func_00275D04(Vec3f *out, Tri3 *t) {
    if (t == 0) {
        D_80115E20.x = 0;
        D_80115E20.z = 0;
        D_80115E20.y = D_800C9AE4;
    } else if (t != D_800D263C) {
        tri_normal(&D_80115E20, t);
        func_002720EC(&D_80115E20);
    }
    *out = D_80115E20;
    D_800D263C = t;
    return out;
}
