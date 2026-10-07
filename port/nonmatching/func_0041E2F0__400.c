#include "o03_types.h"
extern O3Ps *D_800E39C0;
extern O3Plr D_80153F80[3];
extern O3Chr D_800E381C[][17];
void func_0029A73C();
s32 func_0029A9A0(s32 a);
s32 func_0041ECB4(s32 a, s32 b);
void func_002A125C(void *d, void *s);
void func_0041E478(s32 i);
void func_0025DF54(s32 a);
s32 func_0041E2F0(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 row, col, key;
    if (a3 != 1) return 0;
    func_0029A73C();
    if (func_0029A9A0(0) == 0x16) return 0;
    row = D_80153F80[D_800E39C0->sel].type;
    col = func_0041ECB4(row, D_80153F80[D_800E39C0->sel].id);
    do {
        row ++;
        if (row >= 3) {
            col ++;
            row = 0;
            if (col >= 0x11) {
                col = 0;
            }
        }
        key = D_800E381C[row][col].ch;
    } while (key == -1);
    D_80153F80[D_800E39C0->sel].type = row;
    D_80153F80[D_800E39C0->sel].id = key;
    func_002A125C(D_80153F80[D_800E39C0->sel].name, *((O3Chr *)D_800E381C)[row * 17 + key].s);
    D_80153F80[D_800E39C0->sel].fC = row;
    func_0041E478(D_800E39C0->sel);
    func_0025DF54(0xE81);
    return 0;
}
