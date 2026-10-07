#include "b17_types.h"

s32 func_00275B80(Poly3 *p, f32 x, f32 z) {
    s32 i;
    Pt3 *a, *b;

    if (p == 0) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        a = p->v[i];
        b = p->v[(i + 1) % 3];
        if ((b->z - a->z) * (x - a->x) + (a->x - b->x) * (z - a->z) < 0.0f) {
            return 0;
        }
    }
    return 1;
}
