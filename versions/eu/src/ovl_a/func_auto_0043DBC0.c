#include "veu3n10_types.h"

extern VeuCheatBuf D_800E5CA0;
extern s32 D_80154030;

/* delete the character before the cursor */
s32 func_auto_0043DBC0(void) {
    s32 i;
    D_80154030 = -1;
    D_800E5CA0.timer = 0;
    if (D_800E5CA0.len == 0) return 0;
    if (D_800E5CA0.pos == 0) return 0;
    for (i = D_800E5CA0.pos - 1; i < 23; i++)
        D_800E5CA0.buf[i] = D_800E5CA0.buf[i + 1];
    D_800E5CA0.pos--;
    D_800E5CA0.len--;
    return 0;
}
