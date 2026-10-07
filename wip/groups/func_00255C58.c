#include "b12_types.h"

void func_00255C58(B12List *l, u8 *n) {
    if (l->head) {
        *(u8 **)(n + l->nextOff) = l->head;
        *(u8 **)(l->head + l->prevOff) = n;
    } else {
        *(u8 **)(n + l->nextOff) = 0;
        l->tail = n;
    }
    *(u8 **)(n + l->prevOff) = 0;
    l->head = n;
    l->count++;
}
