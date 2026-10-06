#include "b19_types.h"
extern u8 D_801462E3;
s32 func_002833B0(B19Obj *o) {
    s32 r = 0;
    if (o->parent->flags & 0x2000000) {
        if (o->flags & 2) r = 2;
        else if (D_801462E3 == 2) r = 1;
    }
    return r;
}
