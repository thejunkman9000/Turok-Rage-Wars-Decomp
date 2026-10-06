#include "b02_types.h"

extern f32 D_800C6D80;
extern f32 D_800C6D84;
extern f32 D_800C6D88;

f32 func_00209AE8(B2Ctl *ctl) {
    f32 v = ctl->owner->def->info.unk18 * D_800C6D80;

    switch (ctl->owner->stats->unk93) {
    case 1:
        break;
    default:
        ctl->owner->stats->unk93 = 0;
    case 0:
        v *= D_800C6D84;
        break;
    case 2:
        v *= D_800C6D88;
        break;
    }
    return v;
}
