#include "b14_types.h"
typedef struct { u32 addr; u32 bits; } B14BitArr;
s32 func_00260E6C(B14BitArr *a, s32 idx) {
    u32 bits = a->bits;
    u32 addr = a->addr + bits * idx;
    u32 *p = (u32 *)((addr & 0xF0000000) | ((addr & 0x0FFFFFE0) >> 3));
    u32 sh = addr & 0x1F;
    u32 v = p[0];
    u32 hi = p[1];
    if (sh != 0) {
        v >>= sh;
        hi <<= 32 - sh;
        v |= hi;
    }
    if (bits < 32) {
        v &= (1 << bits) - 1;
    }
    return v | (-1 << bits);
}
