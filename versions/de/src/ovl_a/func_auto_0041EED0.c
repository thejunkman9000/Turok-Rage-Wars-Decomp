#include "o03_types.h"
extern O3Ps *D_800E39C0;
O3Hdr *func_0040ECB0(s32 p, s32 id);
void func_0040E958(O3Hdr *it, s32 on);
void func_0029A73C();
void func_0025DF54(s32 a);
s32 func_auto_0041EED0(s32 a0, s32 a1, s32 a2, s32 a3) {
    O3Hdr *it;
    if (a3 != 1) return 0;
    {
        func_0029A73C();
        it = func_0040ECB0(D_800E39C0->w[D_800E39C0->sel], 0x38C);
        it->alpha = 0xFF;
        func_0040E958(it, 0);
        D_800E39C0->sel = (D_800E39C0->sel + 1) % D_800E39C0->cnt;
        it = func_0040ECB0(D_800E39C0->w[D_800E39C0->sel], 0x38C);
        it->alpha = 0xFF;
        func_0040E958(it, 1);
        D_800E39C0->timer = 0;
        func_0025DF54(0xE80);
    }
    return 0;
}
