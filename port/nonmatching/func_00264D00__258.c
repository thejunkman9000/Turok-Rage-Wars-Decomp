#include "b14_types.h"

typedef struct B14Pl {
    /* 0x0000 */ u8 pad0[8];
    /* 0x0008 */ B14W3 w;
    /* 0x0014 */ s32 f14;
    /* 0x0018 */ u8 pad18[0x6C - 0x18];
    /* 0x006C */ f32 f6C;
    /* 0x0070 */ u8 pad70[0x5E0 - 0x70];
    /* 0x05E0 */ B14Blk70 blk;
    /* 0x0650 */ u8 pad650[0x16E8 - 0x650];
} B14Pl;

typedef struct B14GameP {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ B14Pl *players;
    /* 0x08 */ s32 count;
} B14GameP;

extern B14GameP D_80145040[];
extern B14Mgr D_8010FC40[];
extern u8 D_8011FE88[];
s32 func_0028B32C(void *a, s32 b, s32 c, s32 d);

void func_00264D00(void) {
    s32 i;
    B14Pl *pl;
    B14Mgr *m = D_8010FC40;
    for (i = 0; i < D_80145040->count; i++) {
        pl = &D_80145040->players[i];
        m->blk[i] = pl->blk;
        m->w[i] = pl->w;
        m->f3F0[i] = pl->f6C;
        m->i410[i] = func_0028B32C(D_8011FE88, pl->f14, pl->w.a, pl->w.b);
    }
}
