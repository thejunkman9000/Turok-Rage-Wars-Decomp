#include "b17_types.h"

f32 func_002BC380(f32); /* sqrtf */
f32 func_00274640(f32 x);

f32 func_0027612C(Poly3 *p, s32 i) {
    Pt3 *a, *b;
    f32 dx, dz, len, r;

    a = p->v[i];
    b = p->v[(i + 1) % 3];
    dx = b->x - a->x;
    dz = b->z - a->z;
    len = func_002BC380(dx * dx + dz * dz);
    if (len == 0.0f) {
        return 0.0f;
    }
    r = func_00274640(dx / len);
    if (!(dz < 0.0f)) {
        r = -r;
    }
    return r;
}
