#include "b13_types.h"

void func_0025B718(SndVoice *v, SndMgr *m, s32 idx);

static inline void qinit(SndNode *n, SndMgr *m) {
    n->link.next = &n->link;
    n->link.prev = &n->link;
    func_0025B718(&n->body, m, -1);
}

static inline void qadd(SndLink *head, SndLink *n) {
    SndLink *p = head->prev;
    n->next = head;
    n->prev = p;
    head->prev->next = n;
    head->prev = n;
}

void func_002596D4(SndQueue *q, SndMgr *m) {
    s32 i;
    q->owner = m;
    qinit(&q->active, m);
    qinit(&q->free, m);
    for (i = 0; i < 32; i++) {
        qinit(&q->nodes[i], m);
        qadd(q->free.link.next, &q->nodes[i].link);
    }
}


