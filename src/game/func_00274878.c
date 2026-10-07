#include "b17_types.h"

extern f32 D_800D2988;

f32 func_00274878(f32 x, f32 lim, f32 d) {
    if (x < lim) {
        x += d * D_800D2988;
        if (lim < x) {
            x = lim;
        }
    } else if (lim < x) {
        x -= d * D_800D2988;
        if (x < lim) {
            x = lim;
        }
    }
    return x;
}
