
#include "b22_types.h"
double func_0029ECB0(double x, s32 *e)
{
    union { double d; u32 w[2]; } u;
    double r;
    if (x == 0.0) {
        *e = 0;
        r = 0.0;
    } else {
        u.d = x;
        *e = ((u.w[0] >> 20) & 0x7FF) - 0x3FE;
        u.w[0] = (u.w[0] & 0x800FFFFF) | 0x3FE00000;
        r = u.d;
    }
    return r;
}
