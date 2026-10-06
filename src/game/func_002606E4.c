#include "b14_types.h"
u32 func_002606E4(u32 addr, u32 n) {
    u32 *p = (u32 *)((addr & 0xF0000000) | ((addr & 0x0FFFFFE0) >> 3));
    u32 sh = addr & 0x1F;
    u32 v = p[0];
    u32 hi = p[1];
    if (sh != 0) {
        v >>= sh;
        hi <<= 32 - sh;
        v |= hi;
    }
    if (n < 32) {
        v &= (1 << n) - 1;
    }
    return v;
}
