/* port (passthru_fix.py): func_0020EA10 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b02_types.h"

void func_0020EA10();
extern s32 D_80146918;

s32 func_0020EAB4(u32 pt_a0) {
    if (D_80146918 != 0) {
        func_0020EA10(pt_a0);
    }
    return 1;
}
