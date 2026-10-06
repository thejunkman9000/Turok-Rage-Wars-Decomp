#include "b12_types.h"

void func_00255F10(B12List *l) {
    l->head = *(u8 **)(l->head + l->nextOff);
    l->count--;
}
