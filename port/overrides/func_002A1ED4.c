/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "b23_types.h"
extern s32 (*D_800D2B9C)(s32 fp, void *buf, s32 n);
s32 func_002A1ED4(void *buf, s32 size, s32 n, s32 fp) {
    s32 total = size * n;
    if (total == 0) {
        return 0;
    }
    return ((s32 (*)(s32, void *, s32, u32))D_800D2B9C)(fp, buf, total, (u32)fp) / size;

}
