
#include "b22_types.h"
extern SndMgr *D_8014D080;
s32 func_00411E70(s32);
s32 func_00298A34(s32, s32, s32, s32);
s32 func_00297E3C(s32, s32, s32, s32, s32);
s32 func_0029A5D4(s32 id, s32 cmd, s32 a, s32 b, s32 c)
{
    s32 r;
    s32 saved;
    s32 f;
    s32 top;
    if (func_00411E70(id)) {
        if (id != D_8014D080->stk[D_8014D080->top].id) {
            return 0;
        }
    }
    top = D_8014D080->top;
    f = -1;
    if (id == D_8014D080->unk528 || top == f) {
        return 0;
    }
    if (D_8014D080->fn0) {
        saved = D_8014D080->unk520;
        D_8014D080->unk520 = 0;
        r = D_8014D080->fn0(cmd, a, b, c);
        if (D_8014D080->unk520 == 1) {
            D_8014D080->unk520 = saved;
            return r;
        }
        D_8014D080->unk520 = saved;
    }
    if (id == D_8014D080->stk[D_8014D080->top].ctx->id) {
        r = func_00298A34(cmd, a, b, c);
    } else {
        r = func_00297E3C(id, cmd, a, b, c);
    }
    return r;
}


