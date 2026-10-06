#include "b22_types.h"
typedef s32 (*SndFn)();
s32 func_0029A7E4(s32);
s32 func_0029A8E0(SndCtx *c, s32 a, s32 b, s32 d, s32 e)
{
    SndFn fn = (SndFn)func_0029A7E4(c->unkE);
    if (fn) {
        return fn(c, a, b, d, e);
    }
    return 0;
}
