#include "o01_types.h"

extern s32 D_80153778;
extern O01Text D_800D7A0C;
extern O01Text D_800D7A04;

s32 func_0040BBC0(O01Item *item) {
    switch (D_80153778) {
    default:
    case 0:
        item->unk14 = &D_800D7A0C;
        break;
    case 3:
        item->unk14 = &D_800D7A0C;
        break;
    case 4:
        item->unk14 = &D_800D7A0C;
        break;
    case 1:
    case 2:
        item->unk14 = &D_800D7A04;
        break;
    }
    return 0;
}
