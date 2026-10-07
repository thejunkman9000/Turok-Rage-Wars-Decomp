#include "b12_types.h"

extern u8 D_801051A0[];
void func_00254D70(s32 a, B12Node *n);
void func_00255ACC(void *list, s32 key);
void func_00254A70(s32 a, B12Node *n);

void func_00254930(s32 unused, B12Node *n) {
    n->flags &= ~2;
    while (n->refs != 0) {
        n->refs--;
        if (n->refs == 0) {
            n->flags &= ~0x100;
        }
    }
    if (!(n->flags & 0x702)) {
        func_00254D70(0, n);
        func_00255ACC(D_801051A0, n->key);
        func_00254A70(0, n);
    }
}
