#include "p4_types.h"
typedef struct { u8 pad0[0xC50]; P4Node *list[128]; s32 count; } P4Mgr;
P4Node *func_0028CC10(P4Mgr *m, P4Node *key) {
    s32 i;
    P4Node *found;
    s32 n = m->count;
    P4Node **list = m->list;
    for (i = 0, found = NULL; i < n; i++) {
        P4Node *e = list[i];
        if (e->prev == key) {
            found = e;
            found->prev = NULL;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        P4Node *e = list[i];
        if (e->prev == key) {
            e->prev = found;
        }
    }
    return found;
}
