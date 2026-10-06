#include "p2_types.h"

extern List D_80104584;
void func_00255D10(List *l, PNode *at, PNode *n);
void func_00255CB4(List *l, PNode *n);

void func_00254C10(void *unused, PNode *n) {
    PNode *c;

    for (c = D_80104584.head; c != NULL; c = c->next) {
        if (c->key > n->key) {
            func_00255D10(&D_80104584, c, n);
            break;
        }
    }
    if (c == NULL) {
        func_00255CB4(&D_80104584, n);
    }
    n->fC |= 0x1000;
}