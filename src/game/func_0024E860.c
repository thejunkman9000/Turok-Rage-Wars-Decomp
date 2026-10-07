#include "b11_types.h"

f32 func_0024E860(Obj *a) {
    B11Box *b = a->unk14;
    f32 lo = b->p8->y;
    f32 hi;
    if (!(b->p4->y <= lo)) {
        lo = b->p4->y;
    }
    hi = b->pC->y;
    if (!(lo <= hi)) {
        hi = lo;
    }
    return hi - a->pos.y;
}
