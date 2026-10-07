#include "b17_types.h"
extern f32 D_800D2988;
f32 func_00274810(f32 x, f32 d) {
    if (x > 0.0f) {
        x -= d * D_800D2988;
        if (x < 0.0f) {
            x = 0.0f;
        }
    } else if (x < 0.0f) {
        x += d * D_800D2988;
        if (x > 0.0f) {
            x = 0.0f;
        }
    }
    return x;
}
