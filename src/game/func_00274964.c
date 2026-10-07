#include "b17_types.h"

extern f32 D_800D2988;

s32 func_00274964(s32 a, s32 b, s32 lim) {
    f32 fb = (f32)b;

    a += (s32)(fb * D_800D2988);
    if (fb < 0.0f) {
        lim = -lim;
        if (a < lim) {
            a = lim;
        }
    } else if (lim < a) {
        a = lim;
    }
    return a;
}
