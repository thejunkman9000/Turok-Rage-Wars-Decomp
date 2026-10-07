#include "b12_types.h"

void func_00255E78(B12List *l, B12QNode *n);
void func_00255C58(B12List *l, B12QNode *n);

void func_002566A8(B12Ctx *c, B12QNode *n) {
    u32 mask = __osDisableInt();
    func_00255E78(&c->usedList, n);
    n->state = 0;
    func_00255C58(&c->freeList, n);
    __osRestoreInt(mask);
}
