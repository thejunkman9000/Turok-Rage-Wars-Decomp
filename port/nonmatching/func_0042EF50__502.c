#include "o04_types.h"
extern O04GFlags D_801468A0[];
extern f32 D_800E1B84;
extern f32 D_800E1B88;
extern f32 D_800E1B8C;
#define G D_801468A0
#define C2D5 ((u8 *)D_801468A0)[-0x5CB]
void func_0042EF50(f32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 i;
    f32 m;
    G->unk58 = c;
    G->unk80 = 0;
    G->unk7C = d;
    G->unk54 = e;
    G->unk24 = f;
    G->unk78 = g;
    m = D_800E1B84;
    if (C2D5 == 2 || C2D5 == 3) {
        m = D_800E1B88;
    }
    G->unk14 = a * m;
    G->unk6C = 0xA00;
    G->unk18 = b;
    G->unk1C = 0;
    for (i = 0; i < 5; i++) {
        G->unk2C[i] = 0;
        G->unk40[i] = 0;
    }
    G->unk28 = 0;
    if (G->unk14 == 0.0f) {
        G->unk14 = D_800E1B8C;
    }
}
