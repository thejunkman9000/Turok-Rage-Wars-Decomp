#include "b02_types.h"

void func_0020A95C(B2Ctl *ctl, B2Cfg *cfg);
f32 func_0020AA0C(B2Ctl *ctl);
f32 func_00216F44(B2Actor *a, f32 x, f32 y, f32 z);
f32 func_002745D4(f32 x);
void func_0028509C(void *g, B2Actor *a, f32 *out);
extern u8 D_80121990[];
extern f32 D_800C6E0C;
extern f32 D_800C6E10;
extern f32 D_800C6E14;

void func_0020A458(B2Ctl *ctl, B2Cfg *cfg) {
    f32 d;
    f32 k;
    B2Actor *a;
    f32 dist;
    s32 t;

    if (ctl == NULL) {
        return;
    }
    if (ctl->unk2EC == 0) {
        func_0028509C(D_80121990, ctl->owner, &d);
        if (d < D_800C6E0C) {
            k = D_800C6E14;
            if (func_002745D4(D_800C6E10) + k > (f32)cfg[1].unk18) {
                t = cfg[1].unk8;
                ctl->unk240 = t + func_002745D4(k) * cfg[1].unkC;
            }
            ctl->unk2EC = cfg[1].unk10;
            ctl->unk2EC += func_002745D4(k) * cfg[1].unk14;
            ctl->unk2EC += ctl->unk240;
        }
    } else {
        ctl->unk2EC--;
    }
    if (ctl->unk2E4 > 0) {
        ctl->unk2E4--;
        return;
    }
    if (ctl->unk2E4 == -1) {
        ctl->unk23C = 1;
        ctl->unk2E8--;
    } else {
        a = ctl->target->owner;
        dist = func_00216F44(ctl->owner, a->pos.x, a->pos.y, a->pos.z);
        if (func_0020AA0C(ctl) < dist) {
            return;
        }
        ctl->unk23C = 1;
        ctl->unk2E4 = -1;
    }
    if (ctl->unk2E8 == 0) {
        ctl->unk23C = 0;
        func_0020A95C(ctl, cfg);
    }
}
