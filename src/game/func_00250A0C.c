#include "b12_types.h"

s32 func_00250A0C(B12Obj *o) {
    if (o->unkD8 & 0x40) {
        return 0;
    }
    return o->def->unk12;
}
