#include "o01_types.h"

extern s32 D_80153760;
extern O01Text D_800D7990;
extern O01Text D_800D7994;

s32 func_0040B74C(O01Item *item) {
    if (D_80153760 != 0) {
        item->unk14 = &D_800D7990;
    } else {
        item->unk14 = &D_800D7994;
    }
    return 0;
}
