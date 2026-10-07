#include "b04_types.h"
void func_00274090(f32 *);
extern f32 D_800C7340, D_800C7344, D_800D2988;
f32 func_002184C0(f32 a, f32 b, s32 dir, f32 k) {
    f32 d, r, m;
    func_00274090(&a);
    func_00274090(&b);
    if (dir > 0) {
        if (b < a)
            b = b + D_800C7340;
    } else if (b > a) {
        b = b - D_800C7344;
    }
    d = b - a;
    r = d * k * D_800D2988;
    m = r;
    if (m < 0.0f) m = -m;
    if (d < 0.0f) {
        if (-d < m) goto blk;
    } else if (d < m) {
blk:
        r = d;
    }
    return r;
}
