#include "o06_types.h"
typedef struct { u32 w0; u32 w1; } O06Gfx;
typedef struct { u8 pad[0x29C]; f32 unk29C; f32 unk2A0; f32 unk2A4; f32 unk2A8; } O06V;
typedef struct { u8 pad[0x40]; O06V *unk40; u8 pad2[0x184]; s32 unk1C8; s32 unk1CC; } O06A;
extern void func_002A94E8(void);
extern void func_0026925C(s32 a);
extern void func_002ABC18(s32 a, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g);
extern O06Gfx *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern f32 D_800E26BC;
extern f32 D_800E26C0;
void func_00442D18(O06A *a) {
    s32 v, t;
    f32 x, y;
    O06Gfx *g;
    if (a->unk1CC == 0) return;
    t = a->unk1C8;
    v = (t < 0x18) ? t : 0x2F - t;
    func_002A94E8();
    func_0026925C(0x15);
    x = a->unk40->unk29C;
    y = a->unk40->unk2A0;
    g = D_80110634++;
    g->w0 = 0xFB000000; g->w1 = 0xFF0000FF;
    g = D_80110634++;
    g->w0 = 0xFA000000; g->w1 = 0xE00000FF;
    func_002ABC18(0x67, v, (s32)a->unk40->unk2A4, (s32)a->unk40->unk2A8,
                  x / (f32)D_800E28D0 * D_800E26BC,
                  y / (f32)D_800E28D4 * D_800E26C0, 1);
}
