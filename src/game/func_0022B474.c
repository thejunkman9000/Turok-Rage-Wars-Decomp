#include "b06_types.h"

extern u8 D_8011FE88[];
extern u8 D_800D0EF8[];
s32 func_0028B1F8(u8 *a, s32 b);
s32 func_0028C174(u8 *a, s32 b);
void func_0026DF30(s32 a, u8 *b, u8 *c, s32 d, s32 e);

void func_0022B474(u8 *a) {
    s32 r;
    if (B6F(a, s32, 0x120C) != 0) {
        r = func_0028B1F8(D_8011FE88, 0xC84);
    } else {
        r = func_0028B1F8(D_8011FE88, 0xC85);
    }
    if (r != -1) {
        func_0026DF30(func_0028C174(D_8011FE88, r), a + 0x1600, D_800D0EF8, 0, -1);
    }
}
