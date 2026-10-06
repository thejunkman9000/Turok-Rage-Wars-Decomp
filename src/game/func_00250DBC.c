#include "b12_types.h"

extern u8 D_801462E5;

s32 func_00250DBC(B12Obj *o) {
    B12Def *d;
    if (D_801462E5) {
        return o->def->unkE;
    }
    d = o->def;
    if (o->unkDC < d->unk24 * 2) {
        return d->unkE;
    }
    return d->unkF;
}
