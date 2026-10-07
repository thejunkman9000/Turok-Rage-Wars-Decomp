#include "o04_types.h"
extern O04ModeS4518 *D_800E4518;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_002A338C(void);
void func_0043C458(void *p);
void func_0040E958(void *p, s32 a);
void func_00245B18(void);
void func_0042EB68(s32 a);
s32 func_0042AEB8(void);
void func_00423370(void);
s32 func_00423A00(void) {
    s32 s0;
    func_0029A73C();
    s0 = 1;
    switch (func_0029AA08()) {
    case 0x37D:
        func_002A338C();
        func_0043C458(D_800E4518);
        D_800E4518->unk1C = 1;
        D_800E4518->unk60 = -1;
        func_0040E958(D_800E4518->unk44, 1);
        func_0040E958(D_800E4518->unk4C, 1);
        func_00245B18();
        break;
    case 0x380:
        func_0042EB68(0x17);
        break;
    case 0x37E:
        func_002A338C();
        if (func_0042AEB8() == 0) {
            D_800E4518->unk30 = 5;
            D_800E4518->unk34 = 4;
            D_800E4518->unk60 = 0x14;
        } else {
            func_0043C458(D_800E4518);
            D_800E4518->unk1C = 1;
            D_800E4518->unk60 = 0;
        }
        break;
    case 0x377:
        func_0042EB68(0xD);
        break;
    case 0x37C:
        func_0042EB68(0xC);
        break;
    case 0x37F:
        func_0042EB68(0xE);
        break;
    default:
        s0 = 0;
        break;
    }
    if (s0 == 1) {
        func_00423370();
    }
    return 0;
}
