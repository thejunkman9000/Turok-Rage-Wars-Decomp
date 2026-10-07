#include "b14_types.h"
u32 func_002607D8(u32 *pp, u32 n);
f32 func_00260654(f32 x, s32 bits);
f32 func_00260670(f32 t, f32 a, f32 b);
void func_0025FD94(B14Trk *t);
extern s32 D_8010EC78;
extern f32 D_8010EC7C;
extern f32 D_8010EC80;
void func_0025FFD0(B14Trk *t, u32 *pcur) {
    u32 cur;
    u32 x, y;
    f32 lo, hi;
    cur = *pcur;
    t->f2C = func_002607D8(&cur, 6);
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
    t->base = lo;
    t->range = hi - lo;
    do { } while (0);
    t->bits = func_002607D8(&cur, 6);
    t->cur = 0;
    t->start = 0;
    t->data = cur;
    func_0025FD94(t);
    *pcur = cur;
}
