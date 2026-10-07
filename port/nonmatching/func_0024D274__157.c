#include "b11_types.h"

extern f32 D_800C8D24;
extern f32 D_800C8D28;
f32 func_0024E3B4(Obj *a);

f32 func_0024D274(Obj *a) {
    ObjDef *d;
    f32 r;
    if (a->type == 1 && a->unk174 <= 0) {
        return func_0024E3B4(a);
    }
    switch (a->def->type) {
    case 11:
        if (a->type == 1 && (a->flags & 0x300000)) {
            return a->unk1D8->unk6F4;
        }
        return a->def->unkF4;
    case 1:
    case 4:
        return a->def->unk30;
    case 8:
        d = a->def;
        {
            u32 fl14 = d->flags14;
            r = D_800C8D24;
            if (!(fl14 & 1)) {
                r = d->unk1C;
            }
        }
        return r;
    case 7:
        return a->def->unk20;
    case 6:
        return D_800C8D28;
    case 0:
    case 5:
    case 10:
    case 12:
    case 13:
    case 14:
        return a->def->unk1C;
    default:
        return 0.0f;
    }
}
