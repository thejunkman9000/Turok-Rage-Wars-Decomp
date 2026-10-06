#include "b10_types.h"

extern B10G D_801041F0[];
s32 func_00243A80(B10Obj *o, Vec3f v, B10Q *q);

s32 func_00246548(B10Obj *o, Vec3f v, B10Q *q) {
    B10Blk saved;
    B10Q loc;
    s32 r;
    saved = *(B10Blk *)o;
    loc = *q;
    loc.b4 = 0;
    loc.b5 = 1;
    func_00243A80(o, v, &loc);
    *(B10Blk *)o = saved;
    r = 0;
    if (D_801041F0[0].f0 || D_801041F0[0].f9C) {
        r = 1;
    }
    return r ^ 1;
}
