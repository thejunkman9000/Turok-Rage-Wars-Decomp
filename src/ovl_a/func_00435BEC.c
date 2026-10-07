#include "o05_types.h"

extern O05Lobby *D_800E54A4;

s32 func_00435BEC(s32 a, s32 b, u32 c, s32 d) {
    s32 idx = c & 0xFFFF;
    if (D_800E54A4->plr[idx].state == 12) {
        if ((c >> 16) == 3) {
            if (d < 6) {
                if (d >= 4) {
                    D_800E54A4->plr[idx].fB4C = 0;
                    D_800E54A4->plr[idx].fB48 = 2;
                }
            }
        }
    }
    return 0;
}
