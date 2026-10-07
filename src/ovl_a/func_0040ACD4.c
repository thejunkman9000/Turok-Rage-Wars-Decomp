#include "o01_types.h"

extern s32 D_80153788;
extern O01Text D_800D781C;
extern O01Text D_800D7820;

s32 func_0040ACD4(O01Item *item) {
    switch (D_80153788) {
    default:
    case 0:
        item->unk14 = &D_800D781C;
        break;
    case 5:
    case 6:
    case 9:
    case 10:
    case 12:
    case 15:
        item->unk14 = &D_800D7820;
        break;
    }
    return 0;
}
