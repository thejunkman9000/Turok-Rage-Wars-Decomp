#include "b22_types.h"
extern SndMgr *D_8014D080;
void func_00298310(s32, s32, void *, s32, s32);
void func_0029AC80(void *);
void func_00298DBC(void)
{
    s32 top = D_8014D080->top;
    s32 id = D_8014D080->stk[top].id;
    if (D_8014D080->fn10) {
        D_8014D080->stk[top].ctx->unk40 = D_8014D080->fn10(id);
    }
    func_00298310(1, 0xE06, 0, 0, 0);
    func_00298310(1, 0xE07, 0, 0, 0);
    D_8014D080->stk[top].unk14 = 0;
    func_00298310(1, 0xE02, &D_8014D080->stk[top].unkC, 0, 0);
    func_0029AC80(&D_8014D080->stk[top].unkC);
}
