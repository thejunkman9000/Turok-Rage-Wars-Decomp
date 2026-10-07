#include "b02_types.h"

f32 func_00274B00(f32 a, f32 b);
extern f32 D_800CDA30;
extern f32 D_800CDA34;
extern f32 D_800CDA38;
extern f32 D_800C6DB0;
extern f32 D_800C6DB4;

f32 func_00209DAC(B2Ctl *ctl) {
    f32 k;
    f32 f;

    switch (ctl->owner->stats->unk93) {
    default:
        ctl->owner->stats->unk93 = 0;
    case 0:
        k = D_800CDA30;
        break;
    case 1:
        k = D_800CDA34;
        break;
    case 2:
        k = D_800CDA38;
        break;
    }
    f = ctl->unk244;
    if (f < func_00274B00(-k, k)) {
        f += D_800C6DB0;
    } else {
        f -= D_800C6DB4;
    }
    ctl->unk244 = f;
    return f;
}
