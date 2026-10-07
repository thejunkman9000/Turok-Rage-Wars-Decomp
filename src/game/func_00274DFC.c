#include "b17_types.h"

s32 func_00274DFC(RayObj *a, PlaneObj *b) {
    Vec3f v;
    Vec3f d;
    s32 r;

    v = a->dir;
    d.x = b->pos.x - a->pos.x;
    d.z = b->pos.z - a->pos.z;
    r = 0;
    if (!(v.x * d.x + v.z * d.z <= 0.0f)) {
        r = 1;
    }
    return r;
}
