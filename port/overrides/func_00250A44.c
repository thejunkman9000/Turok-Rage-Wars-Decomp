/* port (passthru_fix.py): func_00250458 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b12_types.h"

extern u8 D_801462E5;
void func_0025021C(void);
void func_00250458(u32);

void func_00250A44(u32 pt_a0) {
    if (D_801462E5 != 0) {
        func_00250458(pt_a0);
    } else {
        func_0025021C();
    }
}
