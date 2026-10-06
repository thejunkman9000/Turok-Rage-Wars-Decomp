#include "b10_types.h"

extern B10Ctl *D_800E2830;
void func_002537D8(s32 a, void *p);

void func_00245B18(void) {
    if (D_800E2830->p0) {
        func_002537D8(0, D_800E2830->p0);
    }
    D_800E2830->p0 = 0;
    D_800E2830->f4 = 0;
    D_800E2830->f38 = 0;
    D_800E2830->f3C = 0;
    D_800E2830->f60 = 0;
}
