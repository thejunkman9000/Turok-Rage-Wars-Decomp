#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];
extern O01PadTab *D_800E2854;

s32 func_00405160(s32 pad, s32 *out) {
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    if (D_80153500[pad] == 0) {
        *out = D_800E2854[pad].unk0 / 256;
    } else {
        *out = 0;
    }
    return D_80153500[pad];
}
