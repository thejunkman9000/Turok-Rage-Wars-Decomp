#include "o05_types.h"

extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];

s32 func_00435AE8(s32 idx) {
    s32 r = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].bE == 0 && D_80102B00[i].bD == idx) {
            if (D_80102B00[i].w8 != D_800E54A4->plr[idx].fB64) {
                r = 0;
            }
        }
    }
    return r;
}
