#include "p2_types.h"

void func_00255E78(List *l, PNode *n);
void func_00255CB4(List *l, PNode *n);

PNode *func_0023B89C(Player *o) {
    PNode *n = o->listA.head;

    if (n != NULL) {
        func_00255E78(&o->listA, n);
        func_00255CB4(&o->listB, n);
    }
    return n;
}