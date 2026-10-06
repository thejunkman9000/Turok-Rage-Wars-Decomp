#include "b22_types.h"
extern SndMgr *D_8014D080;
s32 func_0029A9A0(s32);
void func_00299368(s32);
void func_0029A8A8(void)
{
    if (D_8014D080->top > 0) {
        func_00299368(func_0029A9A0(0));
    }
}
