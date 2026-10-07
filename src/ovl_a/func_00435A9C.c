#include "o05_types.h"

extern O05Rec D_80102B00[];

s32 func_00435A9C(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].bC == b && D_80102B00[i].w8 == a) {
            return i;
        }
    }
    return -1;
}
