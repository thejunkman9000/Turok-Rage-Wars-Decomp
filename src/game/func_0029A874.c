#include "b22_types.h"
extern SndMgr *D_8014D080;
void func_0029A874(s32 id, s32 v)
{
    SndSlot *s = D_8014D080->slot;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (s->id == id) {
            s->unk10 = v;
        }
        s++;
    }
}
