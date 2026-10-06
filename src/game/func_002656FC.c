#include "b14_types.h"
void func_002656FC(u8 *p, s32 bit) {
    s32 i = bit / 8;
    s32 m = 1 << (bit - i * 8);
    p[i] ^= m;
}
