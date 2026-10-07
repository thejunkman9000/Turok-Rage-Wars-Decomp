#include "o01_types.h"

extern s32 D_801534F0[];
extern O01PadTab *D_800E2854;
u32 func_004057EC(u32 n);

s32 func_004053E0(s32 pad, s32 idx, u32 *out) {
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    *out = func_004057EC(D_800E2854[pad].ent[idx].unk0);
    return 0;
}
