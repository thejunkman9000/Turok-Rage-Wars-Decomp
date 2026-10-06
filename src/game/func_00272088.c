#include "b16_types.h"

void func_00272088(Vec3f *dst, Vec3f *a, Vec3f *b) {
    dst->x = a->y * b->z - a->z * b->y;
    dst->y = a->z * b->x - a->x * b->z;
    dst->z = a->x * b->y - a->y * b->x;
}
