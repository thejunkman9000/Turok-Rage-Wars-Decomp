#include "b14_types.h"
void func_002656A8(u8 *p, s32 bit, s32 set) {
    s32 i = bit / 8;
    s32 m = 1 << (bit - i * 8);
    if (set != 0) {
        p[i] |= m;
    } else {
        p[i] &= ~m;
    }
}
