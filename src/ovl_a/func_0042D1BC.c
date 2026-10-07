#include "o04_types.h"
extern O04GFlags D_801468A0[];
s32 func_0042B108(void);
s32 func_0042AEB8(void);
void func_00299368(s32 a);
void func_0042E080(void);
void func_0042D1BC(void) {
    D_801468A0->unk78 = 0;
    D_801468A0->unk54 = 0;
    if (func_0042B108() == 0 || func_0042AEB8() == 0) {
        func_00299368(0x14);
    } else {
        func_0042E080();
    }
}
