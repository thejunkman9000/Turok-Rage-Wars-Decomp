
#include "b22_types.h"
static inline double Frexp(double x, s32 *e, double zero)
{
    union { double d; u32 w[2]; } u;
    register double r asm("$f4");
    if (x != zero) {
        u.d = x;
        *e = ((u.w[0] >> 20) & 0x7FF) - 0x3FE;
        u.w[0] = (u.w[0] & 0x800FFFFF) | 0x3FE00000;
        r = u.d;
    } else {
        *e = 0;
        r = zero;
    }
    return r;
}
double func_0029BD38(double x)
{
    s32 e;
    double f, y, z, w, p, q, r;
    register double zero asm("$f1") = 0.0;
    if (zero >= x) {
        return -1.0 / 0.0;
    }
    f = Frexp(x, &e, zero);
    if (f > 0.7071067690849304) {
        y = f * 0.5;
        f = f - 0.5;
        f = f - 0.5;
        y = y + 0.5;
    } else {
        f = f - 0.5;
        y = f * 0.5;
        e--;
        y = y + 0.5;
    }
    z = f / y;
    w = z * z;
    p = (w * -0.7895611524581909 + 16.383943557739258) * w - 64.12494659423828;
    q = ((w - 35.66797637939453) * w + 312.0322265625) * w - 769.4993286132812;
    r = z * (w * p / q);
    return e * -0.00021219444170128557 + (z + r) + e * 0.693359375;
}



