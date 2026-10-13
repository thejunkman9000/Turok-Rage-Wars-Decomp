#include "veu3n10_types.h"

extern s32 D_801462C8;
extern s32 D_801462CC;
extern u8 D_800D3B0C[];
extern u8 D_800D3B10[];

s32 func_auto_0043E168(VeuItem *a) {
    if (D_801462CC & 1) a->flags |= 0x1000000; else a->flags &= ~0x1000000;
    if (D_801462C8 & 1) a->txt = D_800D3B0C; else a->txt = D_800D3B10;
    return 0;
}
