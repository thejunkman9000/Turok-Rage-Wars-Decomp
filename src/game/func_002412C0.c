#include "b09_types.h"

extern f32 D_800C8830;
void func_00271FD8(f32 *, void *, void *);

s32 func_002412C0(B09Quad *q, B09V3 *org, B09V3 *dir, f32 *t) {
    f32 d1[3];
    f32 d2[3];
    f32 denom;
    f32 v;
    s32 r;
    if (q->unk8 == 0) {
        return 0;
    }
    func_00271FD8(d1, dir, org);
    denom = q->nx * d1[0] + q->ny * d1[1] + q->nz * d1[2];
    r = 0;
    if (!(denom >= 0.0f)) {
        func_00271FD8(d2, org, &q->v[0]);
        r = 1;
        v = -(q->nx * d2[0] + q->ny * d2[1] + q->nz * d2[2]) / denom;
    } else {
        v = D_800C8830;
    }
    *t = v;
    return r;
}
