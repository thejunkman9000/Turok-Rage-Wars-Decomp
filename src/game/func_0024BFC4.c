#include "b11_types.h"

extern u8 D_800C8C18[];
extern u8 D_800C8C2C[];
void func_0026D814();
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
s32 func_0028FE1C(s32 *node, s32 a, s32 b, void *c);
void func_002536F4(s32 a, void *p);

s32 *func_0024BFC4(Obj *a, s32 idx) {
    s32 *h;
    if (idx < 0) {
        return 0;
    }
    if (idx != a->unkD8) {
        h = func_002518DC(0, a->unkCC, a->unkCC, a->unkD4, 0, 0, 0, D_800C8C18, 1);
        if (h != 0) {
            a->unkDC = func_0028FE1C((s32 *)*h, a->unkCC, idx % *(s32 *)*h, &a->unkE0);
            a->unkD8 = idx;
            func_002536F4(0, h);
        }
    }
    if (a->unkDC != 0) {
        return func_002518DC(0, a->unkDC, a->unkDC, a->unkE0, 0, 0, func_0026D814, D_800C8C2C, 0);
    }
    return 0;
}
