#include "b23_types.h"

extern StreamBuf D_800D2BB0;
extern u8 D_801051B8[];

s32 func_00252FFC(s32 n);
void func_0025631C(void *a, s32 b, s32 c, s32 d);

void func_002A209C(void) {
    if (D_800D2BB0.open != 1) {
        D_800D2BB0.size = 0x8BB01;
        D_800D2BB0.buf = (u8 *)func_00252FFC(0x8BB01);
        func_0025631C(D_801051B8, 0x200000, D_800D2BB0.size, (s32)D_800D2BB0.buf);
        D_800D2BB0.unkC = 0;
        D_800D2BB0.open = 1;
    }
}
