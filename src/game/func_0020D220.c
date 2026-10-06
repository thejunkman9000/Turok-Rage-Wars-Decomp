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

void func_0020D220(B2Mgr *m, s32 key) {
    s32 i;

    for (i = 0; i < 64; i++) {
        if (m->slots[i] == -1) {
            m->slots[i] = key;
            find(m, key)->unk2C = 1;
            return;
        }
    }
}
