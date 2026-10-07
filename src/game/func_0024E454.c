#include "b11_types.h"

f32 Trunc16ToF32(u16 x);

f32 func_0024E454(Obj *a) {
    ObjDef *d = a->def;
    switch (d->type) {
    case 11:
        if (a->type == 1 && (a->flags & 0x300000) && a->unk1D8->unk80C != 0) {
            return func_0024E454(a->unk1D8->unk80C);
        }
        return a->def->unkF0;
    case 1:
    case 4:
        return d->unk2C;
    case 5:
        return d->u18.f;
    default:
        if (a->type == 2) {
            return Trunc16ToF32(a->unk118->unk30->unk14);
        }
        return 0.0f;
    }
}
