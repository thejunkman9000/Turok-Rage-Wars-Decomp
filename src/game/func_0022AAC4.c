#include "b06_types.h"

extern u8 *D_800D052C[];

s32 func_0022AAC4(u8 *a, s32 i) {
    u8 *t = D_800D052C[i];
    s16 *p;
    if (B6F(a, s32, 0x594) == 1) {
        p = B6F(t, s16 *, 0x20);
    } else {
        p = B6F(t, s16 *, 0x24);
    }
    if (p != NULL) {
        return *p;
    }
    return -1;
}
