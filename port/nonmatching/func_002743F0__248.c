#include "b16_types.h"
extern f32 D_800D2988;
f32 func_00274640(f32 x);
B16Vec4 func_00270D40(f32 t, B16Vec4 *a, B16Vec4 *b);
void func_002743F0(B16Vec4 *q1, B16Vec4 *q2) {
    f32 th, r, u;
    th = func_00274640(q1->x * q2->x + q1->y * q2->y + q1->z * q2->z + q1->w * q2->w);
    if (th != 0.0f) {
        r = 1.0f - (th - (th * 0.1388889f + 0.0001745329f) * D_800D2988) / th;
        u = 1.0f;
        if (1.0f < r) goto b4;
        if (r < 0.0f) {
            u = 0.0f;
        } else {
            u = 1.0f;
b4:
            if (!(u < r)) u = r;
        }
        *q1 = func_00270D40(u, q1, q2);
    }
}
