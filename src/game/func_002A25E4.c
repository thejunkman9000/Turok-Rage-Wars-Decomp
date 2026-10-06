#include "b23_types.h"

extern MinMaxF D_800D2BDC;
extern MinMaxF D_800D2BF4;
extern f32 D_800CAF18;
extern f32 D_800CAF1C;
extern s32 D_8014D324;

s32 func_002A25E4(s32 size) {
    s32 n = (size + 7) & ~7;
    s32 left = D_8014D324 - n;

    D_8014D324 = left;
    MM_UPDATE(D_800D2BF4, (f32)n, D_800CAF18, D_800CAF1C)
    MM_UPDATE(D_800D2BDC, (f32)-n, D_800CAF18, D_800CAF1C)
    return left;
}
