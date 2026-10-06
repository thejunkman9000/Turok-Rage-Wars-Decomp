#include "b10_types.h"

extern B10Ctl *D_800E2830;
extern f32 D_800D2988;
extern f32 D_800C88D0;
s32 func_00245774(void);
s32 func_00245840(void);
void func_00244E48(void);

void func_00245C28(void) {
    if (func_00245774()) {
        if (func_00245840()) {
            D_800E2830->f20 = D_800E2830->f1C;
            return;
        }
        D_800E2830->f20 = D_800E2830->f1C;
        D_800E2830->f1C += D_800D2988 * D_800C88D0;
        if (D_800E2830->f30 <= D_800E2830->f1C) {
            func_00244E48();
        }
        if (D_800E2830->f1C >= D_800E2830->f2C) {
            if (D_800E2830->f104 == 1) {
                D_800E2830->f1C -= D_800E2830->f2C;
            } else {
                D_800E2830->f1C = D_800E2830->f2C;
                if (D_800E2830->fB4) {
                    D_800E2830->f3C = 1;
                    D_800E2830->fB4 = 0;
                }
            }
        }
    }
}
