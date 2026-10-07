#include "b17_types.h"

void func_002795C0(DLList *l, DLNode *n) {
    if (n->next) {
        n->next->prev = n->prev;
    }
    if (n->prev) {
        n->prev->next = n->next;
    }
    if (l->head == n) {
        l->head = n->next;
    }
    if (l->tail == n) {
        l->tail = n->prev;
    }
    l->count--;
}
