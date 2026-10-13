#include "o03_types.h"
/* real entry is glabel+0xC (rom 0x18BFC0): the 3 leading words are padding junk */
extern O3Ps *D_800E39C0;
void *func_00252FFC(s32 size);
s32 func_0029A9A0(s32 a);
void func_002A3358();
void func_auto_0040E8D8(void *it, s32 on);
O3Hdr *func_auto_0040EC30(s32 p, s32 id);
s32 func_auto_0041B610(s32 p, s32 n);
void func_auto_0041B6E8(s32 p, s32 i, s32 id);
s32 func_auto_0041EB50(void);
void func_auto_0041E408(s32 i);
s32 func_auto_0041DF50(s32 parent) {
    O3Hdr *it;
    s32 i;
    D_800E39C0 = func_00252FFC(0x20);
    D_800E39C0->parent = parent;
    D_800E39C0->menu = func_auto_0041B610(parent, 4);
    func_auto_0041B6E8(parent, 0, 0x383);
    func_auto_0041B6E8(parent, 1, 0x383);
    func_auto_0041B6E8(parent, 2, 0x383);
    func_auto_0041B6E8(parent, 3, 0x383);
    it = func_auto_0040EC30(parent, 0x385);
    it->alpha = 0x8C;
    if (func_0029A9A0(0) == 0x16) {
        func_auto_0040E8D8(it, 0);
    }
    D_800E39C0->timer = 0;
    D_800E39C0->sel = 0;
    D_800E39C0->w[0] = func_auto_0040EC30(parent, 0x386);
    D_800E39C0->w[1] = func_auto_0040EC30(parent, 0x38F);
    D_800E39C0->w[2] = func_auto_0040EC30(parent, 0x390);
    D_800E39C0->cnt = func_auto_0041EB50();
    for (i = 0; i < 3; i++) {
        func_auto_0041E408(i);
        func_auto_0040E8D8(func_auto_0040EC30(D_800E39C0->w[i], 0x38C), 0);
    }
    func_002A3358();
    func_auto_0040E8D8(func_auto_0040EC30(D_800E39C0->w[D_800E39C0->sel], 0x38C), 1);
    return 0;
}
