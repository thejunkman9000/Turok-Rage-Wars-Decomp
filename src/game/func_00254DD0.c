#include "b12_types.h"

extern B12List D_801050F8[];
void func_00255E78(void *list, B12Node *n);
void func_00255C58(void *list, B12Node *n);

B12Node *func_00254DD0(void) {
    B12Node *n = (B12Node *)D_801050F8[0].head;
    if (n) {
        func_00255E78(&D_801050F8[0], n);
        n->unk10 = 1;
        func_00255C58(&D_801050F8[1], n);
    }
    return n;
}
