#include "b22_types.h"
extern SndMgr *D_8014D080;
extern s32 D_8014D098;
s32 func_0029A958(void)
{
    s32 v = D_8014D098;
    if (v < 0) {
        if (D_8014D080->top < 0) {
            return -1;
        }
        v = D_8014D080->stk[D_8014D080->top].id;
    }
    return v;
}
