/* port (passthru_fix.py): func_00255E78 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b09_types.h"

void func_00255E78(u8 *, u32);
void func_00255C58(u8 *, s32);

void func_0023B8E8(u8 *p, s32 a) {
    func_00255E78(p + 0x8B4, a);
    func_00255C58(p + 0x8A0, a);
}
