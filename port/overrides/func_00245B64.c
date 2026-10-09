/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "b10_types.h"

extern B10Ctl *D_800E2830;

void func_00245B64(u32 pt_a0, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    B10Ctl *p = D_800E2830;
    if (p->f44 == 0) {
        void (*fn)(void) = p->fn10;
        if (fn) {
            p->fn10 = 0;
            ((void (*)(u32, u32, u32, u32))fn)(pt_a0, pt_a1, pt_a2, pt_a3);
        }
        D_800E2830->f44 = 1;
    }
}
