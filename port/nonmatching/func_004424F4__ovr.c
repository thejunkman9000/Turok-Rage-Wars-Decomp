/* port (passthru_fix.py): func_00442020 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o06_types.h"
extern s32 func_00442020(s32 a, u32);
s32 func_004424F4(s32 a, s32 b, s32 c) { return func_00442020(c, b) != 0; }
