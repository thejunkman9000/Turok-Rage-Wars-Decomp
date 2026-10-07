#include "b22_types.h"
double func_0029E9DC(double);
static inline double Floor_(double x)
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
    if (x < t) {
        return t - 1.0;
    }
    return t;
}
static inline double Ceil_(double x)
{
    double t;
    if (x >= 4503599627370496.0) {
        return x;
    }
    if (x < 0.0) {
        return -Floor_(-x);
    }
    t = x + 4503599627370496.0;
    t = t - 4503599627370496.0;
    if (t < x) {
        return t + 1.0;
    }
    return t;
}
double func_0029C278(double x, double y)
{
    double q = x / y;
    q = (q < 0.0) ? Ceil_(q) : Floor_(q);
    return x - q * y;
}

