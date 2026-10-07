#include "o05_types.h"

extern O05Lobby *D_800E54A4;

s32 func_00435790(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E54A4->plr[i].state != 0) {
            n++;
        }
    }
    return n;
}
