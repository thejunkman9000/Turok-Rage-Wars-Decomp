#include "o03_types.h"
void *func_00252FFC(s32 size);
void func_002A1748(void *p, s32 v, s32 n);
s32 func_0029A958();
s32 func_00411E4C(s32);
O3Hdr *func_0040ECB0(s32, s32);
void func_0040EE64(O3Hdr *, void *);
void func_00419D04();
void func_00419F98(O3A *o);
O3A *func_00419ED4(s32 a, u32 base) {
    O3Hdr *g;
    O3A *o;
    g = func_0040ECB0(func_00411E4C(func_0029A958()), a & 0xFFFF);
    func_00411E4C(func_0029A958());
    o = func_00252FFC(0x88);
    func_002A1748(o, 0, 0x88);
    o->gobj = g;
    o->base = base;
    o->id2 = 0xB62;
    o->unk12 = 8;
    o->id = 0xB62;
    g->alpha = (u8)o->base;
    func_00419D04(o, -1, g, 0xB62);
    func_00419F98(o);
    func_0040EE64(g, o);
    return o;
}
