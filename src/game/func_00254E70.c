#include "b12_types.h"

extern B12Node *D_801050F8;
extern u8 D_8010510C[];
s32 func_002512C8(s32 a, s32 b, s32 c);
void func_00255E78(void *list, B12Node *n);
void func_00255C58(void *list, B12Node *n);

static inline B12Node *take(s32 v) {
    B12Node *n = D_801050F8;
    if (n) {
        func_00255E78(&D_801050F8, n);
        n->unk10 = v;
        func_00255C58(D_8010510C, n);
    }
    return n;
}

B12Node *func_00254E70(s32 unused, u32 flags) {
    B12Node *n = take(1);
    if (n == 0) {
        s32 one = 1;
        flags &= 0x10;
        for (;;) {
            if (func_002512C8(0, 2, flags == 0) == 0) {
                return n;
            }
            n = take(one);
            if (n != 0) {
                break;
            }
        }
    }
    return n;
}