#include "veu3n10_types.h"

extern VeuCheatBuf D_800E5CA0;
extern s32 D_80154030;
extern u8 D_80152789;

/* insert the selected character at the cursor */
s32 func_auto_0043DAF0(u8 **a) {
    s32 i;
    D_80154030 = -1;
    D_800E5CA0.timer = 0;
    if (D_800E5CA0.len == 22) return 0;
    for (i = 22; D_800E5CA0.pos < i; i--)
        D_800E5CA0.buf[i] = D_800E5CA0.buf[i - 1];
    D_800E5CA0.buf[D_800E5CA0.pos] = *((u8 **)a[5])[D_80152789];
    D_800E5CA0.pos++;
    D_800E5CA0.len++;
    D_800E5CA0.buf[D_800E5CA0.len] = 0;
    return 0;
}
