#include "b22_types.h"
double func_0029E9DC(double);
inline double Floor_(double x)
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
double func_0029EAA0(double x, double *ip)
{
    *ip = Floor_(x);
    return x - *ip;
}
