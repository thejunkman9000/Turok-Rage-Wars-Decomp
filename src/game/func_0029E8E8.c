#include "b22_types.h"
float sqrtf(float);
float func_0029E8E8(float x)
{
    float r;
    if (x <= 0.0f) {
        r = 0.0f;
    } else {
        r = sqrtf(x);
    }
    return 1.0f / r;
}
