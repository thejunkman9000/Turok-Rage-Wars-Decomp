#include "b06_types.h"

extern u8 D_8011FE88[];
s32 func_002866F8(u8 *a);

s32 func_0022AE18(u8 *a, Vec3f *v) {
    s32 r = func_002866F8(D_8011FE88);
    B6F(a, Vec3f, 0x8) = *v;
    B6F(a, s32, 0x14) = r;
    B6F(a, Vec3f, 0x2F0) = *v;
    B6F(a, s32, 0x2FC) = r;
    return r != 0;
}
