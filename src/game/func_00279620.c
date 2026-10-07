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

void func_00279620(NodePool *p, DLNode *mem, s32 stride, u32 n) {
    
    DLList *u;
    p->freel.head = 0;
    p->freel.tail = 0;
    p->freel.count = 0;
    u = &p->usedl;
    u->head = 0;
    u->tail = 0;
    u->count = 0;
    while (n--) {
        LIST_APPEND(&p->freel, mem);
        mem = (DLNode *)((u8 *)mem + stride);
    }
}
