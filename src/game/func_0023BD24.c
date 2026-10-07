
#include "b09_types.h"

extern B09SlotA D_80103F28[];
extern B09LNode D_80103B50[];
extern B09List D_80103E20;
extern u8 D_80156000[];
void osMapTLB(s32 index, s32 pm, void *vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid);
s32 func_0023BC64(void);

static inline void m03_unlink(B09LNode *n) {
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        D_80103E20.head = n->next;
        n->next->prev = NULL;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    } else {
        D_80103E20.tail = n->prev;
        n->prev->next = NULL;
    }
}

static inline void m03_push(B09LNode *n) {
    n->next = NULL;
    n->prev = D_80103E20.tail;
    if (D_80103E20.tail != NULL) {
        D_80103E20.tail->next = n;
    }
    D_80103E20.tail = n;
    if (D_80103E20.head == NULL) {
        D_80103E20.head = n;
    }
}

void func_0023BD24(s16 slot, B09LNode *n, s32 unused, u8 *pair) {
    u8 *p = pair;
    s32 idx;
    B09LNode *q;
    if (slot & 1) {
        p = pair - 1;
    }
    if (p[0] != 0xFF && D_80103B50[p[0]].tlb != 0xFF) {
        idx = D_80103B50[p[0]].tlb;
        D_80103F28[(s16)idx].b = n->id;
    } else if (p[1] != 0xFF && D_80103B50[p[1]].tlb != 0xFF) {
        idx = D_80103B50[p[1]].tlb;
        D_80103F28[(s16)idx].a = n->id;
    } else {
        idx = func_0023BC64();
        if (slot & 1) {
            D_80103F28[(s16)idx].b = n->id;
            if (p[0] != 0xFF) {
                q = &D_80103B50[p[0]];
                D_80103F28[(s16)idx].a = q->id;
                q->tlb = idx;
                m03_unlink(q);
                m03_push(q);
            }
        } else {
            D_80103F28[(s16)idx].a = n->id;
            if (p[1] != 0xFF) {
                q = &D_80103B50[p[1]];
                D_80103F28[(s16)idx].b = q->id;
                q->tlb = idx;
                m03_unlink(q);
                m03_push(q);
            }
        }
        D_80103F28[(s16)idx].key = slot & 0xFFFE;
    }
    n->slot = slot;
    n->tlb = idx;
    *pair = n->id;
    osMapTLB((s16)idx, 0, (void *)(D_80103F28[(s16)idx].key << 12),
             D_80103F28[(s16)idx].a != 0xFF ? ((u32)D_80156000 & 0x3FFFFFF) + (D_80103F28[(s16)idx].a << 12) : -1,
             D_80103F28[(s16)idx].b != 0xFF ? ((u32)D_80156000 & 0x3FFFFFF) + (D_80103F28[(s16)idx].b << 12) : -1, 7);
}

