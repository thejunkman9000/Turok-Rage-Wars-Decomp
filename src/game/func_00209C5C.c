#include "b02_types.h"

extern f32 D_800C6DA4;
extern f32 D_800C6DA8;
extern f32 D_800C6DAC;

f32 func_00209C5C(B2Ctl *ctl) {
    f32 v = ctl->owner->def->info.unk1C * D_800C6DA4;

    switch (ctl->owner->stats->unk93) {
    case 1:
        break;
    default:
        ctl->owner->stats->unk93 = 0;
    case 0:
        v *= D_800C6DA8;
        break;
    case 2:
        v *= D_800C6DAC;
        break;
    }
    return v;
}
