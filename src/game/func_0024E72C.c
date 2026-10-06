#include "b11_types.h"

void func_002165F8(Obj *a, void *b, void *c);

f32 func_0024E72C(Obj *a) {
    f32 buf[15];
    if (a->type == 1) {
        func_002165F8(a, a->unk170, buf);
        return buf[14];
    }
    return 0.0f;
}
