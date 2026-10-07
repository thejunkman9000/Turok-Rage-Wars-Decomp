#include "b12_types.h"

void func_00255E78(B12List *l, u8 *n) {
    u8 *prev = *(u8 **)(n + l->prevOff);
    u8 *next;
    if (prev) {
        *(u8 **)(prev + l->nextOff) = *(u8 **)(n + l->nextOff);
    }
    next = *(u8 **)(n + l->nextOff);
    if (next) {
        *(u8 **)(next + l->prevOff) = *(u8 **)(n + l->prevOff);
    }
    if (l->head == n) {
        l->head = *(u8 **)(n + l->nextOff);
    }
    if (l->tail == n) {
        l->tail = *(u8 **)(n + l->prevOff);
    }
    l->count--;
}
