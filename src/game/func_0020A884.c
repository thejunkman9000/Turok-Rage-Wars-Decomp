#include "p1_types.h"
extern f32 D_800C6E18;
extern f32 D_800C6E1C;
f32 func_002745D4(f32 x);
void func_0020A95C(Brain *brain, AiCfg *cfg);
void func_0020A884(Brain *brain, AiCfg *cfg) {
    f32 k;
    if (brain->unk2EC == 0) {
        if (brain->unk23C == 0 && brain->unk240 <= 0) {
            k = D_800C6E1C;
            if (func_002745D4(D_800C6E18) + k > (f32)cfg->unk18) {
                brain->unk240 = 1;
                func_0020A95C(brain, cfg);
            }
            brain->unk2EC = cfg->unk10;
            brain->unk2EC = (s32)((f32)brain->unk2EC + func_002745D4(k) * (f32)cfg->unk14);
        }
    } else {
        brain->unk2EC--;
    }
}
