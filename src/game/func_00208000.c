#include "b02_types.h"

void func_0020986C(B2Ctl *ctl, void *tbl);
s32 func_00209874(B2Ctl *ctl, s32 id);
void func_002110C4(B2Ctl *ctl);
void func_00209988(B2Ctl *ctl);
void func_0020999C(B2Ctl *ctl);
extern u8 D_800CE040[];

void func_00208000(B2Ctl *ctl) {
    s32 i;
    s32 m1;

    ctl->unk4 = -1;
    ctl->unk8 = -1;
    ctl->unkC = 0xB;
    ctl->unk10 = -1;
    ctl->v2C.x = 0;
    ctl->v2C.y = 0;
    ctl->v2C.z = 0;
    m1 = -1;
    for (i = 3; i >= 0; i--) {
        ctl->q[i] = m1;
    }
    ctl->unk28 = -1;
    ctl->unk1BC = 0xFFFF;
    ctl->unk220 = 0;
    ctl->unk1C8 = 0;
    ctl->unk38 = 1;
    ctl->a3C[0] = 0;
    ctl->target = NULL;
    ctl->unk28C = 0;
    ctl->unk68 = 0;
    ctl->unkBC = -1;
    ctl->unk224 = -1;
    ctl->unk228 = 0;
    for (i = 0; i < 10; i++) {
        ctl->a3C[i] = 0;
        ctl->a6C[i] = 0;
        ctl->a94[i] = 0;
    }
    ctl->unk238 = 0;
    func_0020986C(ctl, D_800CE040);
    func_00209874(ctl, 2);
    ctl->unk244 = 0;
    ctl->unk23C = 0;
    ctl->unk240 = 0;
    ctl->unk250 = ctl->unk254 = ctl->unk248 = ctl->unk24C = ctl->v258.x = ctl->v258.y = ctl->v258.z = ctl->unk244;
    func_002110C4(ctl);
    func_00209988(ctl);
    func_0020999C(ctl);
    ctl->unk318 = 0;
    ctl->unk31C = 0;
    ctl->unk320 = -1;
    ctl->unk324 = 0;
    ctl->unk328 = 0;
    ctl->unk2D8 = 0;
    ctl->unk2E4 = 0;
    ctl->unk2EC = 0;
    ctl->unk2E8 = 0;
    ctl->unk2DC = 0;
    ctl->unk2E0 = 0;
    ctl->unk32C = -1;
}
