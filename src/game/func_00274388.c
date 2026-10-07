#include "b16_types.h"

void func_00274388(B16Vec4 *dst, f32 t, B16Vec4 *a, B16Vec4 *b) {
    dst->x = a->x + t * (b->x - a->x);
    dst->y = a->y + t * (b->y - a->y);
    dst->z = a->z + t * (b->z - a->z);
    dst->w = a->w + t * (b->w - a->w);
}
