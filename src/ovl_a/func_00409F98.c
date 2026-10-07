#include "o01_types.h"

extern u8 D_8011FE88[];
extern s32 D_8013B2C8;
void func_002647A8();
void func_0044E178();

void func_00409F98(s32 a, s32 b) {
    func_002647A8(b);
    func_0044E178(D_8011FE88, D_8013B2C8, 2);
}
