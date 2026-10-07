#include "o01_types.h"

void *func_0028FD94(void *tree, s32 idx);

s32 func_00403B70(void *t) {
    O01Node *x = func_0028FD94(t, 0);
    O01Node *y = func_0028FD94(t, 2);
    s32 a = x->unk4 * 9;
    s32 b = y->unk4 * 9;
    return (b + a) * 4 + 0x30;
}
