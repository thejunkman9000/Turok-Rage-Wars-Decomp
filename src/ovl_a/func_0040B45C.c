#include "o01_types.h"

extern s32 D_80153734;
extern O01Text D_800D7970;
extern O01Text D_800D797C;

s32 func_0040B45C(O01Item *item) {
    if (D_80153734 != 0) {
        item->unk14 = &D_800D7970;
    } else {
        item->unk14 = &D_800D797C;
    }
    return 0;
}
