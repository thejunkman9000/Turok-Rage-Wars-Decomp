#include "b12_types.h"

s32 func_00250D88(B12Obj *o) {
    B12Def *d = o->def;
    if (o->unkDC < d->unk24 * 2) {
        return d->unkE;
    }
    return d->unkF;
}
