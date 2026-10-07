#include "o01_types.h"

extern s32 D_80153778;
extern O01Text D_800D7998;
extern O01Text D_800D79AC;
extern O01Text D_800D79C0;
extern O01Text D_800D79D4;
extern O01Text D_800D79E8;

s32 func_0040B8E8(O01Item *item) {
    switch (D_80153778) {
    default:
    case 0:
        item->unk14 = &D_800D7998;
        break;
    case 1:
        item->unk14 = &D_800D79AC;
        break;
    case 2:
        item->unk14 = &D_800D79C0;
        break;
    case 3:
        item->unk14 = &D_800D79D4;
        break;
    case 4:
        item->unk14 = &D_800D79E8;
        break;
    }
    return 0;
}
