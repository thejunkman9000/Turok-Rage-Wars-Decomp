#include "b24_types.h"

s32 func_002A8088(AnimCtl *c) {
    s32 n = 0;
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (c->slot[c->cur].unk0 != 0) n++;
    }
    return n != 0;
}
