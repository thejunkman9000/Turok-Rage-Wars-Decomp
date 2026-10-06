#include "b16_types.h"

f32 func_802BC380(f32 x);

f32 func_00272768(Vec3f *a, Vec3f *b) {
    f32 dx = a->x - b->x;
    f32 dy = a->y - b->y;
    f32 dz = a->z - b->z;
    return func_802BC380(dx * dx + dy * dy + dz * dz);
}
