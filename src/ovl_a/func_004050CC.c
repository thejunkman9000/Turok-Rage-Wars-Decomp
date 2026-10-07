#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];
extern O01PadTab *D_800E2854;

s32 func_004050CC(s32 pad, s32 *cnt) {
    s32 i;
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    *cnt = 0;
    if (D_80153500[pad] == 0) {
        for (i = 0; i < 16; i++) {
            if (D_800E2854[pad].ent[i].unk0 == 0) {
                (*cnt)++;
            }
        }
    }
    return D_80153500[pad];
}
