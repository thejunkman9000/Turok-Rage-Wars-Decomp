#include "b02_types.h"

extern f32 D_800C6D78;

void func_00209910(B2Ctl *ctl, f32 x) {
    f32 v = x * D_800C6D78;

    if (ctl != NULL) {
        ctl->owner->unk6A0 = -v;
    }
}
