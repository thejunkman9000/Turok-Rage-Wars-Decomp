#include "o05_types.h"

extern O05Lobby *D_800E54A4;
void func_0041B834(void *p, s32 a, s32 b);
void func_00432488(s32 a);
void func_00433F14(s32 a);

void func_00434F4C(s32 idx) {
    s32 pl = D_800E54A4->slot[0].a;
    func_0041B834(D_800E54A4->h.f4, pl, 0);
    D_800E54A4->plr[idx].state = 17;
    D_800E54A4->plr[idx].fB30 = 0;
    D_800E54A4->plr[pl].f14 = 2;
    D_800E54A4->plr[pl].state = 2;
    D_800E54A4->plr[pl].f8 = 13;
    D_800E54A4->plr[pl].f4 = 3;
    func_00432488(pl);
    func_00433F14(-1);
}
