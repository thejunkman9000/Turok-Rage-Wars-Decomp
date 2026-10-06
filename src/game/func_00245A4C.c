#include "b10_types.h"

extern B10Ctl *D_800E2830;

void func_00245A4C(s32 a, s32 b, s32 c, s32 d) {
    B10Ctl *p = D_800E2830;
    p->f10C = b;
    p->f108 = a;
    p->f110 = c;
    p->f114 = d;
}
