#include "b17_types.h"

void func_00279578(DLList *l, DLNode *n) {
    if (l->count == 0) {
        l->head = n;
        l->tail = n;
        n->prev = 0;
        n->next = 0;
    } else {
        n->prev = l->tail;
        n->next = 0;
        l->tail->next = n;
        l->tail = n;
    }
    l->count++;
}
