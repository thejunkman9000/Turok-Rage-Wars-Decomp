#include "p1_types.h"
extern s32 D_800CD394;
s32 func_00200500();
void func_00200538(s32 mask);
s32 func_002017E8(s32 a, s32 b, s32 c, s32 d);
s32 func_00201A74(void) {
    s32 mask;
    s32 r;
    mask = func_00200500();
    D_800CD394 = 1;
    r = func_002017E8(0x101, 0, 0, 0);
    func_00200538(mask);
    return r;
}
