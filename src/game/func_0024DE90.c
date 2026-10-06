#include "b11_types.h"

extern u8 D_801462E5;

s32 func_0024DE90(Obj *a) {
    ObjDef *d = a->def;
    if (d->type == 0xB) {
        if (D_801462E5) {
            return d->flags14 & 1;
        }
        return 1;
    }
    return 0;
}
