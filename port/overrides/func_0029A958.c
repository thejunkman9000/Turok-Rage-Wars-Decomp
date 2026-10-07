/* debug: log every change of the current screen id, and the pak-screen state now and then */
#include "b22_types.h"
extern SndMgr *D_8014D080;
extern s32 D_8014D098;
extern s32 D_800E28E0;
extern u8 *D_800E3518;
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
s32 func_0029A958(void)
{
    static s32 last = -2;
    static int n;
    s32 v = D_8014D098;
    if (v < 0) {
        if (D_8014D080->top < 0) { v = -1; goto out; }
        v = D_8014D080->stk[D_8014D080->top].id;
    }
out:
    if (v != last) { last = v; fprintf(__acrt_iob_func(2), "screen id -> %d (top=%d)\n", v, D_8014D080->top); }
    if (++n % 2000 == 1) {
        fprintf(__acrt_iob_func(2), "ui: D_800E28E0=%d pg=%p f14=%d f18=%d f1C=%d\n", D_800E28E0, D_800E3518,
                D_800E3518 ? *(s32 *)(D_800E3518 + 0x14) : -1, D_800E3518 ? *(s32 *)(D_800E3518 + 0x18) : -1, D_800E3518 ? *(s32 *)(D_800E3518 + 0x1C) : -1);
    }
    return v;
}
