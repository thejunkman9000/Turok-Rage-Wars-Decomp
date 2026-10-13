#include "veu3n10_types.h"

extern s32 D_801462CC;

/* next unlocked entry (bit 16..26 of the unlock word) in direction step, -1 if none */
s32 func_auto_0043DE74(s32 idx, s32 step, s32 stay) {
    s32 n;
    u32 mask;
    for (n = 0; n < 11; n++) {
        if (stay == 0) {
            idx += step;
            if (idx >= 11) idx = 0;
            else if (idx < 0) idx = 10;
        }
        switch (idx) {
        default:
        case 0: mask = 0x10000; break;
        case 1: mask = 0x20000; break;
        case 2: mask = 0x40000; break;
        case 3: mask = 0x80000; break;
        case 4: mask = 0x100000; break;
        case 5: mask = 0x200000; break;
        case 6: mask = 0x800000; break;
        case 7: mask = 0x400000; break;
        case 8: mask = 0x1000000; break;
        case 9: mask = 0x2000000; break;
        case 10: mask = 0x4000000; break;
        }
        { s32 *fl = &D_801462CC;
        if (*fl & mask) return idx; }
        if (stay != 0) {
            idx += step;
            if (idx >= 11) idx = 0;
            else if (idx < 0) idx = 10;
        }
    }
    return -1;
}
