#include "b14_types.h"
extern B14PortFlags D_8010FBE0[];
void func_00285A94(void *a, void *b, s32 n);
void func_00263D10(B14Ctl *c) {
    s32 port = c->port;
    s32 v = ((D_8010FBE0[port].b[3] >> 3) ^ 1) & 1;
    s32 i;
    if (v != 0 && c->f0 == 0) {
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
        c->fD0.i = 0;
        c->fD4.i = 0;
        func_00285A94(c->blkA, c->blkB, 3);
    }
    c->f0 = v;
}
