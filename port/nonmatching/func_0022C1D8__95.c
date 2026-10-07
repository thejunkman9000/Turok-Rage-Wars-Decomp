#include "p2_types.h"
extern f32 D_800C7E1C;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_801462DE;
void func_002AA224(u8 a);
void func_002ABC18(s32 a, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g);

void func_0022C1D8(Player *p, EvtSrc *t) {
    f32 a, b, fa, fb, m1, m2; s32 sx; func_002AA224(D_801462DE); a = t->f29C; fa = a / (f32)D_800E28D0; m1 = fa * D_800C7E1C; b = t->f2A0; fb = b / (f32)D_800E28D4; m2 = fb * D_800C7E1C; sx = p->f7BC; func_002ABC18(0x1FC, sx, t->f2A4 + a + m1, t->f2A8 + b + m2, fa, fb, 1);
}
