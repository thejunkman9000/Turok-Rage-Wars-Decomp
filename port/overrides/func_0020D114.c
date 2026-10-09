#include "b02_types.h"
extern int port_verbose(void); extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);

static inline B2Node *find(B2Mgr *m, s32 key) {
    B2Node *n;

    for (n = m->head; n != NULL; n = n->next) {
        if (n->id == key) {
            return n;
        }
    }
    return NULL;
}

void func_0020D114(B2Mgr *m, s32 *out, s32 n) {
    s32 i;
    s32 done;
    B2Node *node;

    for (i = 0; i < n; i++) {
        out[i] = -1;
    }
    done = 0;
    node = find(m, m->unk18);
    if (node->link30 == NULL) {
        out[0] = node->id;
        return;
    }
    if (port_verbose()) fprintf(__acrt_iob_func(2), "20D114: mgr %p key %d node %p id %d link30 %p n=%d\n", m, m->unk18, node, node ? node->id : -999, node ? node->link30 : 0, n);
    if (port_verbose()) { int guard = 0; B2Node *q = node; while (q && guard < 40) { fprintf(__acrt_iob_func(2), "   chain %d: %p id %d -> %p\n", guard, q, q->id, q->link30); q = q->link30; guard++; } }
    while (!done) {
        for (i = n - 1; i > 0; i--) {
            out[i] = out[i - 1];
        }
        out[0] = node->id;
        node = node->link30;
        if (node->link30 == NULL) {
            done = 1;
        }
    }
}
