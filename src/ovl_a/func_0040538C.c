#include "o01_types.h"

extern s32 D_801534F0[];
extern O01PadTab *D_800E2854;

s32 func_0040538C(s32 pad, s32 idx, u8 **out) {
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    *out = D_800E2854[pad].ent[idx].unkA;
    return 0;
}
