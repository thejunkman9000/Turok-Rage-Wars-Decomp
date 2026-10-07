#include "o01_types.h"

extern s32 D_80153730;
extern s32 D_80153774;
extern O01Text D_800D7810;
extern O01Text D_800D7814;
extern O01Text D_800D7818;

s32 func_0040AA78(O01Item *item) {
    if (D_80153730 != 0) {
        item->unk14 = &D_800D7810;
    } else if (D_80153774 != 0) {
        item->unk14 = &D_800D7818;
    } else {
        item->unk14 = &D_800D7814;
    }
    return 0;
}
