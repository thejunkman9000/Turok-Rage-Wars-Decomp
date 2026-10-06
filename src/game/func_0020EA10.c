#include "b02_types.h"

f32 func_00209B64(B2Ctl *ctl);
s32 func_0022A82C(B2World *w);
f32 func_00274B00(f32 a, f32 b);
extern B2GameFlags D_801468A0[];
extern f32 D_800C6F40;
extern f32 D_800C6F44;
extern f32 D_800C6F48;

s32 func_0020EA10(B2Ctl *ctl) {
    f32 v;

    if (D_801468A0->unk78 != 0) {
        if (ctl->owner->stats->unk8F == 0) {
            if (func_0022A82C((B2World *)((u8 *)D_801468A0 - 0x1860)) == 0) {
                v = func_00209B64(ctl) * D_800C6F40 + D_800C6F44;
                if (v < func_00274B00(0.0f, D_800C6F48)) {
                    return 1;
                }
                return 0;
            }
        }
    }
    return 0;
}
