#include "p2_types.h"

s32 func_00241604(void *unused, P2Vec3 *a, f32 r, P2Vec3 *b) {
    f32 dx = a->x - b->x;
    f32 dz = a->z - b->z;

    return dx * dx + dz * dz <= r * r;
}