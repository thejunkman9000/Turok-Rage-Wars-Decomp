#include "b14_types.h"
s32 func_auto_002630F4(B14BitRd *r, s32 n) {
    s32 i;
    s32 v = 0;
    for (i = 0; i < n; i++) {
        v |= ((r->data[r->pos >> 3] >> (r->pos & 7)) & 1) << i;
        r->pos++;
    }
    return v;
}
