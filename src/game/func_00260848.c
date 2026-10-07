#include "b14_types.h"
static inline u32 *b14_ptr(u32 a) { return (u32 *)((a & 0xF0000000) | ((a & 0x0FFFFFE0) >> 3)); }
static inline u32 b14_ofs(u32 a) { return a & 0x1F; }


void func_00260848(u32 *pp, s32 n, u32 val) {
u32 mhi = (1 << n) - 1;
    u32 mlo = mhi;
    u32 lo, hi;
    u32 sh;
    u32 *p;
    u32 addr = *pp;
    sh = b14_ofs(addr);
    val &= mhi;
    if (sh == 0) {
        lo = val;
        hi = mhi = 0;
    } else {
        mlo = mhi << sh;
        mhi >>= 32 - sh;
        lo = val << sh;
        hi = val >> (32 - sh);
    }
    p = b14_ptr(addr);
    p[0] = (p[0] & ~mlo) | lo;
    p[1] = (p[1] & ~mhi) | hi;
    *pp += n;
}
