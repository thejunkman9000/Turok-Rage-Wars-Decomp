/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "b23_types.h"
extern s32 (*D_800D2B9C)(s32 fp, u8 *buf, s32 n);
s32 func_002A1FCC(s32 fp, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    u8 c;
    return ((s32 (*)(s32, u8 *, s32, u32))D_800D2B9C)(fp, &c, 1, pt_a3) ? c : -1;

}
