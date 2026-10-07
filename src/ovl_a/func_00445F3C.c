#include "o06_types.h"
extern void func_0025E3C8(void);
extern s32 func_0025E2E4(void);
extern void func_0025E2F4(s32 a);
extern void func_0025E3A4(void);
extern void func_0025E2BC(s32 a);
extern void func_00264A1C(void);
extern void func_00442934(s32 a, s32 b, void *c);
extern s32 D_800E63B8;
extern s32 D_800E63B0;
extern s32 D_800E63B4;
extern u8 D_00451F58[];
s32 func_00445F3C(s32 a, s32 b, s32 c) {
    func_0025E3C8();
    D_800E63B0 = func_0025E2E4();
    func_0025E2F4(D_800E63B8);
    func_0025E3A4();
    func_0025E2BC(1);
    D_800E63B4 = 1;
    func_00264A1C();
    func_00442934(c, b, D_00451F58);
    return 1;
}
