#include "b12_types.h"

void func_00255DC4(B12List *l, u8 *ref, u8 *n) {
    u8 *next = *(u8 **)(ref + l->nextOff);
    if (next) {
        *(u8 **)(next + l->prevOff) = n;
        *(u8 **)(n + l->nextOff) = *(u8 **)(ref + l->nextOff);
        *(u8 **)(ref + l->nextOff) = n;
        *(u8 **)(n + l->prevOff) = ref;
        l->count++;
    } else {
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
}
