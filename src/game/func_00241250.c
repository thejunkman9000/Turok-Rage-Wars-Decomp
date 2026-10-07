#include "b09_types.h"

void func_00271FD8(f32 *, void *, void *);

s32 func_00241250(B09Quad *q, B09V3 *pt) {
    f32 d[3];
    s32 r;
    func_00271FD8(d, pt, &q->v[0]);
    r = 0;
    if (!(q->nx * d[0] + q->ny * d[1] + q->nz * d[2] >= 0.0f)) {
        r = 1;
    }
    return r;
}
