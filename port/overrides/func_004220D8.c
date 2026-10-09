/* port (passthru_fix.py): func_004030E0 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o03_types.h"
extern O3Gl D_801450A8[];
extern O3Scr *D_800E2830;
extern u8 D_8011FE88[];
s32 func_004030E0();
s32 func_0025471C();
void func_0025470C(s32 a);
void func_0044E178(void *p, s32 a, s32 b);
void func_004220D8(u32 pt_a0) {
    f32 a, b;
    s32 m;
    O3Gl *g = D_801450A8;
    O3Cam *c = g->p;
    O3Scr *sc;
    a = 45.0f;
    b = 1.333333f;
    sc = D_800E2830;
    c->f6C = a;
    c->f70 = b;
    c->f29C = (f32)sc->w108;
    c->f2A0 = (f32)sc->w10C;
    do {
        c->f2A4 = (f32)sc->w110;
        c->f2A8 = (f32)sc->w114;
        m = func_004030E0(pt_a0);
        if (func_0025471C() == 0) {
            func_0025470C(1);
        }
        func_0044E178(D_8011FE88, ~m, 0);
        g->f8C = a;
        g->f90 = b;
    } while (0);
}
