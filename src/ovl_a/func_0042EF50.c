#include "o04_types.h"
extern O04GFlags D_801468A0[];
extern u8 D_801462C8[];
#define G D_801468A0
#define G2 ((O04GFlags *)(D_801462C8 + 0x5D8))
#define C2D5 ((u8 *)pg)[-0x5CB]
void func_0042EF50(f32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 i;
    register f32 pr __asm__("$f0");
    O04GFlags *pg = G;
    pg->unk58 = c;
    pg->unk80 = 0;
    pg->unk7C = d;
    pg->unk54 = e;
    pg->unk24 = f;
    pg->unk78 = g;
    pr = a * ((C2D5 == 2 || C2D5 == 3) ? 15.0f : 900.0f);
    pg->unk14 = pr;
    __asm__("");
    G2->unk6C = 0xA00;
    G2->unk18 = b;
    G2->unk1C = 0;
    for (i = 0; i < 5; i++) {
        G2->unk2C[i] = 0;
        G2->unk40[i] = 0;
    }
    G2->unk28 = 0;
    if (G2->unk14 == 0.0f) {
        G2->unk14 = -1.0f;
    }
}






