#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; u8 pad2[4]; s32 unk1C; } O06A;
typedef struct { u8 pad[4]; s32 unk4; u8 pad2[4]; f32 unkC; f32 unk10; u16 unk14; u16 unk16; u8 pad3[6]; u16 unk1E; } O06B;
typedef struct { u8 pad[0x30]; f32 unk30; f32 unk34; } O06C;
extern void func_002AA224(s32 a);
extern void func_002ABC18(void *a, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g);
extern s32 D_800E28D8;
extern f32 D_800E2774;
void func_004438A4(O06A *a, O06B *b, s32 c, O06C *d) {
    s32 t = a->unk1C + 20;
    f32 f;
    s32 h, y;
    t %= 512;
    a->unk1C = t;
    if (t >= 0x100) f = (f32)(0x200 - t) * d->unk30; else f = (f32)t * d->unk30;
    func_002AA224((s32)(d->unk34 * f));
    y = 0x50;
    h = b->unk4 >> 1;
    if (D_800E28D8 == 0) y = 0x2D;
    func_002ABC18(a->unk14, 0, b->unk16 - h * 8, b->unk1E + y, b->unkC * D_800E2774, b->unk10 * D_800E2774, 1);
}
