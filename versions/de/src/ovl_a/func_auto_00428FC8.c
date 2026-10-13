#include "o04_types.h"
extern u8 D_80145088[];
extern u8 D_80145040[];
extern u8 D_8011FE88[];
void func_0029A73C(void);
s32 func_0029AA08(void);
s32 func_0029A9A0(s32 a);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
s32 func_0025471C(void);
void func_0025470C(s32 a);
void func_0042EB68(s32 a);
void func_0029A8A8(void);
s32 func_auto_00428FC8(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x1D5:
        if (func_0029A9A0(0) == 0x16) {
            func_0044AFC0(D_80145088, 0);
            func_0044A600(D_80145088 - 0x48, 0, 0);
            func_00286A78(D_8011FE88, 0, 0);
            if (func_0025471C() == 0) {
                func_0025470C(1);
            }
            *(s32 *)(D_80145088 + 0x17F0) = 8;
            switch (D_80145088[0x124D]) {
            case 0:
                func_0042EB68(0x14);
                break;
            case 1:
                func_0042EB68(0xA);
                break;
            case 2:
                func_0042EB68(0xF);
                break;
            case 3:
            case 4:
                func_0042EB68(0xA);
                break;
            default:
                func_0042EB68(3);
                break;
            }
        } else {
            func_0042EB68(3);
        }
        break;
    case 0x1D6:
        if (func_0029A9A0(0) == 0xB) {
            func_0042EB68(0xB);
        } else {
            func_0042EB68(-1);
        }
        break;
    default:
        goto out;
    }
    func_0029A8A8();
    return 0;
    out:
    return 0;
}

