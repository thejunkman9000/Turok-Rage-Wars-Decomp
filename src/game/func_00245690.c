#include "b10_types.h"

extern B10Ctl *D_800E2830;
s32 func_00245774(void);
void func_00245B64(s32 a);
void func_00245BB0(void);
void func_002537D8(s32 a, void *p);

void func_00245690(void) {
    if (func_00245774()) {
        func_00245B64(1);
        func_00245BB0();
        if (D_800E2830->p0) {
            func_002537D8(0, D_800E2830->p0);
        }
        D_800E2830->p0 = 0;
        D_800E2830->f4 = 0;
        D_800E2830->f38 = 0;
        D_800E2830->f3C = 0;
        D_800E2830->f60 = 0;
    }
}
