#include "b11_types.h"

s32 func_0024E690(Obj *a) {
    s32 r = 0;
    if (a->type == 1) {
        s32 v = a->unk34;
        if (v != 0 && (a->unk38 & 3)) {
            r = v;
        }
    }
    return r;
}
