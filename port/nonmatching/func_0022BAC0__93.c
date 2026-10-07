#include "b06_types.h"

extern u8 D_8011FE88[];
extern s32 D_801468F4;
PlrCls *func_0028CF7C(u8 *a, s32 b, s32 c);

void func_0022BAC0(Plr *a) {
    s32 k;
    PlrCls *c;
    u8 *t = D_8011FE88;
    k = a->unk5E0;
    if (D_801468F4 != 0 && a->stats->unk8F == 1) {
        k = 0x13;
    }
    c = func_0028CF7C(t, 0xB, k);
    if (c == NULL) {
        c = func_0028CF7C(t, 0xB, -1);
        if (c == NULL) {
            c = func_0028CF7C(t, -1, -1);
        }
    }
    a->unk18 = c;
    a->unk50 = c->unkFC;
    a->unk54 = c->unk100;
    a->unk58 = c->unk104;
}
