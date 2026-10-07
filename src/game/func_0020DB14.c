#include "b02_types.h"

B2Edge *func_0020C9B0(B2Mgr *m, s32 idx);
extern B2Mgr D_8013B364;

s32 func_0020DB14(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;
    s32 i;
    s32 j;

    ctl->unk1C0 = -1;
    ctl->unk1C8 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < m->count; j++) {
            B2Edge *e = func_0020C9B0(m, j);

            if (e->a == ctl->q[i] && e->kind == 6) {
                ctl->unk1BC++;
                ctl->unk1C0 = ctl->q[i];
                return 0;
            }
        }
    }
    return 1;
}
