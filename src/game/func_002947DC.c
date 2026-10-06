#include "b21_types.h"

extern u8 D_8011FE88[];
s32 func_44DE70(void *a, s32 b, s32 c, void *d, s32 e);

void func_002947DC(B21Game *g, s32 a) {
    s32 buf[6];
    if (!func_44DE70(D_8011FE88, -1, a, buf, 1)) {
        a = 0;
    }
    g->unk26DC1 = 2;
    g->unk26DD8 = a;
    g->unk26DBC = 14;
}
