#include "b16_types.h"

Vec3f func_00272284(Vec3f *a, Vec3f *b) {
    Vec3f r;
    f32 d;
    d = a->x * b->x + a->y * b->y + a->z * b->z;
    r.x = a->x - d * b->x;
    r.y = a->y - d * b->y;
    r.z = a->z - d * b->z;
    return r;
}
