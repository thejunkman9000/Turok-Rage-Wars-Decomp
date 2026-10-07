#include "b11_types.h"

extern u8 D_800C8E98[];
extern u8 D_800C8EB0[];
extern u8 D_800C8EC4[];
void func_0026D7F4();
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
s32 func_0028FE08(s32 a, s32 b, s32 c);
void func_002537D8(s32 a, void *p);
s32 *func_00254094(s32 a, s32 **out, s32 b, void *c, s32 d);
s32 func_0028FE1C(s32 *node, s32 a, s32 b, void *c);
void func_0026E1F8(s32 *h);

static inline s32 *get_h(ObjH *a, s32 idx) {
    s32 *h;
    s32 *p;
    s32 *sp28;
    s32 n;
    if (idx != a->h54) {
        h = func_002518DC(0, a->h50, a->h50, 0x18, 0, 0, 0, D_800C8E98 + 4, 1);
        if (h != 0) {
            n = func_0028FE08(*h, a->h50, 1);
            func_002537D8(0, h);
            p = func_00254094(0, &sp28, n, D_800C8EB0, 1);
            if (p != 0) {
                a->h58 = func_0028FE1C(sp28, n, idx % *sp28, &a->h5C);
                a->h54 = idx;
                func_002537D8(0, p);
            }
        }
    }
    if (a->h58 != 0) {
        return func_002518DC(0, a->h58, a->h58, a->h5C, 0, 0, func_0026D7F4, D_800C8EC4, 0);
    }
    return 0;
}

void func_0024F0F8(ObjH *a) {
    s32 *h = get_h(a, a->unk1);
    if (h != 0) {
        func_0026E1F8(h);
        func_002536F4(0, h);
    }
}
