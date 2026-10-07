#include "b16_types.h"
f32 sinf(f32 x);
f32 func_00274640(f32 x);
f32 func_802BC380(f32 x);

void func_00270D40(B16Vec4 *dst, f32 t, B16Vec4 *q1, B16Vec4 *q2) {
    B16Vec4 neg;
    f32 d1, d2;
    neg = *q2;
    neg.x = -neg.x;
    neg.y = -neg.y;
    neg.z = -neg.z;
    neg.w = -neg.w;
    d1 = q1->x * q2->x + q1->y * q2->y + q1->z * q2->z + q1->w * q2->w;
    d2 = q1->x * neg.x + q1->y * neg.y + q1->z * neg.z + q1->w * neg.w;
    if (d1 < d2) {
        d1 = d2;
        q2 = &neg;
    }
    if (d1 > 0.70710678f) {
        f32 len;
        f32 inv;
        dst->x = q1->x + t * (q2->x - q1->x);
        dst->y = q1->y + t * (q2->y - q1->y);
        dst->z = q1->z + t * (q2->z - q1->z);
        dst->w = q1->w + t * (q2->w - q1->w);
        len = func_802BC380(dst->x * dst->x + dst->y * dst->y + dst->z * dst->z + dst->w * dst->w);
        if (len != 0.0f) {
            inv = 1.0f / len;
            dst->x *= inv;
            dst->y *= inv;
            dst->z *= inv;
            dst->w *= inv;
        }
    } else {
        f32 th, s, inv, w1, w2;
        th = func_00274640(d1);
        s = sinf(th);
        if (s == 0.0f) {
            *dst = *q1;
        } else {
            inv = 1.0f / s;
            w1 = sinf((1.0f - t) * th) * inv;
            w2 = sinf(t * th) * inv;
            if (d1 < d2) {
                q2 = &neg;
            }
            dst->x = w1 * q1->x + w2 * q2->x;
            dst->y = w1 * q1->y + w2 * q2->y;
            dst->z = w1 * q1->z + w2 * q2->z;
            dst->w = w1 * q1->w + w2 * q2->w;
        }
    }
}
