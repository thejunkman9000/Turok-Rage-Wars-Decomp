#include "o05_types.h"
extern s32 D_80146894;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_002A3304(void);
void func_0025E3A4(void);
void func_0042325C(void);
void func_00299368(s32 a);

s32 func_00435EB8(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x40:
        D_80146894 = 0;
        func_002A3304();
        func_0025E3A4();
        return 0;
    case 0x3C:
        D_80146894 = 0;
        func_0042325C();
        return 0;
    case 0x41:
        func_00299368(0x1F);
        return 0;
    case 0x3E:
        func_00299368(0x20);
        return 0;
    default:
        return 0;
    }
}
