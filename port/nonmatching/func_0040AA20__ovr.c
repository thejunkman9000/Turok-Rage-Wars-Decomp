/* port (passthru_fix.py): func_00442158 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o01_types.h"

extern u16 D_8015371C;
extern u8 D_800E0DC4[];
s32 func_00442158();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_0040AA20(O01Item *item) {
    s32 v = D_8015371C;
    char *buf = item->unk14->buf;
    func_00265904(buf + (func_00442158(item) - 4), D_800E0DC4, v);
    return 0;
}
