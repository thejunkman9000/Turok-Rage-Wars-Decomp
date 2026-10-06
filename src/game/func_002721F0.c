#include "b16_types.h"

Vec3f func_002721F0(Vec3f *a, Vec3f *b, f32 t) {
    Vec3f r;
    f32 dot, d;
    dot = a->x * b->x + a->y * b->y + a->z * b->z;
    d = t * dot + dot;
    r.x = a->x - d * b->x;
    r.y = a->y - d * b->y;
    r.z = a->z - d * b->z;
    return r;
}
