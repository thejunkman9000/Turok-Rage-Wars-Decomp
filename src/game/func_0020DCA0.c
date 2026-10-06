#include "b02_types.h"

s32 func_00274544(void);
s32 func_0020DD04(B2Info *info);
s32 func_00209874(B2Ctl *ctl, s32 id);

void func_0020DCA0(B2Ctl *ctl) {
    s32 n = func_00274544();
    s32 v;

    if ((n / 4) * 4 == n - 1) {
        v = func_0020DD04(&ctl->owner->def->info);
        ctl->unk230 = v;
        func_00209874(ctl, v);
    }
}
