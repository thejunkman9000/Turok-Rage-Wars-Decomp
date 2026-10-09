/* port (passthru_fix.py): func_00299368 needs a1 a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o04_types.h"
extern O04GFlags D_801468A0[];
void func_00299368(s32 a, u32, u32, u32);
void func_0042D214(u32 pt_a0, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    D_801468A0->unk78 = 0;
    D_801468A0->unk54 = 0;
    func_00299368(0xF, pt_a1, pt_a2, pt_a3);
}
