#include "b14_types.h"
extern B14Game D_80145040[];
extern B14Mgr D_8010FC40[];
extern u8 D_8011FE88[];
s32 func_0028B32C(void *a, s32 b, s32 c, s32 d);
void func_00264D00(void) {
    s32 i;
    u8 *pl;
    B14Mgr *m = D_8010FC40;
    for (i = 0; i < D_80145040->count; i++) {
        pl = D_80145040->players + i * 0x16E8;
        m->blk[i] = *(B14Blk70 *)(pl + 0x5E0);
        m->w[i] = *(B14W3 *)(pl + 8);
        m->f3F0[i] = *(f32 *)(pl + 0x6C);
        m->i410[i] = func_0028B32C(D_8011FE88, *(s32 *)(pl + 0x14), *(s32 *)(pl + 8), *(s32 *)(pl + 0xC));
    }
}
