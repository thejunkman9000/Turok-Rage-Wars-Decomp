#include "b12_types.h"

B12Node *func_00251448(s32 a, u32 flags);
s32 func_00254B2C(s32 a, s32 b, s32 c, u32 d);
void func_00254C10(s32 a, B12Node *n);
void func_00254A70(s32 a, B12Node *n);

B12Node *func_00254858(s32 unused, s32 a1, u32 flags) {
    B12Node *n = func_00251448(0, flags);
    if (n) {
        n->refs++;
        n->flags |= 0x100;
        n->key = func_00254B2C(0, a1, (flags >> 5) & 1, flags);
        if (n->key) {
            n->unk4 = a1;
            n->flags |= flags;
            func_00254C10(0, n);
            return n;
        }
        n->refs--;
        if (n->refs == 0) {
            n->flags &= ~0x100;
        }
        func_00254A70(0, n);
        n = 0;
    }
    return n;
}
