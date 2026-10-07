#include "b11_types.h"

f32 func_0024E8A8(Obj *a) {
    B11Box *b = a->unk14;
    f32 hi = b->p8->y;
    f32 lo;
    if (!(hi <= b->p4->y)) {
        hi = b->p4->y;
    }
    lo = b->pC->y;
    if (!(lo <= hi)) {
        lo = hi;
    }
    return a->pos.y - lo;
}
