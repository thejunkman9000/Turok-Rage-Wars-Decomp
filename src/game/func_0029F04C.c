#include "b22_types.h"
double func_0029C278(double, double);
float func_0029F04C(float a)
{
    if (a > 25.1327438f || a < -25.1327438f) {
        a = func_0029C278(a, 6.28318596f);
    } else {
        if (a > 6.28318596f) {
            a -= 6.28318596f;
            while (a > 6.28318596f) {
                a -= 6.28318596f;
            }
        }
        if (a < 0.0f) {
            a += 6.28318596f;
            while (a < 0.0f) {
                a += 6.28318596f;
            }
        }
    }
    return a;
}
