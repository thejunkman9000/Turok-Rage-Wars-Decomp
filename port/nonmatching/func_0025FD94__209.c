#include "b14_types.h"
u32 func_002607D8(u32 *pp, u32 n);
extern f32 D_800C9220;
extern f32 D_800C9224;
extern f64 D_800C9228;
extern f32 D_800C9230;
extern f32 D_800C9234;
void func_0025FD94(B14Trk *t) {
    u32 cur;
    s32 n = t->bits;
    u32 span;
    s32 v1, v2, v3, v4;
    f32 fv1, a0, a1, a2, sc, inv, f2, f3, tmp;
    f64 d;
    cur = t->data + t->cur * (n * 4 + 6);
    span = func_002607D8(&cur, 6);
    v1 = func_002607D8(&cur, n);
    v2 = func_002607D8(&cur, n);
    v3 = func_002607D8(&cur, n);
    v4 = func_002607D8(&cur, n);
    fv1 = (f32)v1;
    a1 = (f32)((v2 << 5) - v1 * 21 - v3 * 12 + v4) * D_800C9220;
    a0 = (f32)(v1 * 14 - (v2 << 5) + v3 * 20 - v4 * 2);
    a2 = (f32)((v2 << 6) - v1 * 24 - v3 * 48 + v4 * 8) * D_800C9220;
    if (n != 0) {
        sc = t->range / (f32)((1 << n) - 1);
    } else {
        tmp = t->range * D_800C9224;
        t->range = 0.0f;
        sc = t->range;
        t->base = t->base + tmp;
    }
    fv1 = fv1 * sc;
    if (span >= 2) {
        d = (f64)span;
        if ((s32)span < 0) {
            d += D_800C9228;
        }
        inv = D_800C9230 / ((f32)d - D_800C9230);
    } else {
        inv = D_800C9234;
    }
    f2 = inv * sc;
    f3 = f2 * inv;
    t->span = span;
    t->c1 = a1 * f2;
    t->c0 = fv1 + t->base;
    t->c2 = a0 * f3;
    t->c3 = a2 * (f3 * inv);
}
