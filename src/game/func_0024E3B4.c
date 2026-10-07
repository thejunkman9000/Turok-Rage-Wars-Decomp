#include "b11_types.h"

f32 func_0024E3B4(Obj *a) {
    ObjDef *d = a->def;
    switch (d->type) {
    case 11:
        return d->unkF8;
    case 1:
    case 4:
        return d->unk34;
    default:
        return 0.0f;
    }
}
