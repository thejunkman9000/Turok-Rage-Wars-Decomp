#include "b12_types.h"

s32 func_002561DC(B12List *l, u8 *n) {
    u8 *p = l->head;
    while (p) {
        if (p == n) {
            return 1;
        }
        p = *(u8 **)(p + l->nextOff);
    }
    return 0;
}
