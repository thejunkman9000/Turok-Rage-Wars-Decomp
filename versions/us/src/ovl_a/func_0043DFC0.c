#include "s1009_types.h"
extern S10Game D_801468A0[];
void func_0043DFC0(f32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 i;
    D_801468A0->unk54 = c;
    D_801468A0->unk24 = d;
    D_801468A0->unk80 = 0;
    D_801468A0->unk14 = a * 900.0f;
    D_801468A0->unk6C = 0xA00;
    D_801468A0->unk18 = b;
    D_801468A0->unk1C = 0;
    D_801468A0->unk78 = e;
    for (i = 0; i < 5; i++) {
        D_801468A0->unk2C[i] = 0;
        D_801468A0->unk40[i] = 0;
    }
    D_801468A0->unk28 = 0;
    D_801468A0->unk20 = 0;
    if (D_801468A0->unk14 == 0.0f) {
        D_801468A0->unk14 = -1.0f;
    }
}
