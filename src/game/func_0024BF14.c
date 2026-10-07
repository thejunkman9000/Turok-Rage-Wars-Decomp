#include "b11_types.h"

extern f32 D_800C8C4C;
extern u8 D_800C8BD8[];
f32 Trunc16ToF32(u16 x);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *h, s32 i);
B11Node *func_0028FD94(s32 node, s32 idx);
void func_002536F4(s32 a, void *p);

f32 func_0024BF14(Obj *a) {
    f32 r = D_800C8C4C;
    s32 *h;
    if (a->flags & 0x40000) {
        h = func_002518DC(0, a->unkC4, a->unkC4, a->unkD0, 4, 0, 0, D_800C8BD8, 1);
        if (h != 0) {
            r = Trunc16ToF32(func_0028FD94(*h, 0)->unk1E);
            func_002536F4(0, h);
        }
    }
    return r;
}
