#include "o03_types.h"
void *func_00252FFC(s32 size);
void func_002A1748(void *p, s32 v, s32 n);
s32 func_0029A958();
s32 func_00411E4C(s32);
O3Hdr *func_0040ECB0(s32, s32);
void func_0040EE64(O3Hdr *, void *);
void func_00419A98(O3Menu *o, s32 f);
void func_00419A5C(O3Menu *o, s32 v);
void func_00419A64(O3Menu *o, s32 v);
void func_00419A84(O3Menu *o, s32 v);
O3Menu *func_0041994C(s32 a, s32 *tbl) {
    O3MenuG *g;
    O3Menu *o;
    g = (O3MenuG *)func_0040ECB0(func_00411E4C(func_0029A958()), a & 0xFFFF);
    func_00411E4C(func_0029A958());
    o = func_00252FFC(0x64);
    func_002A1748(o, 0, 0x64);
    *(s16 *)((u8 *)o + 0xE) = 0xB5F;
    *(s16 *)((u8 *)o + 0x12) = 8;
    *(s16 *)((u8 *)o + 0xC) = 0xB5F;
    o->g = g;
    o->f54 = 0;
    o->tbl = tbl;
    o->flags = 0;
    o->cnt = 0;
    if (tbl[0] != -1) {
        do {
            o->cnt = o->cnt + 1;
        } while (tbl[o->cnt] != -1);
    }
    func_00419A98(o, 1);
    func_00419A5C(o, 0);
    func_00419A64(o, 0);
    func_00419A84(o, 0);
    func_0040EE64((O3Hdr *)g, o);
    return o;
}
