#include "b12_types.h"

void func_002561B4(B12List *l) {
    u8 *p = l->head;
    while (p) {
        p = *(u8 **)(p + l->nextOff);
    }
}
