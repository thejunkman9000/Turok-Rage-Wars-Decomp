/* port (passthru_fix.py): func_0040FA60 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o02_types.h"
extern s16 D_80153C2C;
void func_0040FA60(u32);
void func_00411E24(u32 pt_a0) {
    if (D_80153C2C) {
        func_0040FA60(pt_a0);
    }
}
