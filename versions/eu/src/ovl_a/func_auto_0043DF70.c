#include "veu3n10_types.h"

extern s32 D_801462C8;
extern s32 D_801462CC;

s32 func_auto_0043DF70(VeuItem *a, u32 mask, void *p, void *q) {
    if (D_801462CC & mask) a->flags |= 0x1000000; else a->flags &= ~0x1000000;
    if (D_801462C8 & mask) a->txt = p; else a->txt = q;
    return 0;
}
