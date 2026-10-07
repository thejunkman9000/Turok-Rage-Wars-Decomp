#include "b13_types.h"

s32 func_00259AD8(SndQueue *q, s32 a) {
    SndNode *n;
    SndNode *next;
    for (n = (SndNode *)q->active.link.next; n != &q->active; n = next) {
        next = (SndNode *)n->link.next;
        if (n->body.tag == a) {
            return 1;
        }
    }
    return 0;
}
