#include "b14_types.h"
s32 func_00265670(u8 *p, s32 bit) {
    s32 i = bit / 8;
    s32 m = 1 << (bit - i * 8);
    u32 v = p[i] & m;
    return v != 0;
}
