#include "common.h"

f64 libm_ldexp(f64 x, s32 n) {
    if (n != 0) { x *= (f64)(1 << n); }
    return x;
}
