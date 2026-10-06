#include "b23_types.h"

extern s32 D_800D2BB0[];

void *func_002A1724(void *dst, void *src, u32 n);

s32 func_002A2198(s32 a0, void *dst, s32 n) {
    func_002A1724(dst, (void *)(D_800D2BB0[0] + D_800D2BB0[1]), n);
    D_800D2BB0[1] += n;
    return 1;
}
