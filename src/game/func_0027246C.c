#include "b16_types.h"
f32 func_802BC380(f32 x);

static inline Vec3f vproj(Vec3f *a, Vec3f *b) {
    Vec3f r;
    f32 d;
    d = a->x * b->x + a->y * b->y + a->z * b->z;
    r.x = a->x - d * b->x;
    r.y = a->y - d * b->y;
    r.z = a->z - d * b->z;
    return r;
}

Vec3f func_0027246C(Vec3f *v, Vec3f *n) {
    Vec3f t;
    f32 len;
    f32 s;
    t = vproj(v, n);
    len = func_802BC380(t.x * t.x + t.y * t.y + t.z * t.z);
    if (len != 0.0f) {
        s = func_802BC380(v->x * v->x + v->y * v->y + v->z * v->z) / len;
        t.x *= s;
        t.y *= s;
        t.z *= s;
    }
    return t;
}
