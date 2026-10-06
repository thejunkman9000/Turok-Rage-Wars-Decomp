#include "p3_types.h"

extern s32 D_8011FE88;
void func_0028D8E8(void);
void func_402FB4(s32 a, s32 b);

void func_00279024(s32 a, s32 b, s32 c) {
    if (D_8011FE88 == 4) {
        func_0028D8E8();
        func_402FB4(a, c);
    }
}
