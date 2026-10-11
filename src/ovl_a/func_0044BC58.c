#include "s1005_types.h"

extern S5PortFlags D_8010FBE0[];
extern void func_00285A94(void *a, void *b, s32 n);

s32 func_0044BC58(S5Ctl *c, s32 port) {
    s32 i;

    c->port = port;
    c->f0 = 0;
    c->fC8 = 0;
    c->fCC = 0;
    c->f220 = 0;
    c->f8 = 0;
    c->fC = 0;
    c->f10 = 0;
    c->fC4 = 0;
    c->fC5 = 0;
    c->fC6 = 0;
    c->fC7 = 0;
    c->f14 = 0;
    c->f18 = 0;
    c->f1C = 0;
    c->f20 = 0;
    c->f24 = 0;
    c->f28 = 0;
    for (i = 0; i < 32; i++) {
        c->ent[i].a = 0;
        c->ent[i].b = 0;
        c->ent[i].c = 0x30;
        c->ent[i].d = 0;
    }
    c->f0 = ((D_8010FBE0[port].b[3] >> 3) ^ 1) & 1;
    c->fD0 = 0;
    c->fD4 = 0;
    func_00285A94(c->blkA, c->blkB, 3);
    return c->f0;
}
