#include "o06_types.h"
extern f32 D_801468B0;
extern u8 D_8011FAC0[];
extern void func_0044E9A0(void *a);
s32 func_0043EF4C(void) {
    if (D_801468B0 <= 0.0f) { func_0044E9A0(D_8011FAC0); return 1; }
    return 0;
}
