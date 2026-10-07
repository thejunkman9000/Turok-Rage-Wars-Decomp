#include "o05_types.h"

extern O05Lobby *D_800E54A4;
void func_002A1724(void *dst, void *src, s32 n);
s32 func_004057F8(void *p, s32 a, s32 b);

void func_00435608(s32 idx) {
    O05Rec *buf = D_800E54A4->recs;
    func_002A1724(buf, D_800E54A4->plr[idx].rec, 0x640);
    D_800E54A4->f3468 = D_800E54A4->plr[idx].fB64;
    D_800E54A4->f346C = func_004057F8(buf, 0x640, 7);
}
