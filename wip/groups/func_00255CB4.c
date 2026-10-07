#include "b12_types.h"

void func_00255CB4(B12List *l, u8 *n) {
    if (l->tail) {
        *(u8 **)(n + l->prevOff) = l->tail;
        *(u8 **)(l->tail + l->nextOff) = n;
    } else {
        *(u8 **)(n + l->prevOff) = 0;
        l->head = n;
    }
    *(u8 **)(n + l->nextOff) = 0;
    l->tail = n;
    l->count++;
}
