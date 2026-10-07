#include "o01_types.h"

extern s32 D_80153730;
extern s32 D_80153774;

void func_0040A7A8(O01Item *item) {
    item->unkC->unkA8 &= 0xFE7FFFFF;
    D_80153730 = 0;
    D_80153774 = 1;
    item->unkC->unkD0 &= 0xFE7FFFFF;
}
