#include "b04_types.h"
void func_00217074(void *, f32);
extern f32 D_800D2988;
void func_00216808(void *o, s32 a1, f32 x, f32 y) {
    f32 r = y;
    f32 t = y;
    f32 a;
    if (x < y) r = x;
    else if (y < -x) r = -x;
    r = r * D_800D2988;
    a = r;
    if (a < 0.0f) a = -a;
    if (t < 0.0f) {
        if (!(-t < a)) {
        } else goto blk;
    } else if (t < a) {
blk:
        r = t;
    }
    func_00217074(o, r);
}
