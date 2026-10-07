#include "b12_types.h"

extern s32 D_800D2640;
extern u8 D_800C8F30[];
s32 func_00250754(B12Obj *o, s32 a1);
s32 func_00250BD4(B12Obj *o, s32 **b);
s32 func_00251F0C(s32 a, s32 b, s32 c, s32 d, s32 e, B12Obj *o, void *fn, void *p, s32 i);
void func_002536F4(s32 a, s32 b);
void func_0026E158(s32 a);

void func_00250950(B12Obj *o) {
    s32 h;
    s32 r;
    if (!(o->unkD8 & 0x40)) {
        h = func_00250754(o, o->unk1);
        if (h) {
            func_0026E158(h);
            r = func_00251F0C(0, o->unkD0 | D_800D2640, h, (s32)o->unk20, 8, o, (void *)func_00250BD4, D_800C8F30, 0);
            if (r) {
                func_002536F4(0, r);
            }
            func_002536F4(0, h);
        }
    }
}
