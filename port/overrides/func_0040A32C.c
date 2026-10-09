/* port (passthru_fix.py): func_00442158 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o01_types.h"

extern s32 D_8015375C;
extern u8 D_800D7E14[];
extern O01Text D_800D7710;
extern u8 D_800E0DAC[];
s32 func_00442158();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_0040A32C(O01Item *item, O01Owner *own) {
    char *buf;
    s32 v;
    if (D_8015375C != 0) {
        item->unk14 = (O01Text *)D_800D7E14;
    } else {
        v = own->unk20->unk4;
        item->unk14 = &D_800D7710;
        buf = D_800D7710.buf;
        func_00265904(buf + (func_00442158(item) - 1), D_800E0DAC, v + 1);
    }
    return 0;
}
