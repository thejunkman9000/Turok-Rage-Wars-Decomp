#include "b06_types.h"

extern u8 D_8011FE88[];
extern s32 D_801468F4;
PlrCls *func_0028CF7C(u8 *a, s32 b, s32 c);

void func_0022BAC0(Plr *a) {
    s32 k;
    PlrCls *c;
    Plr *new_var;
    k = (new_var = a)->unk5E0;
    if (D_801468F4 != 0 && new_var->stats->unk8F == 1) {
        k = 0x13;
    }
    c = func_0028CF7C(D_8011FE88, 0xB, k);
    if (c == NULL) {
        c = func_0028CF7C(D_8011FE88, 0xB, -1);
        if (c == NULL) {
            c = func_0028CF7C(D_8011FE88, -1, -1);
        }
    }
    new_var->unk18 = c;
    new_var->unk50 = c->unkFC;
    new_var->unk54 = c->unk100;
    new_var->unk58 = c->unk104;
}
