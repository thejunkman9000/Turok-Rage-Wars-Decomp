#include "veu3n10_types.h"

extern s32 D_801462C8;
extern s32 D_801462CC;
extern u8 D_800D3B14[];
extern u8 D_800D3B18[];

s32 func_auto_0043E1F0(VeuItem *a) {
    if (D_801462CC & 2) a->flags |= 0x1000000; else a->flags &= ~0x1000000;
    if (D_801462C8 & 2) a->txt = D_800D3B14; else a->txt = D_800D3B18;
    return 0;
}
