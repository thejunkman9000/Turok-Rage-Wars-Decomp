#include "b11_types.h"

extern u8 D_800C8920[];
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *h, s32 i);
B11Node *func_0028FD94(s32 node, s32 idx);
void func_002536F4(s32 a, void *p);

s32 func_0024C284(Obj *a, s32 i) {
    s32 *h;
    s32 r;
    if (a->flags & 0x40000) {
        h = func_002518DC(0, a->unkC4, a->unkC4, a->unkD0, 4, 0, 0, D_800C8920, 1);
        if (h != 0) {
            r = func_0028FD94(*h, 1)->unk8[i];
            func_002536F4(0, h);
            return r;
        }
    }
    return -1;
}
