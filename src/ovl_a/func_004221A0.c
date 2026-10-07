#include "o03_types.h"
extern u8 D_80145088[];
extern u8 D_8011FE88[];
void func_00422218(void);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
s32 func_004030E0(s32 a);
void func_0044E178(void *p, s32 a, s32 b);
s32 func_0025471C();
void func_0025470C(s32 a);
void func_004221A0(void) {
    func_00422218();
    func_0044AFC0(D_80145088, 1);
    func_0044A600(D_80145088 - 0x48, 1, 0);
    func_0044E178(D_8011FE88, ~func_004030E0(0x27D), 0);
    if (func_0025471C() == 0) {
        func_0025470C(1);
    }
}
