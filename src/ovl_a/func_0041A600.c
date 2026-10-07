#include "o03_types.h"
void *func_00252FFC(s32 size);
void func_002A1748(void *p, s32 v, s32 n);
s32 func_0029A958();
s32 func_00411E4C(s32);
O3BarG *func_0040ECB0(s32, s32);
void func_0040EF24(O3Bar *, O3Bar *);
void func_0040F004(s32, O3Bar *, O3Bar *);
O3Bar *func_0041A600(s32 a, s32 b, s32 max) {
    O3Bar *src;
    s32 s;
    O3Bar *o;
    O3BarG *g;
    src = (O3Bar *)func_0040ECB0(func_00411E4C(func_0029A958()), a & 0xFFFF);
    s = func_00411E4C(func_0029A958());
    o = func_00252FFC(0x58);
    func_002A1748(o, 0, 0x58);
    *(O3Blk11 *)o = *(O3Blk11 *)src;
    o->h.id2 = 0xB63;
    o->col = src->col;
    g = func_0040ECB0(s, b & 0xFFFF);
    o->g = g;
    o->width = g->w;
    o->max = max;
    o->val = 0;
    o->f54 = 2;
    func_0040EF24(src, o);
    src->h.id = -1;
    func_0040F004(s, src, o);
    return o;
}
