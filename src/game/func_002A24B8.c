#include "b23_types.h"

extern MinMaxF D_800D2BDC;
extern MinMaxF D_800D2BE8;
extern f32 D_800CAF10;
extern f32 D_800CAF14;
extern s32 D_8014D2E0[];
extern s32 D_8014D320;
extern s32 D_8014D328;

void func_002A24B8(void) {
    s32 v = D_8014D2E0[D_8014D320];
    s32 d = v - D_8014D328;

    D_8014D320 = D_8014D320 - 1;
    D_8014D328 = v;
    MM_UPDATE(D_800D2BE8, (f32)-d, D_800CAF10, D_800CAF14)
    MM_UPDATE(D_800D2BDC, (f32)d, D_800CAF10, D_800CAF14)
}
