#include "b21_types.h"
#include "b21_world.h"

extern u8 D_8011FE88[];
s32 func_44DE70(void *a, s32 b, s32 c, void *d, s32 e);

void func_00293268(B21Game *g, s32 a) {
    s32 buf[6];
    B21GameBlk *b;
    if (!func_44DE70(D_8011FE88, -1, a, buf, 1)) {
        a = 0;
    }
    b = &D_80145040.blk;
    b->unk0 = 0;
    b->unk4 = 0;
    b->unk8 = 0;
    b->unkC = 0;
    b->unk88 = 0;
    g->unk26DC1 = 2;
    g->unk26DD8 = a;
    g->unk26DDC = 1;
    g->unk26DBC = 13;
}
