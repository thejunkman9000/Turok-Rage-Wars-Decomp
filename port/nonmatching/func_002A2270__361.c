
#include "b23_types.h"
extern MinMaxF D_800D2BDC;
extern MinMaxF D_800D2BE8;
extern MinMaxF D_800D2BF4;
extern f32 D_800CAF00;
extern f32 D_800CAF04;
extern s32 D_8014D2D0;
extern s32 D_8014D2D4;
extern s32 D_8014D2E0;
extern s32 D_8014D320;
extern s32 D_8014D324;
extern s32 D_8014D328;
extern s32 D_800D2BD4[];

#define MM_SET(m, value, lim0, lim1) \
    (m).cur = (value); \
    if ((m).cur < (lim0)) { \
        (m).cur = (lim0); \
    } \
    if ((m).cur > (lim1)) { \
        (m).cur = (lim1); \
    } \
    if ((m).cur < (m).lo) { \
        (m).lo = (m).cur; \
    } \
    if ((m).hi < (m).cur) { \
        (m).hi = (m).cur; \
    }
#define MM_RANGE(m) \
    if ((m).cur < (m).lo) { \
        (m).lo = (m).cur; \
    } \
    if ((m).hi < (m).cur) { \
        (m).hi = (m).cur; \
    }

void func_002A2270(void) {
    s32 v, w;
    f32 cur, t;
    D_8014D320 = 0;
    cur = (f32)D_8014D2D4;
    v = D_800D2BD4[D_8014D2D0];
    D_800D2BDC.cur = cur;
    D_8014D2E0 = D_8014D328 = v;
    D_8014D324 = v + D_8014D2D4;
    if (cur < D_800CAF00) {
        D_800D2BDC.cur = D_800CAF00;
    }
    if (D_800D2BDC.cur > D_800CAF04) {
        D_800D2BDC.cur = D_800CAF04;
    }
    MM_RANGE(D_800D2BDC)
    D_800D2BE8.cur = 0;
    MM_RANGE(D_800D2BE8)
    D_800D2BF4.cur = D_800D2BE8.cur;
    MM_RANGE(D_800D2BF4)
}

