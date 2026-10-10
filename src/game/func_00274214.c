#include "b16_types.h"

f32 func_802BC380(f32 x);

void func_00274214(B16Vec4 *v) {
    f32 len;
    f32 inv;
    len = func_802BC380(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
    if (len != 0.0f) {
        inv = 1.0f / len;
        v->x *= inv;
        v->y *= inv;
        v->z *= inv;
        v->w *= inv;
    }
}
