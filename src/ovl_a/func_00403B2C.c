#include "o01_types.h"

void func_00403B2C(u8 *bits, s32 bit, s32 set) {
    s32 i = bit >> 3;
    s32 m = 1 << (bit & 7);
    u8 *b2 = bits;
    if (set != 0) {
        bits[i] |= m;
    } else {
        b2[i] &= ~m;
    }
}
