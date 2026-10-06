#include "b11_types.h"

f32 func_0024E410(Obj *a) {
    ObjDef *d;
    if (a->type == 1) {
        return a->unk70;
    }
    d = a->def;
    if (d->type == 0) {
        return d->unk20;
    }
    return 0.0f;
}
