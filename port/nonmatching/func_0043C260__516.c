#include "o06_types.h"
typedef struct { u32 w0; u32 w1; } O06Gfx;
typedef struct { u8 pad[0x2A4]; f32 unk2A4; f32 unk2A8; } O06V;
typedef struct { s32 unk0; u8 pad4[3]; u8 unk7; u8 pad8[3]; u8 unkB; u8 padC[3]; u8 unkF; u8 pad10[4]; s32 unk14; s32 unk18; } O06A;
extern void func_002A94E8(void);
extern void func_0026925C(s32 a);
extern void func_002ABC18(s32 a, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g);
extern O06Gfx *D_80110634;
extern s32 D_800E28D8;
extern O06V D_801450C8[];
void func_0043C260(O06A *a) {
    f32 f0, f1;
    O06Gfx *g;
    O06V *v;
    s32 s;
    if (a->unk18 == 1) {
        s = a->unk14;
        v = D_801450C8;
        func_002A94E8();
        func_0026925C(0x15);
        f1 = 1.0f;
        f0 = f1;
        switch (D_800E28D8) {
        case 0: f0 = f1; break;
        case 1: f0 = 1.6901408f; f1 = 1.6216216f; break;
        case 2: f0 = 1.6901408f; f1 = 1.0810812f; break;
        }
        g = D_80110634++;
        g->w0 = 0xFB000000;
        g->w1 = (a->unk7 << 24) | (a->unkB << 16) | (a->unkF << 8) | 0xFF;
        g = D_80110634++;
        g->w0 = 0xFA000000; g->w1 = 0xE00000FF;
        func_002ABC18(a->unk0, s, (s32)v->unk2A4, (s32)v->unk2A8, f0 * 9.0f, f1 * 4.0f, 1);
    }
}
