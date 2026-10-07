#include "b02_types.h"

void func_0020A6D8(B2Ctl *ctl, B2Cfg *cfg);
void func_0020A7B0(B2Ctl *ctl, B2Cfg *cfg);
void func_0020A028(B2Ctl *ctl, B2Cfg *cfg);
void func_0020A2D4(B2Ctl *ctl, B2Cfg *cfg);
void func_0020A458(B2Ctl *ctl, B2Cfg *cfg);
extern B2Cfg D_800F7D20[22][2];
extern u32 D_800CDA40[22][2];

void func_00209E80(B2Ctl *ctl) {
    B2Actor *o;
    s32 w;
    s32 slot;

    if (ctl != NULL) {
        o = ctl->owner;
        if (o->unk11D8 > 0.0f) {
            return;
        }
        slot = o->unk594;
        slot -= 1;
        w = o->unk62E;
        switch (D_800CDA40[w][slot]) {
        case 0:
        case 1:
        case 2:
        case 3:
            func_0020A6D8(ctl, &D_800F7D20[w][slot]);
            break;
        case 4:
            func_0020A7B0(ctl, &D_800F7D20[w][slot]);
            break;
        case 8:
            ctl->unk240 = 1;
            break;
        case 5:
            func_0020A028(ctl, D_800F7D20[w]);
            break;
        case 7:
            func_0020A2D4(ctl, D_800F7D20[w]);
            break;
        case 6:
            func_0020A458(ctl, D_800F7D20[w]);
            break;
        default:
            return;
        }
        if (ctl->unk240 > 0) {
            ctl->owner->unk6B0 |= 0x4000;
            ctl->owner->unk6AC |= 0x4000;
            ctl->unk240--;
        }
    }
}
