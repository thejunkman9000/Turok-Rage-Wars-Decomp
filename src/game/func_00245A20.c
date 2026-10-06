#include "b10_types.h"

extern B10Ctl *D_800E2830;
extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_00245A20(void) {
    B10Ctl *p = D_800E2830;
    p->f10C = D_800E28D4;
    p->f108 = D_800E28D0;
    p->f110 = 0;
    p->f114 = 0;
}
