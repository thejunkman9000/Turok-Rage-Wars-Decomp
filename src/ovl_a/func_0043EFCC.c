/* GROUP: func_0043EFCC (real entry 0x43EFD0) inlines func_0043F1B8 (a predicate). */
#include "o06_types.h"
typedef struct { u32 w0; u32 w1; } O06Gfx;
typedef struct { u8 pad[0x20]; s16 unk20; s16 unk22; } O06X;
typedef struct { u8 pad[0x14]; s32 unk14; O06X *unk18; } O06A;
typedef struct { u8 pad[0x644]; u8 unk644[9]; u8 unk64D; u8 unk64E; } O06Y;
typedef struct { u8 pad[0x1C]; O06Y *unk1C; } O06B;
static inline s32 func_0043F1B8(O06A *a, O06B *b) {
    O06X *x = a->unk18; s32 id = x->unk20; s32 idx = x->unk22; O06Y *y = b->unk1C; s32 r = 0;
    switch (id) {
    case 0x10FE:
        if (idx >= 0) {
            if (idx < 3) goto A;
            if (idx < 6) goto B;
            break;
        A: r = idx < y->unk64D; break;
        B: r = (idx - 3) < y->unk64E; break;
        }
        break;
    case 0x1194: r = y->unk644[idx] != 0; break;
    }
    return r;
}
typedef struct { u8 pad[0xC]; f32 unkC; f32 unk10; s16 pad14; s16 unk16; u8 pad2[6]; s16 unk1E; } O06E;
typedef struct { u8 pad[0x30]; f32 unk30; f32 unk34; u8 pad2[0x1C]; s32 unk1C; } O06V;
extern void func_002AA224(s32 a);
extern void func_002ABC18(s32 a, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g);
extern O06Gfx *D_80110634;
extern s32 D_800E5E70;
void func_0043EFCC(O06A *a, O06E *b, s32 c, O06V *d) {
    s32 p = func_0043F1B8(a, (O06B *)d);
    O06Gfx *g1, *g2, *g3;
    if (D_800E5E70 != 5) {
        D_800E5E70 = 5;
        func_002AA224((s32)(d->unk30 * (d->unk34 * 255.0f)));
    }
    g1 = D_80110634++;
    g1->w0 = 0xE7000000; g1->w1 = 0;
    g2 = D_80110634++;
    g2->w0 = 0xE3000A01; g2->w1 = 0x100000;
    if (p) {
        g3 = D_80110634++;
        g3->w0 = 0xFB000000;
        g3->w1 = (s32)(d->unk30 * (d->unk34 * 255.0f)) | 0xFFFFFF00;
    } else {
        g3 = D_80110634++;
        g3->w0 = 0xFB000000;
        g3->w1 = ((s32)(d->unk30 * (d->unk34 * 255.0f)) & 0xFF) | 0x32323200;
    }
    func_002ABC18(a->unk14, 0, b->unk16, b->unk1E, b->unkC, b->unk10, 1);
}
