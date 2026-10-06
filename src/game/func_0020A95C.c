#include "b02_types.h"

f32 func_002745D4(f32 x);
extern f32 D_800C6E20;

void func_0020A95C(B2Ctl *ctl, B2Cfg *cfg) {
    f32 k = D_800C6E20;

    ctl->unk2E4 = cfg->unk0;
    ctl->unk2E4 += func_002745D4(k) * cfg->unk4;
    ctl->unk2E8 = cfg->unk8;
    ctl->unk2E8 += func_002745D4(k) * cfg->unkC;
    if (cfg->unk18 == 100) {
        ctl->unk240 = 1;
    }
}
