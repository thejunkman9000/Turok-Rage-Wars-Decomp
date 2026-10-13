#include "o04_types.h"
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_0042EB68(s32 a);
void func_00423304(void);
void func_0029A8A8(void);
s32 func_auto_00423654(void) {
    s32 s0;
    func_0029A73C();
    s0 = 1;
    switch (func_0029AA08()) {
    case 0x1BF:
        func_0042EB68(-1);
        break;
    case 0x1B9:
        func_0042EB68(0xD);
        break;
    case 0x1BE:
        func_0042EB68(0xC);
        break;
    case 0x1C0:
        func_0042EB68(0xE);
        break;
    default:
        s0 = 0;
        break;
    }
    if (s0 == 1) {
        func_00423304();
        func_0029A8A8();
    }
    return 0;
}
