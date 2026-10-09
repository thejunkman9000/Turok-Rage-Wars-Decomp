/* port (passthru_fix.py): func_00442158 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o01_types.h"

extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153734;
extern O01Text D_800D7978;
extern O01Text D_800D7984;
extern u8 D_800E0DCC[];
s32 func_00442158();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_0040B4C4(O01Item *item, O01Owner *own) {
    s32 v;
    char *buf;
    if (D_8015375C != 0) {
        v = D_800E28C8;
    } else {
        v = own->unk20->unk4;
    }
    if (D_80153734 != 0) {
        item->unk14 = &D_800D7978;
    } else {
        item->unk14 = &D_800D7984;
        buf = D_800D7984.buf;
        func_00265904(buf + (func_00442158(item) - 2), D_800E0DCC, v + 1);
    }
    return 0;
}
