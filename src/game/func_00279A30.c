#include "b17_types.h"

Mtx64 *func_00279A30(MtxStack *s, s32 n) {
    Mtx64 *r;

    r = 0;
    if (s->left >= n) {
        r = s->cur;
        s->cur = r + n;
        s->left -= n;
    }
    return r;
}
