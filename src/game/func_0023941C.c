#include "b08_types.h"

extern DlCmd *D_80110634;
extern s32 D_800D297C;

void func_0023941C(u8 *base) {
    DlCmd *dl;

    dl = D_80110634++;
    dl->w0 = 0xDA380007;
    dl->w1 = (u32)(base + ((D_800D297C << 6) + 0x448));
}
