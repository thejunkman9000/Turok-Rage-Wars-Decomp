#include "p2_types.h"

extern char D_800C83CC[];
MemBlk *func_002533DC(s32 a, s32 size, s32 b, char *name);
void *memset(void *p, s32 c, u32 n);

void func_0023A180(Player *o, s32 n) {
    MemBlk *blk;

    o->f_F20 = n;
    blk = func_002533DC(0, n << 6, 0x23, D_800C83CC);
    o->f_F18 = blk;
    memset(o->f_F1C = blk->data, 0, n << 6);
}