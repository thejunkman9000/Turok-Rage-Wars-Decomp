#include "b02_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, void *b);

static inline void *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return &pool->data[idx * pool->elemSize];
}

s32 func_0020CB3C(B2Mgr *m, Vec3f *p) {
    s32 best = -1;
    f32 bestd = 0.0f;
    s32 i;
    Vec3f d;
    f32 d2;

    for (i = 0; i < m->unk4; i++) {
        func_00271FD8(&d, p, getRec0(m, i));
        d2 = d.x * d.x + d.y * d.y + d.z * d.z;
        if (best < 0 || d2 < bestd) {
            best = i;
            bestd = d2;
        }
    }
    return best;
}
