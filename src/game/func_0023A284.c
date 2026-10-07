#include "b08_types.h"

s32 func_00264B8C();

extern f32 D_800C868C;
extern f32 D_800C8690;
extern f32 D_80103224;

f32 func_0023A284(s32 unused, f32 x, f32 target, f32 step) {
    if (func_00264B8C() != 0) {
        x = target;
    }
    if (x < target) {
        x += step;
        D_80103224 = D_800C868C;
        if (target < x) {
            x = target;
        }
    } else if (target < x) {
        x -= step;
        D_80103224 = D_800C8690;
        if (x < target) {
            x = target;
        }
    }
    return x;
}
