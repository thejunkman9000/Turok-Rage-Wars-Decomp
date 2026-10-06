#include "b22_types.h"
extern SndMgr *D_8014D080;
void func_0029A550(s32 (*fn)())
{
    D_8014D080->fn0 = fn;
    if (fn) {
        fn(0xE04, 0, 0, 0);
    }
}
