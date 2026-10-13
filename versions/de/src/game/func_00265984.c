#include "b14_types.h"
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *h, s32 i);
void func_002536F4(s32 a, s32 *p);
extern u8 D_800C9478[];
s32 func_00265984(s32 off) {
    s32 *p;
    s32 r;
    p = func_002518DC(0, 0x28BB00, 0x28BB00, 0x20, 0x10, 0, 0, D_800C9478, 1);
    r = *(s32 *)(*p + off);
    func_002536F4(0, p);
    return r;
}
