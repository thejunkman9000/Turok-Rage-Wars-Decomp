#include "o05_types.h"

extern O05Lobby *D_800E54A4;

s32 func_0043492C(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 st = D_800E54A4->plr[i].state;
        if (st != 0 && st != 17 && st != 14) {
            return -1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_800E54A4->plr[i].state == 14) {
            return i;
        }
    }
    return -1;
}
