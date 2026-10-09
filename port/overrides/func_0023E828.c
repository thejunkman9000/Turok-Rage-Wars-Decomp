/* port (passthru_fix.py): func_0023E844 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b09_types.h"

void func_0023E844(u32);

void func_0023E828(u32 pt_a0) {
    func_0023E844(pt_a0);
}
