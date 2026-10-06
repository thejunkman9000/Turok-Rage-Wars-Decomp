#include "b10_types.h"

extern B10Ctl *D_800E2830;
extern f32 D_800C88C4;
extern f32 D_800C88C8;
f32 func_40184C(f32 a);

f32 func_00245990(void) {
    B10Ctl *p = D_800E2830;
    f32 t;
    if (p->f38 == 0) {
        return D_800C88C4;
    }
    t = p->f100;
    if (t > D_800C88C8) {
        return t;
    }
    return func_40184C(p->f1C);
}