#include "b23_types.h"

extern MinMaxF D_800D2BDC;
extern MinMaxF D_800D2BE8;
extern f32 D_800CAF08;
extern f32 D_800CAF0C;
extern s32 D_8014D328;

s32 func_002A23A4(s32 size) {
    s32 n = (size + 7) & ~7;
    s32 old = D_8014D328;

    D_8014D328 = old + n;
    MM_UPDATE(D_800D2BE8, (f32)n, D_800CAF08, D_800CAF0C)
    MM_UPDATE(D_800D2BDC, (f32)-n, D_800CAF08, D_800CAF0C)
    return old;
}
