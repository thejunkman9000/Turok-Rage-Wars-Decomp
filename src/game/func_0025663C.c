#include "b12_types.h"

void func_00255E78(B12List *l, B12QNode *n);
void func_00255C58(B12List *l, B12QNode *n);

B12QNode *func_0025663C(B12Ctx *c) {
    u32 mask = __osDisableInt();
    B12QNode *n = (B12QNode *)c->freeList.head;
    if (n) {
        func_00255E78(&c->freeList, n);
        n->state = 1;
        func_00255C58(&c->usedList, n);
    }
    __osRestoreInt(mask);
    return n;
}
