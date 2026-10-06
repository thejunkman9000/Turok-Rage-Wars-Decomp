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
void func_0029DAB4(float *m, Vec3f *out)
{
    float t, a, c, e1, e2;
    t = m[9];
    if (1.0f < t) {
        t = 1.0f;
    }
    if (t < -1.0f) {
        t = -1.0f;
    }
    c = func_0029C9FC((a = Asin(-t)) + 1.57079637f);
    if (9.99999975e-05f < c || c < 9.99999975e-05f) {
        e1 = func_0029D044(m[8], m[10]);
        e2 = func_0029D044(m[1], m[5]);
    } else {
        e1 = 0.0f;
        e2 = func_0029D044(m[2], m[0]);
    }
    out->x = a;
    out->y = e1;
    out->z = e2;
}



