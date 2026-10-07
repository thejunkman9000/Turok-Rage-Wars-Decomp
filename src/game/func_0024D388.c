#include "b11_types.h"

extern f32 D_800C8D6C;
extern f32 D_800C8D70;

f32 func_0024D388(Obj *a) {
    ObjDef *d;
    f32 lo;
    f32 hi;
    switch (a->def->type) {
    case 11:
        if (a->type == 1 && (a->flags & 0x300000) && a->unk1D8->unk80C != 0) {
            return D_800C8D6C;
        }
        return a->def->unkEC;
    case 0:
    case 5:
    case 8:
    case 10:
    case 12:
    case 13:
    case 14:
        return a->def->u18.f;
    case 1:
    case 4:
        return a->def->unk28;
    case 2:
        d = a->def;
        if (d->u18.h == 2) {
            lo = d->unk20;
            if (!(d->unk1C <= lo)) {
                lo = d->unk1C;
            }
            hi = d->unk28;
            if (!(lo <= hi)) {
                hi = lo;
            }
            return hi * D_800C8D70;
        }
        return d->unk1C;
    case 7:
        return a->def->unk1C;
    default:
        return 0.0f;
    }
}
