#include "b22_types.h"
extern SndMgr *D_8014D080;
void func_0029A58C(s32 on)
{
    if (on) {
        D_8014D080->unk52C |= 1;
    } else {
        D_8014D080->unk52C &= ~1;
    }
}
