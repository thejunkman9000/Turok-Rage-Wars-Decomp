#include "veu3n10_types.h"

extern s32 D_80154034;
extern u8 D_auto_800E41F4, D_auto_800E3884, D_auto_800E3894, D_auto_800E38A4, D_auto_800E38B4, D_auto_800E38C4, D_auto_800E38D4;
extern u8 D_auto_800E38E4, D_auto_800E38F4, D_auto_800E3904, D_auto_800E3914, D_auto_800E3924;

s32 func_auto_0043DFE0(VeuItem *a) {
    switch (D_80154034) {
    default: a->txt = &D_auto_800E41F4; break;
    case 0: a->txt = &D_auto_800E3884; break;
    case 1: a->txt = &D_auto_800E3894; break;
    case 2: a->txt = &D_auto_800E38A4; break;
    case 3: a->txt = &D_auto_800E38B4; break;
    case 4: a->txt = &D_auto_800E38C4; break;
    case 5: a->txt = &D_auto_800E38D4; break;
    case 6: a->txt = &D_auto_800E38F4; break;
    case 7: a->txt = &D_auto_800E38E4; break;
    case 8: a->txt = &D_auto_800E3904; break;
    case 9: a->txt = &D_auto_800E3914; break;
    case 10: a->txt = &D_auto_800E3924; break;
    }
    return 0;
}
