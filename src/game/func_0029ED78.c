#include "b22_types.h"
float func_0029ED78(float x)
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
