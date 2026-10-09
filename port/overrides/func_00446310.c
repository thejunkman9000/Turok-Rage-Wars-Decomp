/* port (passthru_fix.py): func_00441764 needs a0 a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o06_types.h"
extern void func_00441764(u32, u32);
void func_00446310(u32 pt_a0, u32 pt_a1) { func_00441764(pt_a0, pt_a1); }
