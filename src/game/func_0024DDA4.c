#include "b11_types.h"

s32 func_0024DDA4(Obj *a) {
    ObjDef *d = a->def;
    if (d->type == 1) {
        return d->flags14 & 0x2;
    }
    return 0;
}
