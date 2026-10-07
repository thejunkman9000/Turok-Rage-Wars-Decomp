#include "b17_types.h"

extern f32 D_800C9A50[];
extern f32 D_800D2988;

void func_002748E0(f32 *p, f32 t, f32 r) {
    f32 x = *p;
    f32 d = (t - x) * r * D_800D2988;
    f32 n;

    if (r == D_800C9A50[1]) {
        *p = t;
    } else if (x < t) {
        n = x + d;
        *p = n;
        if (t < n) {
            *p = t;
        }
    } else if (t < x) {
        n = x + d;
        *p = n;
        if (n < t) {
            *p = t;
        }
    }
}
