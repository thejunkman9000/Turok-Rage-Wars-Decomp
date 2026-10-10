#include "b22_types.h"
extern const f32 D_800CABE8;
extern const f32 D_800CABEC;
extern const f32 D_800CABF0;
extern const f32 D_800CABF4;
static inline float Sq(float x)
{
    float r;
    if (x <= 0.0f) {
        r = 0.0f;
    } else {
        r = sqrtf(x);
    }
    return r;
}
static inline float Asin(float x)
{
    s32 neg;
    float y;
    float p, s, zero;
    __asm__("" : "+f"(x));
    if (D_800CABF0 < x) {
        x = D_800CABF0;
    }
    if (x < D_800CABF4) {
        x = D_800CABF4;
    }
    zero = 0.0f;
    __asm__ volatile("" : "+f"(zero));
    neg = 0;
    if (x < zero) {
        neg = 1;
        x = -x;
    }
    p = ((((-0.0116805276f * x + 0.0308918804f) * x - 0.0501743034f) * x + 0.0889789909f) * x - 0.214598805f) * x + 1.57079625f;
    x = D_800CABF0 - x;
    if (x <= zero) {
        s = zero;
    } else {
        s = sqrtf(x);
    }
    y = 1.57079637f - s * p;
    if (neg) {
        y = -y;
    }
    return y;
}
float func_0029D288(Vec3f *a, Vec3f *b)
{
    float la, lb, prod, c;
    la = Sq(a->x * a->x + a->y * a->y + a->z * a->z);
    lb = Sq(b->x * b->x + b->y * b->y + b->z * b->z);
    prod = la * lb;
    if (prod == 0.0f) {
        return 0.0f;
    }
    c = (a->x * b->x + a->y * b->y + a->z * b->z) / prod;
    if (D_800CABE8 < c) {
        c = D_800CABE8;
    } else if (c < D_800CABEC) {
        c = D_800CABEC;
    }
    return 1.57079637f - Asin(c);
}
