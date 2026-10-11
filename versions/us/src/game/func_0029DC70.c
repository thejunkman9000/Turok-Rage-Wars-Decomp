#include "b22_types.h"
static inline float Asin(float x)
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
    x = 1.57079637f - s * p;
    if (neg) {
        x = -x;
    }
    return x;
}
float func_0029C9FC(float);
float func_0029D044(float, float);
void func_0029DC70(float *m, Vec3f *out)
{
    float t, a, c, e1, e2;
    t = m[2];
    if (1.0f < t) {
        t = 1.0f;
    }
    if (t < -1.0f) {
        t = -1.0f;
    }
    a = Asin(-t);
    c = func_0029C9FC(a + 1.57079637f);
    if (0.0f < c || c < 0.0f) {
        e1 = func_0029D044(m[6], m[10]);
        e2 = func_0029D044(m[1], m[0]);
    } else {
        e1 = func_0029D044(-m[9], m[5]);
        e2 = 0.0f;
    }
    out->x = e1;
    out->y = a;
    out->z = e2;
}

