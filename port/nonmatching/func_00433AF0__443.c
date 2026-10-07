#include "o05_types.h"

typedef struct O05Ch { u8 pad[0x30]; struct O05Ch *f30; } O05Ch;
extern O05Lobby *D_800E54A4;
extern void *D_800D727C;
O05ItemWd *func_0040ECB0(void *w, s32 id);
void func_0040E9D0(void *w, s32 a);
void func_0040E958(void *w, s32 a);
s32 func_00435A9C(s32 a, s32 b);
O05Ch *func_0041B87C(void *p, s32 idx);
s32 func_0040EC50(O05Ch *c);
void func_0041B95C(void *p, s32 idx, O05Ch *c);

void func_00433AF0(s32 k) {
    s32 i;
    O05ItemWd *c1;
    O05ItemWd *c2;
    O05Ch *s;
    D_800E54A4->plr[k].fAEC = 0;
    D_800E54A4->plr[k].wdB00[0] = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2B6);
    D_800E54A4->plr[k].wdB00[1] = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2B3);
    D_800E54A4->plr[k].wdB00[2] = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2B0);
    D_800E54A4->plr[k].wdB00[3] = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2B4);
    for (i = 0; i < 4; i++) {
        D_800E54A4->plr[k].tabAF0[i] = 2;
        D_800E54A4->plr[k].wdB00[i]->b10 = 0xFF;
        c1 = func_0040ECB0(D_800E54A4->plr[k].wdB00[i], 0x2B1);
        func_0040E9D0(D_800E54A4->plr[k].wdB00[i], 0);
        c2 = func_0040ECB0(D_800E54A4->plr[k].wdB00[i], 0x2B2);
        if (D_800E54A4->plr[k].rec[i].bD != -1) {
            c2->f38 = &D_800E54A4->plr[k].rec[i];
            D_800E54A4->plr[k].tabAF0[i] = 1;
            if (D_800E54A4->h.f54 == 1) {
                func_0040E958(func_0040ECB0(D_800E54A4->plr[k].wdB00[i], 0x2B1), 0);
                if (func_00435A9C(D_800E54A4->plr[k].fB64, D_800E54A4->plr[k].rec[i].bC) != -1) {
                    D_800E54A4->plr[k].tabAF0[i] = 0;
                    func_0040E9D0(D_800E54A4->plr[k].wdB00[i], 1);
                    func_0040E958(func_0040ECB0(D_800E54A4->plr[k].wdB00[i], 0x2B1), 1);
                }
            }
        } else {
            c2->f38 = D_800D727C;
            func_0040E958(c1, 0);
        }
    }
    s = func_0041B87C(D_800E54A4->h.f4, k);
    while (func_0040EC50(s) != 0) {
        s = s->f30;
    }
    func_0041B95C(D_800E54A4->h.f4, k, s);
}
