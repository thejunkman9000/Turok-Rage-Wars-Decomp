#include "o01_types.h"

extern s32 D_80153778;
extern O01Text D_800D79A0;
extern O01Text D_800D79B4;
extern O01Text D_800D79C8;
extern O01Text D_800D79DC;
extern O01Text D_800D79F0;

s32 func_0040B9E0(O01Item *item) {
    switch (D_80153778) {
    default:
    case 0:
        item->unk14 = &D_800D79A0;
        break;
    case 1:
        item->unk14 = &D_800D79B4;
        break;
    case 2:
        item->unk14 = &D_800D79C8;
        break;
    case 3:
        item->unk14 = &D_800D79DC;
        break;
    case 4:
        item->unk14 = &D_800D79F0;
        break;
    }
    return 0;
}
