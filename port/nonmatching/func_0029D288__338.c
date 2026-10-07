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
float func_0029D288(Vec3f *a, Vec3f *b)
{
    float la, lb, prod, c;
    la = B22Sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
    lb = B22Sqrt(b->x * b->x + b->y * b->y + b->z * b->z);
    prod = la * lb;
    if (prod == 0.0f) {
        return 0.0f;
    }
    c = (a->x * b->x + a->y * b->y + a->z * b->z) / prod;
    if (1.0f < c) {
        c = 1.0f;
    }
    if (c < -1.0f) {
        c = -1.0f;
    }
    return 1.57079637f - Asin(c);
}
