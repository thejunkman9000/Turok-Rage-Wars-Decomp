/* port (passthru_fix.py): func_00413464 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o03_types.h"
void func_00413464(u32);
void func_00419688(u32 pt_a0) {
    func_00413464(pt_a0);
}
