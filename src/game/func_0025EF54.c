#include "b14_types.h"
u32 func_002607D8(u32 *pp, u32 n);
f32 func_00260654(f32 x, s32 bits);
f32 func_00260670(f32 t, f32 a, f32 b);
f32 func_00260BA0(u32 *pp, B14FRange r);
extern s32 D_8010EC78;
extern f32 D_8010EC7C;
extern f32 D_8010EC80;
void func_0025EF54(u32 *pcur, f32 *out, s32 count) {
    u32 cur;
    u32 x, y;
    f32 lo, hi;
    B14FRange r;
    s32 i;
    cur = *pcur;
    if (D_8010EC78 != 0) {
        x = func_002607D8(&cur, 32);
        y = func_002607D8(&cur, 32);
        lo = *(f32 *)&x;
        hi = *(f32 *)&y;
    } else {
        x = func_002607D8(&cur, 6);
        y = func_002607D8(&cur, 6);
        lo = func_00260654((f32)x, 6);
        hi = func_00260654((f32)y, 6);
        lo = func_00260670(lo, D_8010EC7C, D_8010EC80);
        hi = func_00260670(hi, D_8010EC7C, D_8010EC80);
    }
    r.min = lo;
    r.range = hi - lo;
    r.n = func_002607D8(&cur, 6);
    for (i = 0; i < count; i++) {
        *out = func_00260BA0(&cur, r);
        out += 4;
    }
    *pcur = cur;
}
