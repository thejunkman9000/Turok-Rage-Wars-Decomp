#include "b10_types.h"

extern B10Ctl *D_800E2830;
void func_002A125C(void *dst, void *src);

void func_00245A68(void *src) {
    func_002A125C(&D_800E2830->ent[D_800E2830->f1E0], src);
    D_800E2830->f1E0++;
}
