#include "b12_types.h"

void func_00255F34(B12List *l) {
    l->tail = *(u8 **)(l->tail + l->prevOff);
    l->count--;
}
