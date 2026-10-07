#include "o04_types.h"
extern O04ModeS53C0 *D_800E53C0;
extern s32 D_80146894[];
extern s32 D_80146918;
extern s32 D_801468F4;
void func_0029A73C(void);
s32 func_0043C4E8(void *p);
s32 func_0029AA08(void);
void func_0043C458(void *p);
void func_00299368(s32 a);
void func_00435190(s32 a);
s32 func_0042B108(void);
void func_0042EB68(s32 a);
s32 func_0042D968(void) {
    func_0029A73C();
    if (func_0043C4E8(D_800E53C0) == 1) {
        return 0;
    }
    D_80146894[0] = 0;
    switch (func_0029AA08()) {
    case 0x237:
        if (((u8 *)D_80146894)[-0x5BF] == 0) {
            func_0043C458(D_800E53C0);
            D_800E53C0->unk1C = 0;
        } else {
            D_80146918 = 0;
            D_801468F4 = 0;
            func_00299368(0xF);
        }
        break;
    case 0x238:
        func_00435190(5);
        func_00299368(0x13);
        break;
    case 0x23C:
        if (func_0042B108() == 1) {
            func_0042EB68(0x21);
            return 0;
        }
        func_00299368(((u8 *)D_80146894)[-0x5BF] == 0 ? 0x14 : 0xF);
        break;
    }
    return 0;
}
