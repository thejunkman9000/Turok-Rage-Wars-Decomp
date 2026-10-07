#include "b13_types.h"

void func_00259B10(SndLink *head, SndLink *n) {
    n->prev = head->prev;
    n->next = head;
    head->prev->next = n;
    head->prev = n;
}
