#include "o01_types.h"

extern s32 D_80153734;
extern O01Text D_800D7974;
extern O01Text D_800D7980;

s32 func_0040B490(O01Item *item) {
    if (D_80153734 != 0) {
        item->unk14 = &D_800D7974;
    } else {
        item->unk14 = &D_800D7980;
    }
    return 0;
}
