/* debug: log every change of the current screen id */
#include "b22_types.h"
extern SndMgr *D_8014D080;
extern s32 D_8014D098;
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
s32 func_0029A958(void)
{
    static s32 last = -2;
    s32 v = D_8014D098;
    if (v < 0) {
        if (D_8014D080->top < 0) { v = -1; goto out; }
        v = D_8014D080->stk[D_8014D080->top].id;
    }
out:
    if (v != last) { last = v; fprintf(__acrt_iob_func(2), "screen id -> %d (top=%d)\n", v, D_8014D080->top); }
    return v;
}
