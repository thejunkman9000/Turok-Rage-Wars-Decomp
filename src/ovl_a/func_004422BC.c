#include "o06_types.h"
typedef struct { s32 unk0; s32 unk4; f32 unk8; u8 padC[8]; s32 unk14; s32 unk18; s32 unk1C; u8 pad20[0xD4]; f32 unkF4; u8 padF8[0x90]; } O06Blob;
typedef struct { s32 unk0; O06Blob blob; u8 pad[0x478 - 0x18C]; s32 unk478; f32 unk47C; } O06A;
typedef struct { u8 pad[0x20]; O06A *unk20; } O06D;
extern u8 D_8011FE88[];
extern O06Blob *func_0028CF7C();
extern f32 D_800E2524;
O06Blob *func_004422BC(O06D *a, s32 b, s32 c) {
    O06A *p = a->unk20;
    O06Blob *v = func_0028CF7C(D_8011FE88, b, c);
    if (v == 0) { p->unk478 = 0; return 0; }
    p->unk0 = b;
    p->unk478 = 1;
    p->blob = *v;
    p->blob.unk0 = 0;
    p->blob.unk4 = 0;
    p->blob.unk14 = 0;
    p->blob.unk18 = 0;
    p->blob.unk1C = 0;
    p->blob.unk8 = D_800E2524;
    p->unk47C = p->blob.unkF4;
    return &p->blob;
}
