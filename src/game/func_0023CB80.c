#include "p2_types.h"

void func_0023CB80(DList *l, DNode *n) {
    n->prev = NULL;
    n->next = l->head;
    if (l->head != NULL) {
        l->head->prev = n;
    }
    l->head = n;
    if (l->tail == NULL) {
        l->tail = n;
    }
}