#include "b24_types.h"

s32 func_002A80C4(AnimCtl *c, s32 dir) {
    s32 i;
    u16 v;
    if (dir == 0) {
        do {
            c->cur = c->cur + 1;
            c->cur = c->cur & 3;
            i = c->cur;
        } while (c->slot[i].unk0 == 0);
        return i;
    }
    do {
        c->cur = c->cur - 1;
        v = c->cur;
        if (v >= 4) {
            v = 3;
        }
        c->cur = v;
        i = c->cur;
    } while (c->slot[i].unk0 == 0);
    return i;
}
