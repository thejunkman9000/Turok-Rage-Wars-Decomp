#include "b06_types.h"

extern u8 D_8011FE88[];
extern PlrDef *D_800D052C[];
extern s32 D_801450B8;
extern s32 D_8014694C;
void func_0028B250(u8 *a, u8 *b, s32 c, s32 d);

void func_0022BC04(Plr *a) {
    s32 k;
    if (a->unk1450 == 0) goto l1;
    if (D_8014694C != 0) goto l1;
    k = 0x17;
    goto l2;
l1:
    k = 0;
    if (D_801450B8 != 1) k = 0x17;
l2:
    func_0028B250(D_8011FE88, (u8 *)a + 0x2E8, D_800D052C[a->unk62E]->unk4 + k, a->unk484->unk10);
}
