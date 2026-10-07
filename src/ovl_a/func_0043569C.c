#include "o05_types.h"

extern O05Lobby *D_800E54A4;
void func_002A1724(void *dst, void *src, s32 n);

void func_0043569C(s32 idx) {
    func_002A1724(D_800E54A4->plr[idx].rec, D_800E54A4->recs, 0x640);
    D_800E54A4->plr[idx].fB64 = D_800E54A4->f3468;
}
