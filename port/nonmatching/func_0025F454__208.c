#include "b14_types.h"
extern f32 D_800C91FC;
extern f32 D_800C9200;
extern f32 D_800C9204;
extern f32 D_800C9208;
extern f32 D_800D0DA0;
static inline f32 b14_ceil(f32 x) {
    s32 n;
    f32 r;
    if (x <= 0.0f) {
        n = (s32)x;
        r = (f32)n;
    } else {
        n = (s32)x;
        r = (f32)n;
        if (r != x) {
            n = n + 1;
            r = (f32)n;
        }
    }
    return r;
}
f32 func_0025F454(f32 a, f32 b) {
    f32 r;
    if (a == D_800C91FC) {
        return D_800C91FC;
    }
    if (b <= D_800C9200) {
        return D_800C91FC;
    }
    r = b14_ceil(a / b * D_800C9204);
    if (r < D_800D0DA0) {
        return r;
    }
    r = b14_ceil(a / b * D_800C9208);
    if (!(r < D_800D0DA0)) {
        r = a;
    }
    return r;
}
