#include "b06_types.h"

void func_0028B250(u8 *a, Plr *b, s32 c, s32 d);
extern u8 D_8011FE88[];
extern s32 D_800CE430[];
extern s32 D_800CE47C;
extern GStateB6 D_801462C8[];

void func_0022BB70(Plr *a) {
    s32 k;
    if (D_801462C8->unk1D == 0) {
        k = 0x66;
    } else if (D_801462C8->sub.unk54 != 0 && a->stats->unk8F != 0) {
        k = D_800CE47C;
    } else {
        k = D_800CE430[a->unk18->unkC];
        a->unk3 = a->stats->unk81;
    }
    func_0028B250(D_8011FE88, a, k, a->unk86C);
}
