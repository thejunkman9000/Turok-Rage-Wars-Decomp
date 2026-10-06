#include "p4_types.h"
extern u8 D_8011FE88[];
extern s32 D_8014694C;
void func_00293318(s32 a, s32 b, s32 c);
void func_00286A78(void *a, s32 b, s32 c);
void func_00299368(s32 a);
void func_0025E2F4(s32 a);
void func_002943B8(s32 a) {
    func_00293318(a, 0, 0);
    func_00286A78(D_8011FE88, 0, 0);
    D_8014694C = 0;
    func_00299368(0x18);
    func_0025E2F4(0x34);
}
