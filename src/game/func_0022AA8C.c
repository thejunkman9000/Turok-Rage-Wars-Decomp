#include "b06_types.h"

extern u8 *D_800D052C[];

s32 func_0022AA8C(u8 *a, s32 i) {
    u8 *t = D_800D052C[i];
    if (B6F(a, s32, 0x594) == 1) {
        return B6F(t, s32, 0x20);
    }
    return B6F(t, s32, 0x24);
}
