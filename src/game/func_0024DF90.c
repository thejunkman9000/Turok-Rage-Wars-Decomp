#include "b11_types.h"

s32 func_0024DF90(Obj *a) {
    ObjDef *d = a->def;
    if (d->type == 1) {
        return d->flags4C & 0x8;
    }
    return 0;
}
