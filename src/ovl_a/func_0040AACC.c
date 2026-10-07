#include "o01_types.h"

extern s32 D_80153730;
extern u8 D_8014561C[];
extern u8 D_0044F0B8[];
void func_004426E4(u8 *a, void *b, s32 c, void *d, s32 e);

s32 func_0040AACC(O01Item *item, O01Owner *own) {
    if (D_80153730 != 0) {
        func_004426E4(D_8014561C, D_0044F0B8, own->unk1C, own->unk20, 0);
    } else {
        func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
    }
    return 1;
}
