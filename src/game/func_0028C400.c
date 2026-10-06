#include "b20_types.h"
s32 func_0028C400(Level *lv, s32 key) {
    s32 n;
    Rec14 *r;
    n = lv->cnt11C0;
    r = lv->recA;
    while (--n != -1) {
        if (r->key == key && !(r->flags & 0x40)) {
            return 0;
        }
        r++;
    }
    n = lv->cnt11C4;
    r = lv->recB;
    while (--n != -1) {
        if (r->key == key && !(r->flags & 0x40)) {
            return 0;
        }
        r++;
    }
    return 1;
}
