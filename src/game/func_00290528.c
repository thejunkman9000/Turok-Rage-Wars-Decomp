#include "b20_types.h"

extern Node *D_80135200;
extern Node *D_80135204;
extern Node *D_80135208;

void func_00290528(Node *n) {
    u32 f = n->flags;
    Node *h;
    if (f & 1) {
        n->flags = f & ~1;
        if (n->counter != 0) {
            *n->counter = *n->counter - 1;
        }
        do {
        if (n->prev != 0) {
            n->prev->next = n->next;
        }
        if (n->next != 0) {
            n->next->prev = n->prev;
        }
        if (D_80135204 == n) {
            D_80135204 = n->next;
        }
        if (D_80135208 == n) {
            D_80135208 = n->prev;
        }
            h = D_80135200;
        } while (0);
        n->prev = 0;
        n->next = h;
        D_80135200 = n;
    }
}
