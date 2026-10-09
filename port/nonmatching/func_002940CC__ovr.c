/* port (passthru_fix.py): func_00293318 needs a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b21_types.h"

void func_00293318(B21Game *p, s32 a, s32 b, u32);

void func_002940CC(B21Game *p, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    func_00293318(p, 0, 0, pt_a3);
}
