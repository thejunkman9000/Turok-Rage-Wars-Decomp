#include "o01_types.h"

extern s32 D_80153780;
extern O01Text D_800D7810;
extern O01Text D_800D7814;

s32 func_0040A6D4(O01Item *item) {
    if (D_80153780 != 0) {
        item->unk14 = &D_800D7810;
    } else {
        item->unk14 = &D_800D7814;
    }
    return 0;
}
