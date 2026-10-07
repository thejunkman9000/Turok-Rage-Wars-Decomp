#include "o05_types.h"


extern O05R150 D_80146410[];
extern O05Lobby *D_800E54A4;

void func_004352A8(s32 i) {
    D_80146410[i].b0 = 1;
    D_800E54A4->plr[i].f14 = 2;
    D_800E54A4->plr[i].state = 2;
}
