#include "b17_types.h"

extern f32 D_800C9A50;
extern f32 D_800D2988;

f32 func_00274710(f32 x, f32 v, f32 lim) {
    f32 t;

    if (v < 0.0f) {
        if (x <= -lim) {
            return x;
        }
    }
    if (v > 0.0f && lim <= x) {
        return x;
    }
    if ((x < 0.0f && v > 0.0f) || (x > 0.0f && v < 0.0f)) {
        v *= D_800C9A50;
    }
    x += v * D_800D2988;
    if (v < 0.0f) {
        t = -lim;
        if (x < t) {
            x = t;
        }
    } else {
        if (lim < x) {
            x = lim;
        }
    }
    return x;
}
