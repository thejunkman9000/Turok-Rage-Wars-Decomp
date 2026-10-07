#include "o01_types.h"

extern s32 D_80153778;
extern O01Text D_800D79A8;
extern O01Text D_800D79BC;
extern O01Text D_800D79D0;
extern O01Text D_800D79E4;
extern O01Text D_800D79F8;

s32 func_0040BAD8(O01Item *item) {
    switch (D_80153778) {
    default:
    case 0:
        item->unk14 = &D_800D79A8;
        break;
    case 1:
        item->unk14 = &D_800D79BC;
        break;
    case 2:
        item->unk14 = &D_800D79D0;
        break;
    case 3:
        item->unk14 = &D_800D79E4;
        break;
    case 4:
        item->unk14 = &D_800D79F8;
        break;
    }
    return 0;
}
