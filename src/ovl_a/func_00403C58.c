#include "o01_types.h"

extern f32 D_800E0CB0;

f32 func_00403C58(f32 a, f32 b, f32 t) {
    f32 u = D_800E0CB0 - t;
    return a * (u * u * u - u) + b * (t * t * t - t);
}
