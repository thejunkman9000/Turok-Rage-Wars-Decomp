#include "o05_types.h"

extern O05Lobby *D_800E54A4;

s32 func_004353C0(void) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (r != -1) {
            break;
        }
        if (O05_SLOT(D_800E54A4, i).a == -1) {
            r = i;
        }
    }
    return r;
}
