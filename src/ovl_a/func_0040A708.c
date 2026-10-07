#include "o01_types.h"

extern s32 D_80153780;
extern u8 D_8014561C[];
extern u8 D_0044F100[];
void func_004426E4(u8 *a, void *b, s32 c, void *d, s32 e);

s32 func_0040A708(O01Item *item, O01Owner *own) {
    int new_var;
    do {
        if (D_80153780 != 0) {
            func_004426E4(D_8014561C, D_0044F100, own->unk1C, own->unk20, 0);
        } else {
            func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        }
    } while (0);
    new_var = 1;
    return new_var;
}
