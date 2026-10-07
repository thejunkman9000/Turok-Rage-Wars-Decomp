#include "o01_types.h"

s32 func_00403B0C(u8 *bits, s32 bit) {
    s32 i = bit >> 3;
    s32 m = 1 << (bit & 7);
    return bits[i] & m;
}
