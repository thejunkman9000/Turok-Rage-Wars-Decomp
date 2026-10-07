#include "o01_types.h"

extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_80153750;
extern s32 D_8015375C;
extern O01Text D_800D7768;
extern O01Text D_800D776C;
extern O01Text D_800D7770;
extern O01Text D_800D7774;
extern O01Text D_800D777C;
extern O01Text D_800D778C;
extern O01Text D_800D7E14;

s32 func_0040A3A8(O01Item *item, s16 *code) {
    s32 c = *code;
    s32 d = c - 3;
    if (D_80153760 != 0) {
        if (D_8015377C != 0) {
            item->unk14 = &D_800D7768;
        } else {
            item->unk14 = &D_800D7770;
        }
    } else if (D_80153750 != 0) {
        if ((u32)d < 16) {
            item->unk14 = &D_800D777C;
            return 0;
        }
        if (c == 21) {
            item->unk14 = &D_800D7E14;
        } else if (D_8015377C != 0) {
            item->unk14 = &D_800D776C;
        } else {
            item->unk14 = &D_800D7774;
        }
    } else if (D_8015375C != 0) {
        item->unk14 = &D_800D778C;
    }
    return 0;
}
