#include "m03_h12.h"
s32 func_002508E0(B12Elem *elem, s32 key) {
    B12Tbl *t;
    s32 idx = -1;
    s32 i;
    s32 n;
    t = func_0028FD94(key, 0);
    i = 0;
    n = t->count;
    for (; i < n; i++) {
        if (&t->elem[i] == elem) { idx = i; break; }
    }
    return idx;
}
