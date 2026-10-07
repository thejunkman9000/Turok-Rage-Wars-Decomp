#include "p4_types.h"
typedef struct P4LN { u8 pad0[4]; struct P4LN *next; u8 pad8[0x1C - 8]; s32 f1C; s32 f20; } P4LN;
typedef struct { u8 pad0[0x7528]; P4LN *head; } P4LMgr;
P4LN *func_002A7440(P4LMgr *m, s32 a, s32 b) {
    P4LN *n;
    for (n = m->head; n != NULL; n = n->next) {
        if (n->f1C == a && n->f20 == b) {
            return n;
        }
    }
    return NULL;
}
