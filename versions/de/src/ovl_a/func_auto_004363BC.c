#include "o05_types.h"

extern void *D_800E5558;
extern s32 D_80146894;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_00299368(s32 a);
void func_002A338C(void);
s32 func_0042AEB8(void);
void func_0040C4A8(s32 a);
void func_0043C458(void *p);

s32 func_auto_004363BC(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x3D3:
        func_00299368(1);
        return 0;
    case 0x3D2:
        D_80146894 = 0;
        func_002A338C();
        if (func_0042AEB8() == 0) {
            func_0040C4A8(0);
            func_00299368(0x14);
            return 0;
        }
        func_0043C458(D_800E5558);
        return 0;
    default:
        return 0;
    }
}
