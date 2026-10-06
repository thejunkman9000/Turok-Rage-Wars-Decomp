#include "b22_types.h"
extern SndMgr *D_8014D080;
s32 func_0029A9A0(s32 n)
{
    s32 t = D_8014D080->top - 1;
    s32 i = t - n;
    if (i >= 0) {
        return D_8014D080->stk[i].id;
    }
    return -1;
}
