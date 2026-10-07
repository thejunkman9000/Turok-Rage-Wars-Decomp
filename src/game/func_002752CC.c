#include "b17_types.h"

extern f32 D_800C9AB4;
extern f32 D_800C9AB8;
extern Tri4 *D_800D2630;
extern Vec3f D_80115DF0;
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);

static inline Vec3f *tri4_normal(Vec3f *out, Tri4 *t) {
    Vec3f e0, e1;

    if (t == 0) {
        D_80115DF0.x = 0;
        D_80115DF0.z = 0;
        D_80115DF0.y = D_800C9AB4;
    } else if (t != D_800D2630) {
        e0.x = t->v[1]->x - t->v[0]->x;
        e0.y = t->v[1]->y - t->v[0]->y;
        e0.z = t->v[1]->z - t->v[0]->z;
        e1.x = t->v[2]->x - t->v[1]->x;
        e1.y = t->v[2]->y - t->v[1]->y;
        e1.z = t->v[2]->z - t->v[1]->z;
        func_00272088(&D_80115DF0, &e1, &e0);
    }
    *out = D_80115DF0;
    D_800D2630 = t;
    return out;
}

f32 func_002752CC(Tri4 *t, f32 x, f32 z) {
    Vec3f n, p;
    f32 r;

    if (t == 0) {
        r = 0.0f;
    } else {
        tri4_normal(&n, t);
        if (n.y != 0.0f) {
            p.x = t->v[0]->x;
            p.y = t->v[0]->y;
            p.z = t->v[0]->z;
            r = ((p.z - z) * n.z + (p.x - x) * n.x + p.y * n.y) / n.y;
        } else {
            r = (t->v[0]->y + t->v[1]->y + t->v[2]->y) * D_800C9AB8;
        }
    }
    return r;
}
