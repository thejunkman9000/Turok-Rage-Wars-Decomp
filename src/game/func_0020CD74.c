#include "b02_types.h"

s32 func_0024DED0(B2Actor *a);
s32 func_0024DF4C(B2Actor *a);
s32 func_0024DF90(B2Actor *a);
s32 func_00243A80(B2Actor *a, Vec3f pos, B2Opts *opts);
extern B2Opts D_801040D0;
extern B2Opts D_80104050;
extern B2Opts D_80104070;
extern B2Opts D_80103FF0;
extern f32 D_800C6E84;

static inline Vec3f *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return (Vec3f *)&pool->data[idx * pool->elemSize];
}

s32 func_0020CD74(B2Mgr *m, B2Actor *a, s32 idx) {
    Vec3f pos;
    B2Opts opts;
    B2Blk80 save;
    s32 r;
    s32 s0;

    pos = *getRec0(m, idx);
    pos.y += D_800C6E84;
    if (a->kind == 1 && (a->flags & 0x300000)) {
        opts = D_801040D0;
    } else {
        s0 = func_0024DED0(a);
        if (func_0024DF4C(a) == 0) {
            if (s0 != 0) {
                opts = D_80104050;
            } else {
                opts = D_801040D0;
            }
        } else if (func_0024DF90(a) == 0) {
            opts = D_80104070;
        } else {
            opts = D_80103FF0;
        }
    }
    opts.w0 = 0x4000;
    save = *(B2Blk80 *)a;
    r = func_00243A80(a, pos, &opts);
    *(B2Blk80 *)a = save;
    return r == 0;
}
