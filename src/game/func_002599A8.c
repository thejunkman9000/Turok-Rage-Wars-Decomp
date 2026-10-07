#include "b13_types.h"

void func_002599A8(SndQueue *q, s32 a) {
    SndNode *n;
    SndNode *next;
    for (n = (SndNode *)q->active.link.next; n != &q->active; n = next) {
        next = (SndNode *)n->link.next;
        if (n->body.tag == a) {
            n->link.prev->next = n->link.next;
            n->link.next->prev = n->link.prev;
            n->link.prev = q->free.link.prev;
            n->link.next = &q->free.link;
            q->free.link.prev->next = &n->link;
            q->free.link.prev = &n->link;
        }
    }
}
