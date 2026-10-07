#include "o05_types.h"

extern O05Lobby *D_800E54A4;

s32 func_00435750(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 st = D_800E54A4->plr[i].state;
        if (st != 0 && st != 17) {
            n++;
        }
    }
    return n;
}
