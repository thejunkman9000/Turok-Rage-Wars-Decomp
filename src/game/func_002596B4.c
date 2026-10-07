#include "b13_types.h"

SndLink *func_002596B4(SndLink *n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    return n;
}
