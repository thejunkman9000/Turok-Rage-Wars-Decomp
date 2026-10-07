#include "b13_types.h"

f32 func_00274B00(f32 a, f32 b);

s16 func_0025C27C(s16 a, s16 b) {
    f32 x = (f32)a;
    f32 y = (f32)b;
    return (s16)(s32)(func_00274B00(y, x) < 0.0f ? x - func_00274B00(y, x) : x + func_00274B00(y, x));
}
