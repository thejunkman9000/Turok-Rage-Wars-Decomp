#include "b11_types.h"

B11Node *func_0028FD94(void *node, s32 idx);
void func_0026E5E0(void *a, s32 b, s32 c, Obj *d, void *e);

void func_0024C5C4(Obj *a, void *node, s32 bit, s32 c) {
    B11Node *n3;
    void *p;
    s32 s1;
    if (a->unk17C & (1 << bit)) {
        n3 = func_0028FD94(node, 3);
        s1 = n3->unk4;
        if (s1 != 0) {
            p = n3->unk8;
            func_0026E5E0(p, s1, c, a, func_0028FD94(node, 5));
        }
    }
}