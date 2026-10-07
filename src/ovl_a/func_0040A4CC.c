#include "o01_types.h"

extern s32 D_80153780;
extern O01Text D_800D77CC;
extern O01Text D_800D77D0;

s32 func_0040A4CC(O01Item *item) {
    if (D_80153780 != 0) {
        item->unk14 = &D_800D77CC;
    } else {
        item->unk14 = &D_800D77D0;
    }
    return 0;
}
