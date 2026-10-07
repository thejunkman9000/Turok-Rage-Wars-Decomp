#include "b12_types.h"

extern u8 D_8010510C[];
extern u8 D_801050F8[];
void func_00255428(s32 a);
void func_00255E78(void *list, B12Node *n);
void func_00255C58(void *list, B12Node *n);

void func_00254D70(s32 unused, B12Node *n) {
    if (n->link) {
        func_00255428(n->link->refs);
        n = n->link;
        func_00255E78(D_8010510C, n);
        n->unk10 = 0;
        func_00255C58(D_801050F8, n);
    }
}
