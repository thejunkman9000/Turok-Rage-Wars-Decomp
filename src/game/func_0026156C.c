#include "b14_types.h"
extern f32 D_800C9298;
extern f32 D_800C929C;
s32 func_0026156C(f32 x) {
    s32 n = 0;
    f32 t = D_800C929C / (2.0f * x) + D_800C929C;
    if (D_800C9298 <= x) {
        return 0;
    }
    if (D_800C929C < t) {
        do {
            n++;
        } while ((f32)(1 << n) < t);
    }
    return n;
}
