#include "o01_types.h"

extern s32 D_80153730;
extern s32 D_80153774;
extern O01Text D_800D77EC;
extern O01Text D_800D77F0;
extern O01Text D_800D77F4;

s32 func_0040A7E8(O01Item *item) {
    if (D_80153730 != 0) {
        item->unk14 = &D_800D77EC;
    } else if (D_80153774 != 0) {
        item->unk14 = &D_800D77F4;
    } else {
        item->unk14 = &D_800D77F0;
    }
    return 0;
}
