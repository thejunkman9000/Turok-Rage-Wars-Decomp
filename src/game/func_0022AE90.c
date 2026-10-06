#include "b06_types.h"

s32 func_0025C97C(s32 a, s32 b, u8 *c, u8 *d, u8 *e);
void func_0025CA44(s32 a, s32 b);
s32 func_0025CC8C();
extern s32 D_8013B29C;
extern s32 D_80146894;

void func_0022AE90(u8 *a, s32 b) {
    u8 *p;
    if (B6F(a, u8 *, 0x5DC) != NULL) {
        p = B6F(a, u8 *, 0x5DC) + 0x128;
    } else {
        p = a + 8;
    }
    if (D_8013B29C == 0 && D_80146894 == 0) {
        func_0025CA44(func_0025CC8C(), B6F(a, s32, 0x11BC));
        B6F(a, s32, 0x11BC) = func_0025C97C(func_0025CC8C(), b, p, p, a);
    }
}
