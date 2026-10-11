#include "common.h"

f64 libm_frexp(f64 x, s32 *ex) {
    f64 a;
    *ex = 0;
    if (x == 0.0) { return x; }
    a = __builtin_fabs(x);
    if (a >= 1.0) { do { a *= 0.5; (*ex)++; } while (a >= 1.0); }
    if (a < 0.5) { do { a += a; (*ex)--; } while (a < 0.5); }
    return (x > 0.0) ? a : -a;
}
