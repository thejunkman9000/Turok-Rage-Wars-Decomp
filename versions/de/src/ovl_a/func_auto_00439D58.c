#include "o05_types.h"

extern u8 D_801462D5;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_00299368(s32 a);
void func_0042EB68(s32 a);
void func_0029A8A8(void);

s32 func_auto_00439D58(void) {
    s32 a;
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x3D4:
        switch (D_801462D5) {
        case 0:
            a = 0x14;
            break;
        case 1:
            a = 3;
            break;
        case 2:
            a = 0xF;
            break;
        case 3:
        case 4:
            a = 0xA;
            break;
        default:
            a = 3;
            break;
        }
        func_00299368(a);
        return 0;
    case 0x3D5:
        func_0042EB68(-1);
        func_0029A8A8();
        return 0;
    default:
        return 0;
    }
}
