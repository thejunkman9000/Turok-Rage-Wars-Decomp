#include "o05_types.h"

extern O05Lobby *D_800E54A4;
void *func_0041B87C(void *p, s32 idx);

void func_004350D0(s32 idx) {
    u8 c;
    D_800E54A4->h.w2C[idx] = 0;
    func_0041B87C(D_800E54A4->h.f4, idx);
    if (D_800E54A4->plr[idx].name[D_800E54A4->plr[idx].fB44 * 2] == 0) {
        D_800E54A4->plr[idx].name[D_800E54A4->plr[idx].fB44 * 2] = 0x41;
    }
    c = D_800E54A4->plr[idx].name[D_800E54A4->plr[idx].fB44 * 2];
    c--;
    if (c < 0x20) {
        c = 0x5A;
    }
    D_800E54A4->plr[idx].name[D_800E54A4->plr[idx].fB44 * 2] = c;
}
