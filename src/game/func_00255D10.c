#include "b12_types.h"

void func_00255D10(B12List *l, u8 *ref, u8 *n) {
    u8 *prev = *(u8 **)(ref + l->prevOff);
    if (prev) {
        *(u8 **)(prev + l->nextOff) = n;
        *(u8 **)(n + l->prevOff) = *(u8 **)(ref + l->prevOff);
        *(u8 **)(ref + l->prevOff) = n;
        *(u8 **)(n + l->nextOff) = ref;
        l->count++;
    } else {
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
}
