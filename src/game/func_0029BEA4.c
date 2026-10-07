#include "b22_types.h"
double func_0029BBA0(double, s32);
double func_0029BD38(double);
static inline double Exp_(double x)
{
    double y, g, px, q;
    s32 n;
    if (-2.7105049465376212e-20 < x && x < 2.7105049465376212e-20) {
        return 1.0;
    }
    y = x * 1.4426950216293335;
    n = (s32)y;
    if (n < 0) {
        n--;
    }
    if (0.5 <= y - n) {
        n++;
    }
    g = (x - n * 0.693359375) + n * 0.00021219444170128557;
    y = g * g;
    px = ((y * 1.652032915444579e-05 + 0.006943599786609411) * y + 0.25) * g;
    q = (y * 0.00049586285604164 + 0.0555538684129715) * y + 0.5;
    return func_0029BBA0(0.5 + px / (q - px), n + 1);
}
double func_0029BEA4(double x, double y)
{
    double w, d;
    s32 i, k;
    if (y == 0.0) {
        return 1.0;
    }
    if (x == 0.0) {
        if (y < 0.0) {
            return 1.0 / 0.0;
        }
        return 0.0;
    }
    if (x < 0.0) {
        i = (s32)y;
        if ((double)i == y) {
            w = func_0029BD38(-x) * y;
            if (i & 1) {
                return -Exp_(w);
            }
            return Exp_(w);
        }
        i = (s32)(1.0 / y);
        d = y - (double)i * y;
        if (!(-2.7105049465376212e-20 < d && d < 2.7105049465376212e-20 && (i & 1))) {
            return -1.0 / 0.0;
        }
        w = func_0029BD38(-x) * y;
        return -Exp_(w);
    }
    w = func_0029BD38(x) * y;
    return Exp_(w);
}
