#include "b02_types.h"

f32 func_00216F44(B2Actor *a, f32 x, f32 y, f32 z);
f32 func_002745D4(f32 x);
extern f32 D_800C6DE4;
extern f32 D_800C6DE8;
extern f32 D_800C6DEC;
extern f32 D_800C6DF0;
extern f32 D_800C6DF4;
extern f32 D_800C6DF8;
extern f32 D_800C6DFC;

void func_0020A028(B2Ctl *ctl, B2Cfg *cfg) {
    f32 k;
    f32 lim;
    s32 nv;
    B2Actor *a;

    if (ctl->unk2EC > 0) {
        ctl->unk2EC--;
        if (ctl->unk2EC == 0) {
            k = D_800C6DE4;
            if (func_002745D4(k) < D_800C6DE8) {
                ctl->unk2EC = -1;
                ctl->unk2E4 = cfg[1].unk0;
                ctl->unk2E4 += func_002745D4(k) * cfg[1].unk4;
                ctl->unk2E8 = cfg[1].unk8;
                ctl->unk2E8 += func_002745D4(k) * cfg[1].unkC;
            } else {
                ctl->unk2EC = cfg->unk10;
                ctl->unk2EC += func_002745D4(k) * cfg->unk14;
            }
        }
    }
    if (ctl->unk2EC == -1) {
        ctl->unk2E8--;
        if (ctl->unk2E8 == 0) {
            k = D_800C6DEC;
            ctl->unk2EC = cfg->unk10;
            ctl->unk2EC += func_002745D4(k) * cfg->unk14;
            ctl->unk2E4 = cfg->unk0;
            ctl->unk2E4 += func_002745D4(k) * cfg->unk4;
            ctl->unk2E8 = cfg->unk8;
            ctl->unk2E8 += func_002745D4(k) * cfg->unkC;
            ctl->unk240 = 0;
        } else {
            ctl->unk240 = 1;
        }
    }
    if (ctl->unk2E4 > 0) {
        ctl->unk2E4--;
        return;
    }
    if (ctl->unk240 > 0) {
        nv = cfg[1].unk0;
        nv += func_002745D4(D_800C6DF0) * cfg[1].unk4;
        lim = D_800C6DF4;
    } else {
        nv = cfg->unk0;
        nv += func_002745D4(D_800C6DF8) * cfg->unk4;
        lim = D_800C6DFC;
    }
    a = ctl->target->owner;
    if (!(lim < func_00216F44(ctl->owner, a->pos.x, a->pos.y, a->pos.z))) {
        ctl->unk23C = 1;
        ctl->unk2E4 = nv;
    }
}
