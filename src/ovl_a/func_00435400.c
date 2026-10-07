#include "o05_types.h"

extern O05Lobby *D_800E54A4;

s32 func_00435400(s32 a, s32 b) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (r != -1) {
            break;
        }
        if (O05_SLOT(D_800E54A4, i).a == a && O05_SLOT(D_800E54A4, i).b == b) {
            r = i;
        }
    }
    return r;
}
