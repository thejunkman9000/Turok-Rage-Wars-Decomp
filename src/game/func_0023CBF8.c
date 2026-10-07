#include "b09_types.h"

extern B09LNode *D_80103E20;
extern B09LNode *D_80103E24;
void func_0023C074(B09LNode *);
B09Region *func_0023CBB0(u32 addr);

B09LNode *func_0023CBF8(void) {
    B09LNode *n = D_80103E20;
    B09Region *r;
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        ((B09List *)&D_80103E20)->head = n->next;
        n->next->prev = NULL;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    } else {
        ((B09List *)&D_80103E20)->tail = n->prev;
        n->prev->next = NULL;
    }
    func_0023C074(n);
    if (n->slot != 0xFFFF) {
        r = func_0023CBB0(n->slot);
        r->data[n->slot - r->base] = 0xFF;
        n->slot = 0xFFFF;
    }
    n->unkC = 0;
    return n;
}
