#include "b10_types.h"

extern u8 D_801040D0[];
extern u8 D_80104050[];
extern u8 D_80103FF0[];
extern u8 D_80104070[];
s32 func_0024DED0(B10Obj *o);
s32 func_0024DF4C(B10Obj *o);
s32 func_0024DF90(B10Obj *o);
s32 func_00243A80(B10Obj *o, Vec3f v, void *ctx);

s32 func_002462D8(B10Obj *o, Vec3f v, void **out) {
    B10Blk saved;
    s32 res;
    void *ctx;
    s32 r;
    if (o->type == 1 && (o->flags100 & 0x300000)) {
        ctx = D_801040D0;
    } else {
        r = func_0024DED0(o);
        if (func_0024DF4C(o) == 0) {
            ctx = D_801040D0;
            if (r != 0) {
                ctx = D_80104050;
            }
        } else {
            if (func_0024DF90(o) == 0) {
                ctx = D_80104070;
            } else {
                ctx = D_80103FF0;
            }
        }
    }
    if (out) {
        *out = ctx;
    }
    saved = *(B10Blk *)o;
    res = func_00243A80(o, v, ctx);
    *(B10Blk *)o = saved;
    return res;
}

