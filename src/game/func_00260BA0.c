#include "b14_types.h"
typedef struct { u32 pad; B14FRange r; } B14Tmp;
f32 func_00260BA0(u32 *pp, B14FRange r) {
    B14Tmp l;
    u32 addr = *pp;
    u32 *p;
    u32 sh;
    u32 v;
    u32 hi;
    u32 n;
    f32 res;
    l.r = r;
    n = l.r.n;
    p = (u32 *)((addr & 0xF0000000) | ((addr & 0x0FFFFFE0) >> 3));
    sh = addr & 0x1F;
    v = p[0];
    hi = p[1];
    if (sh != 0) {
        v >>= sh;
        hi <<= 32 - sh;
        v |= hi;
    }
    if (n < 32) {
        v &= (1 << n) - 1;
    }
    res = (f32)v / (f32)((1 << n) - 1) * l.r.range + l.r.min;
    *pp += r.n;
    return res;
}
