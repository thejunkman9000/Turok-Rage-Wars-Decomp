#include "o03_types.h"
void *func_00252FFC(s32 size);
void func_002A1748(void *p, s32 v, s32 n);
s32 func_0029A958();
s32 func_00411E4C(s32);
O3B60G *func_0040ECB0(s32, s32);
void func_0040EE64(O3B60G *, void *);
void func_0041A4FC(O3B60 *o);
void func_0041A4B0(O3B60 *o, s32 v);
O3B60 *func_0041A300(s32 a, s32 b) {
    O3B60G *g;
    s32 s;
    O3B60 *o;
    g = func_0040ECB0(func_00411E4C(func_0029A958()), a & 0xFFFF);
    s = func_00411E4C(func_0029A958());
    o = func_00252FFC(0x7C);
    func_002A1748(o, 0, 0x7C);
    o->h.id2 = 0xB60;
    o->h.unk12 = 8;
    o->h.id = 0xB60;
    o->g = g;
    o->g2 = func_0040ECB0(s, b & 0xFFFF);
    o->sp1 = 0.33333334f;
    o->sp2 = 0.33333334f;
    o->g->fx = 0;
    o->g->fy = 0.05f;
    o->c[0] = o->g2->col[0].w;
    o->c[1] = o->g2->col[1].w;
    o->c[2] = o->g2->col[2].w;
    o->c[3] = o->g2->col[3].w;
    o->stepA = (((o->g2->col[1].w & 0xFF0000) >> 16) - ((o->g2->col[0].w & 0xFF0000) >> 16)) / 75;
    o->stepB = (u32)(o->g2->col[0].c.r - o->g2->col[1].c.r) / 75;
    o->f78 = 1;
    func_0041A4FC(o);
    func_0041A4B0(o, 1);
    func_0040EE64(g, o);
    return o;
}
