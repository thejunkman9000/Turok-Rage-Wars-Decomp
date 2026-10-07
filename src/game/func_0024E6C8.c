#include "b11_types.h"

void func_002165F8(Obj *a, void *b, B11Res *c);

void func_0024E6C8(Obj *a, Vec3f *out) {
    B11Res r;
    if (a->type == 1) {
        func_002165F8(a, a->unk170, &r);
        *out = r.v;
    } else {
        out->x = 0;
        out->y = 0;
        out->z = 0;
    }
}
