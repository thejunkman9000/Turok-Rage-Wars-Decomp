#include "b16_types.h"

void func_00272038(Vec3f *dst, f32 t, Vec3f *a, Vec3f *b) {
    dst->x = a->x + t * (b->x - a->x);
    dst->y = a->y + t * (b->y - a->y);
    dst->z = a->z + t * (b->z - a->z);
}
