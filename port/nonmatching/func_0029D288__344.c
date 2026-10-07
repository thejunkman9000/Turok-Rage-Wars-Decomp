#include "b22_types.h"
extern f32 D_800CABE8;
extern f32 D_800CABEC;
extern f32 D_800CABF0;
extern f32 D_800CABF4;
extern f32 D_800CABF8;
extern f32 D_800CABFC;
extern f32 D_800CAC00;
extern f32 D_800CAC04;
extern f32 D_800CAC08;
extern f32 D_800CAC0C;
extern f32 D_800CAC10;
static inline float Asin(float x)
{
    s32 neg;
    float p, s;
    if (D_800CABF0 < x) {
        x = D_800CABF0;
    }
    if (x < D_800CABF4) {
        x = D_800CABF4;
    }
    neg = 0;
    if (x < 0.0f) {
        neg = 1;
        x = -x;
    }
    p = ((((D_800CABF8 * x + D_800CABFC) * x - D_800CAC00) * x + D_800CAC04) * x - D_800CAC08) * x + D_800CAC0C;
    x = 1.0f - x;
    if (x <= 0.0f) {
        s = 0.0f;
    } else {
        s = sqrtf(x);
    }
    x = D_800CAC10 - s * p;
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
    if (D_800CABE8 < c) {
        c = D_800CABE8;
    }
    if (c < D_800CABEC) {
        c = D_800CABEC;
    }
    return D_800CAC10 - Asin(c);
}
