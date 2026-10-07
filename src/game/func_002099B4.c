#include "b02_types.h"

s32 func_00244494(B2Actor *a, Vec3f from, Vec3f to, void *out);
extern f32 D_800C6D7C;
extern B2Actor **D_80103FCC;
extern u8 D_80103FD0[];

s32 func_002099B4(B2Ctl *ctl, B2Actor *target) {
    Vec3f from;
    Vec3f to;

    if (ctl == NULL || target == NULL) {
        return 0;
    }
    from = ctl->owner->pos;
    to = target->pos;
    from.y += D_800C6D7C;
    to.y += D_800C6D7C;
    if (func_00244494(ctl->owner, from, to, D_80103FD0)) {
        return *D_80103FCC == target;
    }
    return 1;
}
