#include "o01_types.h"

extern s32 D_80153778;
extern O01Text D_800D79A4;
extern O01Text D_800D79B8;
extern O01Text D_800D79CC;
extern O01Text D_800D79E0;
extern O01Text D_800D79F4;

s32 func_0040BA5C(O01Item *item) {
    switch (D_80153778) {
    default:
    case 0:
        item->unk14 = &D_800D79A4;
        break;
    case 1:
        item->unk14 = &D_800D79B8;
        break;
    case 2:
        item->unk14 = &D_800D79CC;
        break;
    case 3:
        item->unk14 = &D_800D79E0;
        break;
    case 4:
        item->unk14 = &D_800D79F4;
        break;
    }
    return 0;
}
