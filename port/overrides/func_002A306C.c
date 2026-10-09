/* port (passthru_fix.py): func_00254784 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b23_types.h"

void func_00254784();

s32 func_002A306C(u32 pt_a0) {
    func_00254784(pt_a0);
    return 0;
}
