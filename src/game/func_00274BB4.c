#include "p3_types.h"

extern f32 D_800D2988;

s32 func_00274BB4(f32 *p) {
    *p -= D_800D2988;
    if (*p <= 0.0f) {
        *p = 0.0f;
        return 1;
    }
    return 0;
}
