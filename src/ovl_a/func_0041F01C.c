#include "o03_types.h"
extern O3Ps *D_800E39C0;
extern O3Plr D_80153F80[3];
extern O3Pl4 D_80146398[];
void func_0029A73C();
void func_0041E478();
s32 func_0029A9A0(s32 a);
s32 func_0041F01C(s32 a0, s32 a1, u32 a2, s32 a3) {
    s32 j;
    if ((a2 >> 16) == 3 && a3 == 0) {
        func_0029A73C();
        D_80153F80[D_800E39C0->sel].f8 = (D_80153F80[D_800E39C0->sel].f8 + 1) % 5;
        func_0041E478(D_800E39C0->sel);
        if (func_0029A9A0(0) == 0x16) {
            j = D_800E39C0->sel;
            D_80146398[7 - j].f92 = (u8)D_80153F80[j].f8;
        }
    }
    return 0;
}
