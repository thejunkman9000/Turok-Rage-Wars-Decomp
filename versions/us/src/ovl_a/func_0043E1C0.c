#include "s1009_types.h"
extern S10Game D_801468A0[];
extern f32 D_8015404C;
extern f32 D_800D2988;
extern void func_0022A738(void *p);
s32 func_0043E1C0(void) {
    D_8015404C += D_800D2988;
    if (D_8015404C >= 120.0f) {
        D_801468A0->unk24 = 0;
        func_0022A738((u8 *)D_801468A0 - 0x1860);
        return 1;
    }
    return 0;
}
