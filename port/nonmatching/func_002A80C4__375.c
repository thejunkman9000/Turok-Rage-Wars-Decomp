
#include "b24_types.h"
s32 func_002A80C4(AnimCtl *c, s32 dir) {
    s32 i;
    if (dir == 0) {
        do {
            c->cur++;
            c->cur = c->cur % 4;
            i = c->cur;
        } while (c->slot[i].unk0 == 0);
        return i;
    }
    do {
            c->cur--;
            c->cur = (c->cur < 4) ? c->cur : 3;
            i = c->cur;
    } while (c->slot[i].unk0 == 0);
    return i;
}

