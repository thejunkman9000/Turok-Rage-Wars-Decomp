#include "b13_types.h"

extern f32 D_800C9084;
extern f32 D_800C9088;

f32 func_002745D4(f32 a);

f32 func_0025C30C(u8 a, u8 b) {
    f32 x = a * D_800C9084;
    f32 y = b * D_800C9084;
    if (x == D_800C9088) {
        return D_800C9088;
    }
    if (y == x) {
        return x;
    }
    return x + func_002745D4(y - x);
}
