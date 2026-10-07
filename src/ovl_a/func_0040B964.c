#include "o01_types.h"

extern s32 D_80153778;
extern O01Text D_800D799C;
extern O01Text D_800D79B0;
extern O01Text D_800D79C4;
extern O01Text D_800D79D8;
extern O01Text D_800D79EC;

s32 func_0040B964(O01Item *item) {
    switch (D_80153778) {
    default:
    case 0:
        item->unk14 = &D_800D799C;
        break;
    case 1:
        item->unk14 = &D_800D79B0;
        break;
    case 2:
        item->unk14 = &D_800D79C4;
        break;
    case 3:
        item->unk14 = &D_800D79D8;
        break;
    case 4:
        item->unk14 = &D_800D79EC;
        break;
    }
    return 0;
}
