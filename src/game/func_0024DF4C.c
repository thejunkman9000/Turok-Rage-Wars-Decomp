#include "b11_types.h"

s32 func_0024DF4C(Obj *a) {
    ObjDef *d = a->def;
    s32 r;
    if (d->type == 1) {
        r = 0;
        if (a->unk174 <= 0 || (d->flags4C & 4)) {
            r = 1;
        }
        return r;
    }
    return 0;
}
