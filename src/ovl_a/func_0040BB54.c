#include "o01_types.h"

extern s32 D_80153778;
extern O01Text D_800D7A08;
extern O01Text D_800D7A00;

s32 func_0040BB54(O01Item *item) {
    switch (D_80153778) {
    default:
    case 0:
        item->unk14 = &D_800D7A08;
        break;
    case 3:
        item->unk14 = &D_800D7A08;
        break;
    case 4:
        item->unk14 = &D_800D7A08;
        break;
    case 1:
    case 2:
        item->unk14 = &D_800D7A00;
        break;
    }
    return 0;
}
