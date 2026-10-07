#include "o06_types.h"
typedef struct { u8 pad[0x8F]; u8 unk8F; } O06C;
typedef struct { u8 pad[0x5D0]; s32 unk5D0; s32 pad5D4; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
typedef struct { u8 pad[0x54]; s32 unk54; u8 pad2[0x1C]; s32 unk74; } O06G;
extern O06G D_801468A0[];
extern s32 D_80145070;
extern u8 D_8011FAC0[];
extern void func_0044E9A0(void *a);
s32 func_004439B4(s32 a, O06A *b) {
    if (D_801468A0->unk54) { u8 v = b->unk1C->unk5D8->unk8F; if (v == 1) D_801468A0->unk74 = v; }
    if (D_80145070 == 1) func_0044E9A0(D_8011FAC0); else b->unk1C->unk5D0 = 0;
    return 1;
}
