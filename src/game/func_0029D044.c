#include "b22_types.h"
extern f32 D_800D2B60[];
static inline float Atan(float x)
{
    float a = x;
    float t, u, r;
    if (x < 0.0f) {
        a = -x;
    }
    t = (a - 1.0f) / (a + 1.0f);
    u = t * t;
    r = ((((((((-0.00405405788f * u + 0.0218612291f) * u - 0.055909887f) * u + 0.0964200422f) * u - 0.139085338f) * u + 0.199465364f) * u - 0.333298564f) * u + 0.999999344f) * t) + 0.785398185f;
    if (x < 0.0f) {
        r = -r;
    }
    return r;
}
float func_0029D044(float y, float x)
{
    s32 q;
    float t, r;
    if (-9.99999997e-07f < x) {
        if (x < 9.99999997e-07f) {
            x = 0.0f;
        }
    }
    if (-9.99999997e-07f < y) {
        if (y < 9.99999997e-07f) {
            y = 0.0f;
        }
    }
    if (x == 0.0f && y == 0.0f) {
        return 0.0f;
    }
    if (x == 0.0f) {
        if (0.0f <= y) {
            return 1.57079637f;
        }
        return -1.57079637f;
    }
    if (y == 0.0f) {
        if (0.0f <= x) {
            return 0.0f;
        }
        return 3.14159274f;
    }
    q = 0;
    if (x < 0.0f) {
        q = 1;
    }
    if (y < 0.0f) {
        q |= 2;
    }
    t = y / x;
    r = t;
    if (q != 0 && q != 3) {
        r = -t;
    }
    if (r < 9.99999997e-07f) {
        return D_800D2B60[q];
    }
    return Atan(t) + D_800D2B60[q];
}
