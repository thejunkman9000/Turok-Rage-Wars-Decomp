#include "b17_types.h"

extern f32 D_800C9AEC;
extern f32 D_800C9AF0;
extern Tri3 *D_800D2638;
extern Vec3f D_80115E10;
void func_00271FD8(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);

static inline Vec3f *tri_normal(Vec3f *out, Tri3 *t) {
    Vec3f e0, e1;

    if (t == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = 0;
    } else if (t != D_800D2638) {
        func_00271FD8(&e0, t->v[1], t->v[0]);
        func_00271FD8(&e1, t->v[2], t->v[1]);
        func_00272088(&D_80115E10, &e0, &e1);
    }
    *out = D_80115E10;
    D_800D2638 = t;
    return out;
}

f32 func_00275E44(Tri3 *t, f32 x, f32 z) {
    Vec3f n, p;
    f32 r;

    if (t == 0) {
        return D_800C9AEC;
    }
    tri_normal(&n, t);
    if (n.y != 0.0f) {
        p = *t->v[0];
        r = ((p.z - z) * n.z + (p.x - x) * n.x + p.y * n.y) / n.y;
    } else {
        r = (t->v[0]->y + t->v[1]->y + t->v[2]->y) * D_800C9AF0;
    }
    return r;
}
