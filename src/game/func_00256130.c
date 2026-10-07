#include "b12_types.h"

u32 func_00274544(void);

u8 *func_00256130(B12List *l) {
    u8 *n = l->head;
    u32 r;
    if (!n) {
        return 0;
    }
    r = func_00274544() % l->count;
    while (r-- != 0) {
        n = *(u8 **)(n + l->nextOff);
    }
    return n;
}
