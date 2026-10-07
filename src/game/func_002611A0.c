#include "b14_types.h"
void func_0025FFD0(B14Trk *t, u32 *pcur);
f32 func_002610AC(B14Trk *t, f32 x, s32 a, s32 b);
void func_002611A0(u32 *pcur, f32 *out, s32 count) {
    B14Trk t;
    u32 cur;
    s32 i;
    cur = *pcur;
    func_0025FFD0(&t, &cur);
    for (i = 0; i < count; i++) {
        *out = func_002610AC(&t, (f32)i, 0, 0);
        out += 4;
    }
    cur += t.f2C * (t.bits * 4 + 6);
    *pcur = cur;
}
