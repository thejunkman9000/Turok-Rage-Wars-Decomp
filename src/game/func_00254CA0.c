#include "b12_types.h"
extern s32 D_801045A8[];
extern s32 D_80104598[];
void func_00254CE4(s32 a, s32 b);

void func_00254CA0(void) {
    func_00254CE4(0, D_801045A8[0]);
    D_80104598[D_801045A8[0]] = 0;
}
