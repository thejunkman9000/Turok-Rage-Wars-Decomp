#include "b02_types.h"

extern f32 D_800C6D98;
extern f32 D_800C6D9C;
extern f32 D_800C6DA0;

f32 func_00209BE0(B2Ctl *ctl) {
    f32 v = ctl->owner->def->info.unk20 * D_800C6D98;

    switch (ctl->owner->stats->unk93) {
    case 1:
        break;
    default:
        ctl->owner->stats->unk93 = 0;
    case 0:
        v *= D_800C6D9C;
        break;
    case 2:
        v *= D_800C6DA0;
        break;
    }
    return v;
}
