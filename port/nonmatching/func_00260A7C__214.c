#include "b14_types.h"
static inline u32 *b14_ptr(u32 a) { return (u32 *)((a & 0xF0000000) | ((a & 0x0FFFFFE0) >> 3)); }
static inline u32 b14_ofs(u32 a) { return a & 0x1F; }
extern const f32 D_800C9268;
void func_00260A7C(u32 addr, B14FRange r, f32 v) {
    f32 f;
    s32 t;
    u32 q;
    u32 mhi;
    u32 mlo;
    u32 lo;
    u32 hi;
    u32 sh;
    u32 *p;
    f = (v - r.min) / r.range * (f32)((1 << r.n) - 1) + D_800C9268;
    if (f >= 0.0f) {
        q = (s32)f;
    } else {
        t = (s32)f;
        q = t - ((f32)t != f);
    }
    mhi = (1 << r.n) - 1;
    mlo = mhi;
    sh = b14_ofs(addr);
    q &= mhi;
    if (sh == 0) {
        lo = q;
        hi = mhi = 0;
    } else {
        mlo = mhi << sh;
        mhi >>= 32 - sh;
        lo = q << sh;
        hi = q >> (32 - sh);
    }
    p = b14_ptr(addr);
    p[0] = (p[0] & ~mlo) | lo;
    p[1] = (p[1] & ~mhi) | hi;
}
