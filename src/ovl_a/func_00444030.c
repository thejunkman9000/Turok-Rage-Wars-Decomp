/* GROUP: func_00444030 (real entry 0x444030; the 3 words before it are stray padding) inlines func_00444204 -> verify both from this file */
#include "o06_types.h"
typedef struct { u8 pad[0x78]; u8 unk78; u8 unk79; u8 unk7A; u8 unk7B; u8 unk7C; u8 unk7D; u8 unk7E; u8 unk7F; u8 unk80; u8 unk81; u8 unk82; u8 unk83; u8 pad2[0x10]; u8 unk94; u8 unk95; } O06A;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; u8 padC[1]; u8 unkD; u8 padE[2]; s32 unk10; s16 unk14; u8 unk16; u8 unk17;
    u8 unk18; u8 unk19; u8 unk1A; u8 unk1B; u8 unk1C; u8 unk1D; u8 unk1E; u8 unk1F; f32 unk20;
    u8 unk24; u8 unk25; u8 unk26; u8 unk27; u8 unk28; u8 unk29; u8 unk2A; u8 unk2B; u8 unk2C[10];
    u8 unk36; u8 unk37; u8 unk38; u8 unk39; u8 pad3A[0x78]; u8 unkB2; u8 padB3[0x4CD]; u8 unk580;
} O06B;
extern void func_00444260(O06A *a);
extern const f32 D_800E2798;
static inline void func_00444204(O06A *a, u8 b) {
    a->unk78 = 0; a->unk79 = 0x86; a->unk7A = 0x84; a->unk7C = 0; a->unk7B = 0; a->unk7D = 1; a->unk7E = 0;
    a->unk7F = b; a->unk80 = 0; a->unk82 = 0; a->unk83 = 0; a->unk81 = 0; a->unk94 = 0; a->unk95 = 0;
    func_00444260(a);
}
void func_00444030(O06B *a) {
    s32 i;
    a->unk17 = 1;
    a->unk18 = 0x80;
    a->unk19 = 0xFA;
    a->unk1A = 0xFF;
    a->unk14 = 0x80;
    a->unk8 = 0x10;
    a->unk0 = 0;
    a->unk4 = 0;
    a->unk0 = 0x4000000;
    a->unk4 = 0x4000000;
    a->unk10 = 0;
    a->unk4 = -1;
    a->unk1B = 1;
    a->unk1C = 0;
    a->unk1F = 0;
    a->unk580 = 0;
    a->unk24 = 10;
    a->unk25 = 10;
    a->unk26 = 10;
    a->unk27 = 10;
    a->unk28 = 1;
    a->unk29 = 0;
    a->unk2A = 0;
    a->unk2B = 1;
    a->unk16 = a->unk14;
    a->unk20 = D_800E2798;
    for (i = 0; i < 10; i++) a->unk2C[i] = 1;
    a->unk36 = 0; a->unk37 = 3; a->unk38 = 0; a->unk39 = 3;
    for (i = 0; i < 8; i++) func_00444204((O06A *)((u8 *)a + 0xD0 + i * 0x96), i);
    func_00444204((O06A *)((u8 *)a + 0x3A), 0);
    a->unkB2 = 1;
    a->unk1D = 0; a->unk1E = 1; a->unkD = 0;
}
