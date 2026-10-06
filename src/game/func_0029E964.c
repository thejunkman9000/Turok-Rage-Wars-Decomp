#include "b22_types.h"
double func_0029E9DC(double);
double func_0029E964(double x)
{
    double t;
    if (x >= 4503599627370496.0) {
        return x;
    }
    if (x < 0.0) {
        return -func_0029E9DC(-x);
    }
    t = x + 4503599627370496.0;
    t = t - 4503599627370496.0;
    if (!(x < t)) {
        return t;
    }
    return t - 1.0;
}
