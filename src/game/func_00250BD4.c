#include "b12_types.h"
s32 func_00278530(s32 a, s32 b, void *c, void *d, s32 e, B12Obj *o);
s32 func_00253E04(s32 a, s32 *b, s32 c);

s32 func_00250BD4(B12Obj *o, s32 **b) {
    s32 x = **b;
    s32 r = func_00278530(x, *o->unk20, o->unkB8, o->unk28, 0, o);
    return func_00253E04(0, (s32 *)b, r);
}
