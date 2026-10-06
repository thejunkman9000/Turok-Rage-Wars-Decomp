#include "b02_types.h"

void func_0020A884(B2Ctl *ctl);
f32 func_00216F44(B2Actor *a, f32 x, f32 y, f32 z);
f32 func_0020AA0C(B2Ctl *ctl);
void func_0020A95C(B2Ctl *ctl, B2Cfg *cfg);

void func_0020A7B0(B2Ctl *ctl, B2Cfg *cfg) {
    f32 dist;
    B2Actor *t;

    if (ctl != NULL) {
        func_0020A884(ctl);
        if (ctl->unk2E4 > 0) {
            ctl->unk2E4--;
            return;
        }
        if (ctl->unk2E4 == 0) {
            ctl->unk23C = 1;
            ctl->unk2E8--;
        }
        if (ctl->unk2E8 == 0) {
            ctl->unk2E4 = -1;
            t = ctl->target->owner;
            dist = func_00216F44(ctl->owner, t->pos.x, t->pos.y, t->pos.z);
            if (func_0020AA0C(ctl) < dist) {
                ctl->unk23C = 1;
            } else {
                ctl->unk23C = 0;
                func_0020A95C(ctl, cfg);
            }
        }
    }
}
