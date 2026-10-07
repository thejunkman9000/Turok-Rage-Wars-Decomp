#include "b12_types.h"

extern s32 D_800D2640;
extern u8 D_800C8F30[];
s32 func_00250754(B12Obj *o, s32 a1);
s32 func_00250BD4(B12Obj *o, s32 **b);
s32 func_00251F0C(s32 a, s32 b, s32 c, s32 d, s32 e, B12Obj *o, void *fn, void *p, s32 i);
s32 *func_0026E27C(s32 h, s32 b, s32 *out);

s32 *func_00250ACC(B12Obj *o, s32 a1, s32 a2, s32 *out) {
    s32 h = func_00250754(o, a2);
    s32 r;
    if (h) {
        o->unkB4 = h;
        *out = h;
        out = func_0026E27C(h, a1, out + 1);
        r = func_00251F0C(0, o->unkD0 | D_800D2640, h, (s32)o->unk20, 8, o, (void *)func_00250BD4, D_800C8F30, 1);
        if (r) {
            *out = r;
            out++;
        }
    }
    return out;
}
