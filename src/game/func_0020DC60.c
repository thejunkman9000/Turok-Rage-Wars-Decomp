#include "b02_types.h"

s32 func_0020DD04(B2Info *info);
s32 func_00209874(B2Ctl *ctl, s32 id);

void func_0020DC60(B2Ctl *ctl) {
    s32 v = func_0020DD04(&ctl->owner->def->info);

    ctl->unk230 = v;
    func_00209874(ctl, v);
}
