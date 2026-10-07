#include "b11_types.h"

void func_00275C38(f32 *out, B11Box *box);

s32 func_0024BCF8(Obj *a) {
    B11Box *b = a->unk14;
    f32 t;
    f32 hi;
    f32 t2;
    f32 lo;
    f32 s;
    f32 c;
    f32 buf[3];
    if (b == 0) {
        return 0;
    }
    t = b->p8->y;
    if (!(b->p4->y <= t)) {
        t = b->p4->y;
    }
    hi = b->pC->y;
    if (!(t <= hi)) {
        hi = t;
    }
    t2 = b->p8->y;
    if (!(t2 <= b->p4->y)) {
        t2 = b->p4->y;
    }
    lo = b->pC->y;
    if (!(lo <= t2)) {
        lo = t2;
    }
    if (hi < a->pos.y) {
        return 0;
    }
    if (a->pos.y < lo) {
        return 0;
    }
    s = sinf(a->unk6C.f);
    c = cosf(a->unk6C.f);
    func_00275C38(buf, b);
    return buf[0] * -s + buf[2] * -c < 0.0f;
}
