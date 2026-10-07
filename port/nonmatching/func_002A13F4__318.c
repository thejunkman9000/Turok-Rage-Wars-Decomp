#include "p4_types.h"
s32 func_002A13F4(const u8 *a, const u8 *b);
/* 2 words differ (branch order beqz c2 / beq c2,c1 comes out as bne c1,c2 / bnez c1) */
s32 func_002A13F4(const u8 *a, const u8 *b) {
    s32 c1, c2;
    c2 = *b++;
    if (c2 > 0x40) { if (c2 < 0x5B) c2 += 0x20; }
    c1 = *a++;
    if (c1 > 0x40) { if (c1 < 0x5B) c1 += 0x20; }
    if (c1 == c2 && c2 != 0) return func_002A13F4(a, b);
    return c1 - c2;
}
