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

inline void func_00255CB4(B12List *l, u8 *n) {
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

void func_00256044(B12List *l, u8 *n) {
    func_00255E78(l, n);
    func_00255CB4(l, n);
}
