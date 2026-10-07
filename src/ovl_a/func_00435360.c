#include "o05_types.h"

extern O05Lobby *D_800E54A4;

s32 func_00435360(s32 idx) {
    s32 r = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (r != 1) {
            break;
        }
        if (D_800E54A4->plr[idx].rec[i].bD != -1) {
            r = 0;
        }
    }
    return r;
}
