#include "b11_types.h"

extern u8 D_801462E5;

s32 func_0024D150(Obj *a) {
    B11Own *o;
    u32 f;
    u32 g;
    switch (a->def->type) {
    case 11:
        if (a->type == 1 && (a->flags & 0x300000)) {
            o = a->unk1D8;
            if (D_801462E5 != 0) {
                if (o->unk85C != 0) {
                    return 0;
                }
            }
        }
        return 1;
    case 8:
        return 1;
    case 0:
        return a->def->flags14 & 2;
    case 2:
        if (a->type != 1) {
            return 0;
        }
        return a->flags & 0x10000;
    case 1:
        if (a->type != 1) {
            return 0;
        }
        if (!(a->flags & 0x2000)) {
            return 0;
        }
        if (a->unk1A0 == 0) {
            return 0;
        }
        g = a->unk1A0->flags1C & 0x10000;
        return g == 0;
    case 4:
    case 5:
    case 7:
    case 10:
        if (a->type != 1) {
            return 0;
        }
        f = a->flags;
        if (!(f & 0x2000)) {
            return 0;
        }
        return f & 0x10000;
    case 12:
        return a->def->flags14 & 1;
    default:
        return 0;
    }
}