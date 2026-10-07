#include "b17_types.h"

s32 func_00274D80(RayObj *a, PlaneObj *b, f32 *out) {
    Vec3f d;
    f32 den;
    s32 hit;

    d.x = b->pos.x - a->pos.x;
    d.z = b->pos.z - a->pos.z;
    den = b->nrm.x * a->dir.x + b->nrm.z * a->dir.z;
    hit = 0;
    if (den != 0.0f) {
        hit = 1;
        *out = (d.x * a->dir.x + d.z * a->dir.z) / -den;
    }
    return hit;
}
