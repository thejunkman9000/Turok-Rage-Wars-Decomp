#include "b22_types.h"
extern SndMgr *D_8014D080;
void func_00298EA4(s32);
void func_0029AC80(void *);
void func_00411E98(s32);
void func_00299ECC(void)
{
    SndMgr *m;
    if (D_8014D080->stk[D_8014D080->top].ctx != 0) {
        func_00298EA4(D_8014D080->stk[D_8014D080->top - 1].id);
        func_0029AC80(&D_8014D080->stk[D_8014D080->top].unkC);
        func_00411E98(D_8014D080->stk[D_8014D080->top].ctx->id);
    }
    m = D_8014D080;
    m->stk[m->top].ctx = 0;
    m->stk[m->top].id = 0;
    m->stk[m->top].unk8 = 0;
    m->top--;
    if (m->top < m->unk8) {
        m->unk8 = m->top;
    }
}
