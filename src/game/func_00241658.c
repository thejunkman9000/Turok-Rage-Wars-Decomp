#include "b09_types.h"

s32 func_00241658(B09Quad *q, B09V3 *pt) {
    s32 i;
    s32 j;
    B09V3 *a;
    B09V3 *b;
    f32 ax, az, dz, dx;
    i = 0;
    j = 1;
    for (; i < 4; i++) {
        if (q->ny < 0.0f) {
            b = &q->v[i];
            a = &q->v[j & 3];
        } else {
            a = &q->v[i];
            b = &q->v[j & 3];
        }
        j++;
        ax = a->x;
        if ((b->z - a->z) * (pt->x - ax) + (ax - b->x) * (pt->z - a->z) > 0.0f) {
            return 0;
        }
    }
    return 1;
}
