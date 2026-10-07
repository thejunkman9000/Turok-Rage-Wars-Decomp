#include "b06_types.h"

extern u8 D_8011FE88;
extern s32 D_801468F4;
extern s32 D_80146938;
extern u8 D_801462D5;
extern ActorRow400 D_80102B10[];
PlrCls *func_0028CF7C(u8 *a, s32 b, s32 c);

void func_002266E4(Plr *a) {
    s32 k;
    s32 v;
    s32 w;
    s32 s;
    PlrCls *c;
    k = a->unk5E0;
    if (D_801468F4 != 0 && a->stats->unk8F == 1) {
        k = 0x13;
    }
    c = func_0028CF7C(&D_8011FE88, 0xB, k);
    if (c == NULL) {
        c = func_0028CF7C(&D_8011FE88, 0xB, -1);
        if (c == NULL) {
            c = func_0028CF7C(&D_8011FE88, -1, -1);
        }
    }
    a->unk18 = c;
    a->unk50 = c->unkFC;
    a->unk54 = c->unk100;
    a->unk58 = c->unk104;
    if (D_801468F4 != 0 && a->stats->unk8F != 0) {
        a->unk5E4 = 0xA00;
        a->unk174 = 0xA00;
        return;
    }
    if (D_80146938 != 0 && a->stats->unk94 != 0) {
        s = a->stats->unk80;
        if (s == 11) goto A1;
        if (s == 12) {
A1:
            v = 0x19000;
        } else if (s == 14) {
            goto B1;
        } else if (s == 13) {
B1:
            v = 0x12C00;
        } else {
            goto C1;
        }
    } else {
C1:
        v = a->unk18->unk18 << 8;
    }
    if (D_801462D5 == 1 && a->unk1450 == 0) {
        v += D_80102B10[a->unk5D4].unk0;
    }
    a->unk5E4 = v;
    if (D_80146938 != 0 && a->stats->unk94 != 0) {
        s = a->stats->unk80;
        if (s == 11) goto A2;
        if (s == 12) {
A2:
            w = 0x19000;
        } else if (s == 14) {
            goto B2;
        } else if (s == 13) {
B2:
            w = 0x12C00;
        } else {
            goto C2;
        }
    } else {
C2:
        w = a->unk18->unk18 << 8;
    }
    if (D_801462D5 == 1 && a->unk1450 == 0) {
        w += D_80102B10[a->unk5D4].unk0;
    }
    a->unk174 = w;
    a->unk3 = -1;
}
