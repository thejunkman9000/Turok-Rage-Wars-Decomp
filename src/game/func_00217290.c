#include "b04_types.h"
f32 func_00217290(B04Pos *p, Vec3f v) {
    f32 dx = v.x - p->x;
    f32 dz = v.z - p->z;
    return dx*dx + dz*dz;
}
