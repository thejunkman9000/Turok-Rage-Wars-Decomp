
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
float func_0029F1D4(float a, float b)
{
    a = a - b + 3.14159274f;
    a = Wrap(a);
    return a - 3.14159274f;
}
