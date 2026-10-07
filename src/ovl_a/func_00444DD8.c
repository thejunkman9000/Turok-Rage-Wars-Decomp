#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; u8 pad2[8]; s32 unk14; } O06A;
extern f32 D_80154100;
extern f32 D_800D2988;
extern s32 func_00265370();
extern s32 func_0040C43C();
s32 func_00444DD8(O06A *a) {
    f32 v = D_80154100 - D_800D2988;
    D_80154100 = v;
    if (v <= 0.0f) D_80154100 = 0.0f;
    if (func_00265370() != 0x400000) a->unk8 |= 0x1000000; else a->unk8 &= ~0x1000000;
    a->unk14 = func_0040C43C();
    return 0;
}
