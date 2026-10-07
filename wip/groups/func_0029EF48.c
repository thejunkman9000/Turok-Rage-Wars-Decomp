#include "b22_types.h"
inline float func_0029EE48(float x)
{
    s32 neg;
    float p, s;
    if (1.0f < x) {
        x = 1.0f;
    }
    if (x < -1.0f) {
        x = -1.0f;
    }
    neg = 0;
    if (x < 0.0f) {
        neg = 1;
        x = -x;
    }
    p = ((((-0.0116805276f * x + 0.0308918804f) * x - 0.0501743034f) * x + 0.0889789909f) * x - 0.214598805f) * x + 1.57079625f;
    x = 1.0f - x;
    if (x <= 0.0f) {
        s = 0.0f;
    } else {
        s = sqrtf(x);
    }
    s = 1.57079637f - s * p;
    if (neg) {
        s = -s;
    }
    return s;
}
float func_0029EF48(float x)
{
    return 1.57079637f - func_0029EE48(x);
}
