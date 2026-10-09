/* port (passthru_fix.py): func_00293318 needs a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "p4_types.h"
extern u8 D_8011FE88[];
extern s32 D_8014694C;
void func_00293318(s32 a, s32 b, s32 c, u32);
void func_00286A78(void *a, s32 b, s32 c);
void func_00299368(s32 a);
void func_0025E2F4(s32 a);
void func_002943B8(s32 a, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    func_00293318(a, 0, 0, pt_a3);
    func_00286A78(D_8011FE88, 0, 0);
    D_8014694C = 0;
    func_00299368(0x18);
    func_0025E2F4(0x34);
}
