#include "b16_types.h"

void func_00274108(B16Vec4 *dst, B16Vec4 *a, B16Vec4 *b) {
    dst->x = b->w * a->x - b->z * a->y + b->y * a->z + b->x * a->w;
    dst->y = b->z * a->x + b->w * a->y - b->x * a->z + b->y * a->w;
    dst->z = -b->y * a->x + b->x * a->y + b->w * a->z + b->z * a->w;
    dst->w = -b->x * a->x - b->y * a->y - b->z * a->z + b->w * a->w;
}
