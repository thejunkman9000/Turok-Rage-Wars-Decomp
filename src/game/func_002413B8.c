#include "b09_types.h"

extern f32 D_800C8834;
void func_00271FD8(f32 *, void *, void *);
void func_00272038(void *, f32, void *, void *);

static inline s32 rayhit(B09Quad *q, B09V3 *org, B09V3 *dir, f32 *t) {
    f32 d1[3];
    f32 d2[3];
    f32 denom;
    if (q->unk8 == 0) {
        return 0;
    }
    func_00271FD8(d1, dir, org);
    denom = q->nx * d1[0] + q->ny * d1[1] + q->nz * d1[2];
    if (denom >= 0.0f) {
        *t = D_800C8834;
        return 0;
    }
    func_00271FD8(d2, org, &q->v[0]);
    *t = -(q->nx * d2[0] + q->ny * d2[1] + q->nz * d2[2]) / denom;
    return 1;
}

s32 func_002413B8(B09Quad *q, B09V3 *org, B09V3 *dir, void *out) {
    f32 t;
    if (rayhit(q, org, dir, &t)) {
        func_00272038(out, t, org, dir);
        return 1;
    }
    return 0;
}
