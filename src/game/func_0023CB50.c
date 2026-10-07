#include "b09_types.h"

void func_0023CB50(B09List *l, B09LNode *n) {
    n->next = NULL;
    n->prev = l->tail;
    if (l->tail != NULL) {
        l->tail->next = n;
    }
    l->tail = n;
    if (l->head == NULL) {
        l->head = n;
    }
}
