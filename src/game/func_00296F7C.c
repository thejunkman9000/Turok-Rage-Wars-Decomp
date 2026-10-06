#include "common.h"

typedef struct B21Node {
    s32 unk0;
} B21Node;

typedef struct B21Holder {
    B21Node *node;
} B21Holder;

typedef struct B21Triple {
    s32 unk0;
    s32 unk4;
    s32 *unk8;
} B21Triple;

s32 *func_0028FD94(B21Node *n, s32 idx);

void func_00296F7C(B21Holder *h, B21Triple *t) {
    B21Node *n = h->node;
    if (n->unk0 != 0) {
        t->unk8 = func_0028FD94(n, 0);
        t->unk0 = *func_0028FD94(n, 1);
        t->unk4 = *func_0028FD94(n, 2);
    } else {
        t->unk8 = NULL;
        t->unk0 = 0;
        t->unk4 = 0;
    }
}
