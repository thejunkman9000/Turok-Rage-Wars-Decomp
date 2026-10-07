#include "b16_types.h"

f32 func_802BC380(f32 x);

static inline void vcross(Vec3f *dst, Vec3f *a, Vec3f *b) {
    dst->x = a->y * b->z - a->z * b->y;
    dst->y = a->z * b->x - a->x * b->z;
    dst->z = a->x * b->y - a->y * b->x;
}

static inline void vnorm(Vec3f *v) {
    f32 len;
    f32 inv;
    len = func_802BC380(v->x * v->x + v->y * v->y + v->z * v->z);
    if (len != 0.0f) {
        inv = 1.0f / len;
        v->x *= inv;
        v->y *= inv;
        v->z *= inv;
    }
}

static inline Vec3f vscale(Vec3f *v, f32 s) {
    Vec3f r;
    r.x = v->x * s;
    r.y = v->y * s;
    r.z = v->z * s;
    return r;
}
Vec3f func_0027230C(Vec3f *v, Vec3f *a, Vec3f *b) {
    Vec3f n;
    f32 d;
    vcross(&n, a, b);
    vnorm(&n);
    d = v->x * n.x + v->y * n.y + v->z * n.z;
    return vscale(&n, d);
}
