#include "o05_types.h"
extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];
void func_002A1724(void *dst, void *src, s32 n);
void func_00435898(s32 k) {
    s32 a = D_800E54A4->slot[k].a;
    s32 b = D_800E54A4->slot[k].b;
    O05Rec *rec = &D_80102B00[k];
    if (a != -1) {
        func_002A1724(rec, &D_800E54A4->plr[a].rec[b], 0x190);
        rec->bC = b;
    }
    rec->bD = a;
}
