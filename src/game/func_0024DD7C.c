#include "b11_types.h"

s32 func_0024DD7C(Obj *a) {
    ObjDef *d = a->def;
    if (d->type == 1) {
        return d->flags14 & 0x1;
    }
    return 0;
}
