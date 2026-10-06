#include "b17_types.h"

extern f32 D_800C9A3C;
extern f32 D_800C9A40;
extern f32 D_800C9A44;
extern f32 D_800C9A48;
extern f32 D_800C9A4C;
extern f32 D_800D162C[];
extern f32 D_800D1630[];
extern f32 D_800D2628;

f32 func_00274640(f32 x) {
    s32 neg, i;
    f32 fx, fi, a, r;

    if (x < 0.0f) {
        neg = 1;
        fx = x * D_800C9A3C;
    } else {
        neg = 0;
        fx = x * D_800C9A40;
    }
    i = (s32)fx;
    fi = (f32)i;
    if (fi < D_800C9A44) {
        a = D_800D162C[i];
        r = a + (fx - fi) * (D_800D1630[i] - a);
        if (neg) {
            return D_800C9A48 - r;
        }
        return r;
    }
    if (neg) {
        f32 t = D_800D2628;
        return D_800C9A4C - t;
    }
    return D_800D2628;
}
