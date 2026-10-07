#include "common.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);

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
    { static int c; if (c++ < 6) { s32 *w = (s32 *)n; fprintf(__acrt_iob_func(2), "f296F7C h=%p n=%p words %08x %08x %08x %08x %08x\n", h, n, w[0], w[1], w[2], w[3], w[4]); } }
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
