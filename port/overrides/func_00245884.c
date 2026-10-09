/* port (passthru_fix.py): func_00402BA0 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b10_types.h"

extern B10Ctl *D_800E2830;
void func_402BA0(u32);

void func_00245884(u32 pt_a0) {
    if (D_800E2830->f38) {
        func_402BA0(pt_a0);
    }
}
