#include "b17_types.h"

#define LIST_APPEND(l, n)               \
    if ((l)->count == 0) {              \
        (l)->head = (n);                \
        (l)->tail = (n);                \
        (n)->prev = 0;                  \
        (n)->next = 0;                  \
    } else {                            \
        (n)->prev = (l)->tail;          \
        (n)->next = 0;                  \
        (l)->tail->next = (n);          \
        (l)->tail = (n);                \
    }                                   \
    (l)->count++

#define LIST_UNLINK(l, n)               \
    if ((n)->next) {                    \
        (n)->next->prev = (n)->prev;    \
    }                                   \
    if ((n)->prev) {                    \
        (n)->prev->next = (n)->next;    \
    }                                   \
    if ((l)->head == (n)) {             \
        (l)->head = (n)->next;          \
    }                                   \
    if ((l)->tail == (n)) {             \
        (l)->tail = (n)->prev;          \
    }                                   \
    (l)->count--

void func_00279764(NodePool *p, DLNode *n) {
    DLList *u = &p->usedl;
    LIST_UNLINK(u, n);
    LIST_APPEND(&p->freel, n);
}
