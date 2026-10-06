#include "b22_types.h"
extern SndMgr *D_8014D080;
typedef void (*VpFn)(SndCtx *, B22Viewport);
static inline s32 SlotC(s32 id)
{
    SndSlot *s = D_8014D080->slot;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (s->id == id) {
            return s->unkC;
        }
        s++;
    }
    return 0;
}
s32 func_0029AA80(SndCtx *c, B22Viewport vp)
{
    VpFn fn = (VpFn)SlotC(c->unkE);
    if (fn) {
        fn(c, vp);
        return 1;
    }
    return 0;
}

