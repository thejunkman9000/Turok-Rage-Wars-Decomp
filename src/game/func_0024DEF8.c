#include "b11_types.h"

s32 func_0024DEF8(Obj *a) {
    ObjDef *d = a->def;
    s32 r;
    switch (d->type) {
    case 11:
        return 1;
    case 1:
        r = 0;
        if (a->unk174 <= 0 || (d->flags4C & 2)) {
            r = 1;
        }
        return r;
    default:
        return 0;
    }
}