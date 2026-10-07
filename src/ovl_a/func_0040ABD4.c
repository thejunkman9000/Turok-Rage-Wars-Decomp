#include "o01_types.h"

extern s32 D_80153788;
s32 func_00264A1C(O01Flags *f);

s32 func_0040ABD4(O01Item *item) {
    O01Flags *f;
    item->unkC->unk120 &= 0xFBFFFFFF;
    f = item->unkC;
    D_80153788 = 8;
    f->unk120 |= 8;
    return func_00264A1C(f);
}
