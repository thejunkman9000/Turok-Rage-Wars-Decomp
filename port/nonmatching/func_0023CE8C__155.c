#include "b09_types.h"

extern B09List D_80103E20;
extern OSMesgQueue D_80103CD0;
void func_0023BD24(s16, B09LNode *, u8, u8 *);

static inline void list_push_back(B09List *l, B09LNode *n) {
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

static inline void list_push_front(B09List *l, B09LNode *n) {
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

void func_0023CE8C(B09LoadReq *r) {
    if (*r->data == 0xFF) {
        list_push_back(&D_80103E20, r->node);
        func_0023BD24(r->slot, r->node, r->task->b17, r->data);
        osInvalDCache((void *)((u16)r->slot << 12), 0x1000);
        osInvalICache((void *)((u16)r->slot << 12), 0x1000);
    } else {
        list_push_front(&D_80103E20, r->node);
    }
    r->task->state = 2;
    osStartThread((OSThread *)r->task);
    osSendMesg(&D_80103CD0, (OSMesg)r, 1);
}
