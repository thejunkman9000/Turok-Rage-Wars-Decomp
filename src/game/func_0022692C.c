#include "b06_types.h"

s32 *func_002533DC(s32 a, s32 size, s32 b, void *c);
extern u8 D_800C7C58[];

void func_0022692C(PlrGroup *g, s32 n) {
    s32 *blk;
    u8 *base;
    u8 *brain;
    u8 *bp;
    s32 s1 = n * 0x16E8;
    s32 s2 = n * 0x330;
    s32 i;
    blk = func_002533DC(0, s1 + s2, 0x23, D_800C7C58);
    g->unk0 = blk;
    g->unk8 = n;
    base = (u8 *)blk[0];
    brain = base + s1;
    memset(g->unk4 = (Plr *)base, 0, s1);
    memset(brain, 0, s2);
    for (i = 0; i < n; i++) {
        g->unk4[i].brain = brain + i * 0x330;
    }
}
