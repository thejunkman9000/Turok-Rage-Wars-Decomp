#include "b20_types.h"

void func_00290930(NodeOwner *o, Node *n);
void func_00246174(Node *n);

Node *func_002908A0(NodeOwner *o) {
    Node *n;
    if (o->freeList == 0) {
        func_00290930(o, o->tail);
    }
    n = o->freeList;
    o->freeList = n->next;
    if (o->head != 0) {
        o->head->prev = n;
    }
    n->next = o->head;
    n->prev = 0;
    o->head = n;
    if (o->tail == 0) {
        o->tail = n;
    }
    n->flags |= 1;
    func_00246174(n);
    n->unk1C8 = 0;
    return n;
}
