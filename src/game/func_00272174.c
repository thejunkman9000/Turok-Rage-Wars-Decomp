#include "b16_types.h"

void func_00272174(Vec3f *dst, Vec3f *a, Vec3f *b, f32 y) {
    f32 dy = b->y - a->y;
    f32 t;
    if (dy == 0.0f) {
        *dst = *a;
    } else {
        t = (y - a->y) / dy;
        dst->x = a->x + t * (b->x - a->x);
        dst->y = y;
        dst->z = a->z + t * (b->z - a->z);
    }
}
