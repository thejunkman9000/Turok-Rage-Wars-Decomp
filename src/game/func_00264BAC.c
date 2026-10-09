#include "b14_types.h"
extern B14Game D_80145040[];
extern B14Mgr D_8010FC40[];
extern u8 D_8011FE88[];
s32 func_0028B370(void *a, s32 b);

void func_00264BAC(void) {
    s32 i;
    u8 *pl;
    B14Mgr *m = D_8010FC40;
    for (i = 0; i < D_80145040->count; i++) {
        pl = D_80145040->players + i * 0x16E8;
        *(B14Blk70 *)(pl + 0x5E0) = m->blk[i];
        if (m->b == 1) {
            *(B14W3 *)(pl + 8) = m->w[i];
            *(f32 *)(pl + 0x6C) = m->f3F0[i];
            *(s32 *)(pl + 0x14) = func_0028B370(D_8011FE88, m->i410[i]);
        }
    }
}
