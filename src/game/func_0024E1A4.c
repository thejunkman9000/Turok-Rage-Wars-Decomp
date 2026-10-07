#include "b11_types.h"

s32 func_0024E1A4(Obj *a) {
    B11Obj1A0 *p;
    if (a->type != 1) {
        return 0;
    }
    if (!(a->flags & 0x2000)) {
        return 0;
    }
    p = a->unk1A0;
    if (p != 0) {
        if (p->flags1C & 0x10000) {
            return 0;
        }
    }
    return 1;
}