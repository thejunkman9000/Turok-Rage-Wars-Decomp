#include "b11_types.h"

void func_0024C864(Vec3f *out, f32 t, Vec3f *a, Vec3f *b) {
    out->x = a->x + t * (b->x - a->x);
    out->y = a->y + t * (b->y - a->y);
    out->z = a->z + t * (b->z - a->z);
}
