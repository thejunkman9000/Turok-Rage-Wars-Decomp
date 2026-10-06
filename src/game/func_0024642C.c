#include "b10_types.h"

extern f32 D_800C8918;
extern u8 D_80103FD0[];
f32 func_0024D274(void *o);
s32 func_00243A80(B10Obj *o, Vec3f v, void *q);

s32 func_0024642C(B10Obj *o, B10Obj *other) {
    B10Blk saved;
    Vec3f v;
    f32 k;
    s32 r;
    saved = *(B10Blk *)o;
    k = D_800C8918;
    o->fC += func_0024D274(o) * k;
    v = *(Vec3f *)&other->u8;
    v.y += func_0024D274(other) * k;
    r = func_00243A80(o, v, D_80103FD0);
    *(B10Blk *)o = saved;
    return r == 0;
}
