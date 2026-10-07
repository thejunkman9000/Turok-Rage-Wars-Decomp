#include "o01_types.h"

typedef struct O01B70 { s32 w[0x1C]; } O01B70;
typedef struct O01B584 { s32 w[0x161]; } O01B584;
typedef struct O01Cfg2 {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ O01B70 blk18;
    /* 0x088 */ O01B584 blk88;
    /* 0x60C */ u8 unk60C[1];
} O01Cfg2;
typedef struct O01G2 {
    /* 0x00 */ u8 pad0[0x44];
    /* 0x44 */ s32 unk44;
} O01G2;
typedef struct O01Dst {
    /* 0x000 */ u8 pad0[0x5E0];
    /* 0x5E0 */ O01B70 unk5E0;
} O01Dst;
extern O01G2 D_8011FE88[];
extern O01Cfg2 *D_800E28BC;
extern u8 D_80146848;
extern O01B584 D_801462C8;
extern f32 D_801468A0[];
extern s32 D_8013B2D4;
extern u8 D_800FD1F0[];

void func_00409AEC(O01Dst *dst) {
    O01G2 *g = D_8011FE88;
    u8 save = D_80146848;
    s32 i;
    O01Cfg2 *c;
    u8 *src;
    u8 *dp;
    dst->unk5E0 = D_800E28BC->blk18;
    D_801462C8 = D_800E28BC->blk88;
    c = D_800E28BC;
    D_801468A0[0] = c->unk8;
    D_801468A0[1] = c->unkC;
    D_801468A0[2] = c->unk10;
    *((u8 *)D_801468A0 - 0x58) = save;
    D_8013B2D4 = *(s32 *)((u8 *)D_801468A0 - 0x5D4);
    D_801468A0[3] = c->unk14;
    src = c->unk60C;
    dp = D_800FD1F0;
    for (i = 0; i < g->unk44; i++) {
        *dp++ = *src++;
    }
}
