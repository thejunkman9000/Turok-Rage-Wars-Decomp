#include "o03_types.h"
extern u8 D_80145088[];
extern u8 D_8011FE88[];
void func_00245B18();
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
s32 func_0025471C();
void func_0025470C(s32 a);
void func_00245A00();
void func_00245A10(s32 a);
void func_00245A20();
void func_00422050(void) {
    func_00245B18();
    func_0044AFC0(D_80145088, 0);
    func_0044A600(D_80145088 - 0x48, 0, 0);
    func_00286A78(D_8011FE88, 0x24, 0);
    if (func_0025471C() == 0) {
        func_0025470C(1);
    }
    func_00245A00();
    func_00245A10(0);
    func_00245A20();
}
