#include "o02_types.h"
extern u8 D_801539B0[];
extern s32 D_800E2AC0;
extern s32 D_800E2AC4;
void func_002A1748(void *p, s32 v, s32 n);
void func_00411F6C(void) {
    func_002A1748(D_801539B0, 0, 0x2A8);
    D_800E2AC0 = 1;
    D_800E2AC4 = 0;
}
