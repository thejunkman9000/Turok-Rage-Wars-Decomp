#include "b22_types.h"
extern SndMgr *D_8014D080;
s32 func_0029A7E4(s32 id)
{
    SndSlot *s = D_8014D080->slot;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (s->id == id) {
            if (s->unk8) {
                return s->unk8;
            }
            return s->unk4;
        }
        s++;
    }
    return 0;
}
