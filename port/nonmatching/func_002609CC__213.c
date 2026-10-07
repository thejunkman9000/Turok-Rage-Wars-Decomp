#include "b14_types.h"
f32 func_002609CC(u32 addr, B14FRange r) {
    u32 *p = (u32 *)((addr & 0xF0000000) | ((addr & 0x0FFFFFE0) >> 3));
    u32 sh = addr & 0x1F;
    u32 v = p[0];
    u32 hi = p[1];
    if (sh != 0) {
        v >>= sh;
        hi <<= 32 - sh;
        v |= hi;
    }
    if (r.n < 32) {
        v &= (1 << r.n) - 1;
    }
    return (f32)v / (f32)((1 << r.n) - 1) * r.range + r.min;
}
