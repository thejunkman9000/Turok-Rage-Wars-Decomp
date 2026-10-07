#include "o01_types.h"

extern s32 D_80153788;
extern O01Text D_800D7824;
extern O01Text D_800D7828;

s32 func_0040B2FC(O01Item *item) {
    switch (D_80153788) {
    default:
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        item->unk14 = &D_800D7824;
        break;
    case 8:
        item->unk14 = &D_800D7828;
        break;
    }
    return 0;
}
