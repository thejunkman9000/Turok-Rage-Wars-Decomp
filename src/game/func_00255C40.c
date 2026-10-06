#include "b12_types.h"

void func_00255C40(B12List *l, s32 prevOff, s32 nextOff) {
    l->prevOff = prevOff;
    l->nextOff = nextOff;
    l->tail = 0;
    l->head = 0;
    l->count = 0;
}
