#include "veu3n10_types.h"

extern VeuCheatEnt D_0044FB90[];
extern s32 D_80154030;
extern u8 D_auto_800E41F4;

s32 func_auto_0043DE34(VeuItem *a) {
    if ((u32)D_80154030 < 12) a->txt = D_0044FB90[D_80154030].txt;
    else a->txt = &D_auto_800E41F4;
    return 0;
}
