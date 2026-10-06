
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
void func_0029CBB0(f32 a, f32 *sp, f32 *cp)
{
    f32 s, c, z1, z2;
    a = Wrap(a);
    while (a < 0.0f) {
        a += 6.28318548f;
    }
    while (a >= 6.28318548f) {
        a -= 6.28318548f;
    }
    if (a >= 3.14159298f) {
        if (a >= 4.71238947f) {
            a -= 4.71238947f;
            s = a - 1.57079649f;
            c = a;
        } else {
            a -= 3.14159298f;
            s = -a;
            c = a - 1.57079649f;
        }
    } else {
        if (a >= 1.57079649f) {
            a = a - 1.57079649f;
            s = 1.57079649f - a;
            c = -a;
        } else {
            s = a;
            c = 1.57079649f - a;
        }
    }
    z1 = s * s;
    z2 = c * c;
    *sp = ((((z1 * 2.75573188e-06f - 0.000198412701f) * z1 + 0.00833333377f) * z1 - 0.166666672f) * z1 + 1.0f) * s;
    *cp = ((((z2 * 2.75573188e-06f - 0.000198412701f) * z2 + 0.00833333377f) * z2 - 0.166666672f) * z2 + 1.0f) * c;
}

