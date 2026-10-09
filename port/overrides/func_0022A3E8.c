/* port (passthru_fix.py): func_00228AD0 needs a0 a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b06_types.h"

void func_00228AD0();

void func_0022A3E8(u32 pt_a0, u32 pt_a1) {
    func_00228AD0(pt_a0, pt_a1);
}
