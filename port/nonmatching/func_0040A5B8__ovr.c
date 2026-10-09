/* port (passthru_fix.py): func_00442158 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o01_types.h"

extern O01Cfg *D_800E28BC;
extern u8 D_800E0DB0[];
s32 func_00442158();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_0040A5B8(O01Item *item) {
    s32 v = D_800E28BC->unk22;
    char *buf = item->unk14->buf;
    func_00265904(buf + (func_00442158(item) - 2), D_800E0DB0, v);
    return 0;
}
