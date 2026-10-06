#include "p4_types.h"
typedef struct { u8 pad0[0x3C00]; P4Node *head; P4Node *cur0; P4Node *cur1; } P4List;


void func_00290930(P4List *l, P4Node *n) {
    if (n->flags & 1) {
 n->flags &= ~1;
 if (n->counter != NULL) (*n->counter)--;
 if (n->prev != NULL) n->prev->next = n->next;
 if (n->next != NULL) n->next->prev = n->prev;
 if (l->cur0 == n) l->cur0 = n->next;
 if (l->cur1 == n) l->cur1 = n->prev;
 n->next = l->head;
 n->prev = NULL;
 l->head = n;
}
}
