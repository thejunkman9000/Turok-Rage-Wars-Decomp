#include "b16_types.h"
f32 func_802BC380(f32 x);
s32 func_00274544(void);

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

static inline Vec3f vlerp(Vec3f *a, Vec3f *b, f32 t) {
    Vec3f r;
    r.x = a->x + t * (b->x - a->x);
    r.y = a->y + t * (b->y - a->y);
    r.z = a->z + t * (b->z - a->z);
    return r;
}

Vec3f func_00271058(Vec3f *v, f32 t) {
    Vec3f d;
    d.x = func_00274544() % 20000 - 10000;
    d.y = func_00274544() % 20000 - 10000;
    d.z = func_00274544() % 20000 - 10000;
    vnorm(&d);
    vnorm(v);
    return vlerp(v, &d, t);
}
