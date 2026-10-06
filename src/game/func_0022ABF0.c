#include "p1_types.h"
extern s32 D_80146938;
extern u8 D_801462D5;
extern ActorRow400 D_80102B10[];
s32 func_0022ABF0(Actor *a) {
    s32 r;
    ActorStats *st;
    if (D_80146938 != 0 && (st = a->stats)->unk94 != 0) {
        s8 t = st->unk80;
        if (t == 11) goto A;
        if (t == 12) {
A:
            r = 0x19000;
        } else if (t == 14) goto B;
        else if (t == 13) {
B:
            r = 0x12C00;
        } else goto C;
    } else {
C:
        r = a->def->info.unk4 << 8;
    }
    if (D_801462D5 == 1 && a->unk1450 == 0) {
        r += D_80102B10[a->unk5D4].unk0;
    }
    return r;
}
