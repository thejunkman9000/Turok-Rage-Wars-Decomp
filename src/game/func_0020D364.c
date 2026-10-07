#include "b02_types.h"

B2Edge *func_0020C9B0(B2Mgr *m, s32 idx);
s32 func_0020DB14(B2Ctl *ctl);
s32 func_0020D4AC(B2Ctl *ctl);
s32 func_0020D6E4(B2Ctl *ctl);
s32 func_0020D9C0(B2Ctl *ctl);
extern B2Mgr D_8013B364;

s32 func_0020D364(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;
    s32 i;
    B2Edge *e;

    if (m == NULL) {
        return 1;
    }
    {
        if (ctl->unk1BC == 0) {
            return func_0020DB14(ctl);
        }
        if (ctl->unk1C0 != -1 && ctl->unk1C8 == 0) {
            for (i = 0; i < m->count; i++) {
                e = func_0020C9B0(m, i);
                if (e->a == ctl->unk1C0 && e->kind == 6) {
                    ctl->unk1C8++;
                }
            }
        }
        if (ctl->unk1BC > 0 && ctl->unk1BC < ctl->unk1C8 + 1) {
            return func_0020D4AC(ctl);
        }
        if (ctl->unk1BC == ctl->unk1C8 + 1) {
            return func_0020D6E4(ctl);
        }
        if (ctl->unk1BC != ctl->unk1C8 + 2) {
            return 1;
        }
        return func_0020D9C0(ctl);
    }
}
