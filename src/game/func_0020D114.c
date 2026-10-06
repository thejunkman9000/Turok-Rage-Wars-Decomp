#include "b02_types.h"

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
