#include "o03_types.h"
/* real entry is glabel+0xC (rom 0x18BFC0): the 3 leading words are padding junk */
extern O3Ps *D_800E39C0;
void *func_00252FFC(s32 size);
s32 func_0029A9A0(s32 a);
void func_002A3358();
void func_0040E958(void *it, s32 on);
O3Hdr *func_0040ECB0(s32 p, s32 id);
s32 func_0041B690(s32 p, s32 n);
void func_0041B768(s32 p, s32 i, s32 id);
s32 func_0041EBC0(void);
void func_0041E478(s32 i);
s32 func_0041DFB4(s32 parent) {
    O3Hdr *it;
    s32 i;
    D_800E39C0 = func_00252FFC(0x20);
    D_800E39C0->parent = parent;
    D_800E39C0->menu = func_0041B690(parent, 4);
    func_0041B768(parent, 0, 0x389);
    func_0041B768(parent, 1, 0x389);
    func_0041B768(parent, 2, 0x389);
    func_0041B768(parent, 3, 0x389);
    it = func_0040ECB0(parent, 0x38B);
    it->alpha = 0x8C;
    if (func_0029A9A0(0) == 0x16) {
        func_0040E958(it, 0);
    }
    D_800E39C0->timer = 0;
    D_800E39C0->sel = 0;
    D_800E39C0->w[0] = func_0040ECB0(parent, 0x38C);
    D_800E39C0->w[1] = func_0040ECB0(parent, 0x395);
    D_800E39C0->w[2] = func_0040ECB0(parent, 0x396);
    D_800E39C0->cnt = func_0041EBC0();
    for (i = 0; i < 3; i++) {
        func_0041E478(i);
        func_0040E958(func_0040ECB0(D_800E39C0->w[i], 0x392), 0);
    }
    func_002A3358();
    func_0040E958(func_0040ECB0(D_800E39C0->w[D_800E39C0->sel], 0x392), 1);
    return 0;
}
