#include "b21_types.h"

f32 func_002979B0(B21Plane *a, Vec3f *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z - a->w;
}
