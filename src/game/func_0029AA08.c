#include "b22_types.h"
extern SndMgr *D_8014D080;
s32 func_0029AA08(void)
{
    SndCtx *c = D_8014D080->stk[D_8014D080->top].unk8;
    if (c) {
        return c->id;
    }
    return -1;
}
