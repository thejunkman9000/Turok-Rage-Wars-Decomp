#include "b02_types.h"

void func_0020C5A0(B2Mgr *m, B2Node *n);

static inline B2Node *find(B2Mgr *m, s32 key) {
    B2Node *n;

    for (n = m->head; n != NULL; n = n->next) {
        if (n->id == key) {
            return n;
        }
    }
    return NULL;
}

void func_0020D0CC(B2Mgr *m, s32 key) {
    func_0020C5A0(m, find(m, key));
}
