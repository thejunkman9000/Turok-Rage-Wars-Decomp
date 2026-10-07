#include "o05_types.h"
extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];
extern O05GameState D_801462C8[];
void func_002A1724(void *dst, void *src, s32 n);

void func_00434CE4(s32 k) {
    s32 sz = 0x190;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].bE == 0 && D_80102B00[i].bD == k && D_801462C8->rec[i].b0 == 1 && D_801462C8->rec[i].b19 == 0) {
            func_002A1724(&D_800E54A4->plr[k].rec[D_80102B00[i].bC], &D_80102B00[i], sz);
        }
    }
}
