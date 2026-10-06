#include "b12_types.h"

void func_00255BEC(B12BlkList *l, u32 *sum, u32 *max) {
    B12Blk *n;
    *sum = 0;
    *max = 0;
    for (n = l->first; n != 0; n = n->next) {
        *sum += n->size;
        *max = (*max > n->size) ? *max : n->size;
    }
}
