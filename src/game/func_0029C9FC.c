#include "b22_types.h"
double func_0029C278(double, double);
static inline float Wrap(float a)
{
    if (a > 25.1327438f || a < -25.1327438f) {
        a = func_0029C278(a, 6.28318596f);
    } else {
        while (a > 6.28318596f) {
            a -= 6.28318596f;
        }
        while (a < 0.0f) {
            a += 6.28318596f;
        }
    }
    return a;
}
float func_0029C9FC(float x)
{
    s32 sign = 1;
    float r;
    float z;
    Wrap(x);
    if (x < -1.57079637f) {
        x += 6.28318548f;
        while (x < -1.57079637f) {
            x += 6.28318548f;
        }
    }
    if (x > 4.71238899f) {
        x -= 6.28318548f;
        while (x > 4.71238899f) {
            x -= 6.28318548f;
        }
    }
    if (x > 1.57079637f) {
        sign = -1;
        x -= 3.14159274f;
    }
    z = x * x;
    r = (((z * 2.75573188e-06f - 0.000198412701f) * z + 0.00833333377f) * z - 0.166666672f) * z * x + x;
    if (sign < 0) {
        r = -r;
    }
    return r;
}
