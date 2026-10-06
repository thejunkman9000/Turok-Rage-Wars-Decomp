
#include "b22_types.h"
extern SndMgr *D_8014D080;
s32 func_0029A5D4(s32, s32, s32, s32, s32);
void func_0029ACC4(void);
void func_00298310(s32, s32, s32, s32, s32);
s32 func_00298EA4(s32 a)
{
    SndMgr *m;
    s32 saved;
    s32 b;
    if (D_8014D080->top >= 0 && D_8014D080->unk530 != 0) {
        if (D_8014D080->stk[D_8014D080->top].unk8) {
            func_0029A5D4(D_8014D080->stk[D_8014D080->top].unk8->id, 0x10, 0, 0, 0);
        }
        b = a;
        func_0029ACC4();
        m = D_8014D080;
        if (m->top != -1) {
            if (m->fn0) {
                saved = m->unk520;
                m->unk520 = 0;
                m->fn0(0xE03, b, 0, 0);
                if (D_8014D080->unk520 == 1) {
                    D_8014D080->unk520 = saved;
                    goto done;
                }
                D_8014D080->unk520 = saved;
            }
            func_00298310(1, 0xE03, b, 0, 0);
        }
done:
        D_8014D080->unk530 = 0;
    }
    return 1;
}
