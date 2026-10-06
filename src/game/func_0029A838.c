#include "b22_types.h"
extern SndMgr *D_8014D080;
s32 func_0029A838(s32 id)
{
    SndSlot *s = D_8014D080->slot;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (s->id == id) {
            return s->unk10;
        }
        s++;
    }
    return 0;
}
