#include "b12_types.h"

inline void func_00255E78(B12List *l, u8 *n) {
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

inline void func_00255C58(B12List *l, u8 *n) {
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

void func_00255F58(B12List *l, u8 *n) {
    func_00255E78(l, n);
    func_00255C58(l, n);
}
