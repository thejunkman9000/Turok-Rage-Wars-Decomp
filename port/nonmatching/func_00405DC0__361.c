#include "o01_types.h"

typedef struct O01B70 { s32 w[0x1C]; } O01B70;
typedef struct O01B584 { s32 w[0x161]; } O01B584;
typedef struct O01Cfg3 {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ O01B70 blk18;
    /* 0x088 */ O01B584 blk88;
    /* 0x60C */ u8 unk60C[1];
} O01Cfg3;
typedef struct O01Src {
    /* 0x000 */ u8 pad0[0x5E0];
    /* 0x5E0 */ O01B70 unk5E0;
} O01Src;
extern s32 D_8011FECC;
extern s32 D_800E28B0;
extern O01Cfg3 *D_800E28B8;
extern u8 D_800E0D90[];
extern O01B584 D_801462C8;
extern f32 D_801468A0[];
extern u8 D_800FD1F0[];
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
s32 *func_002533DC(s32 a, s32 b, s32 c, void *d);
void *memset(void *p, s32 c, u32 n);
void *memcpy(void *dst, const void *src, u32 n);

void func_00405DC0(O01Src *src) {
    s32 size = D_8011FECC + 0x610;
    s32 sz2;
    s32 *h;
    u8 *p;
    O01Cfg3 *c;
    if (D_800E28B0 != 0) {
        func_002538A8(0);
        func_002537D8(0, D_800E28B0);
    }
    sz2 = D_8011FECC + 0x610;
    h = func_002533DC(0, sz2, 0x33, D_800E0D90);
    p = (u8 *)*h;
    D_800E28B0 = (s32)h;
    D_800E28B8 = (O01Cfg3 *)p;
    memset(p, 0, sz2);
    D_800E28B8->blk18 = src->unk5E0;
    D_800E28B8->blk88 = D_801462C8;
    c = D_800E28B8;
    c->unk8 = D_801468A0[0];
    c->unkC = D_801468A0[1];
    c->unk10 = D_801468A0[2];
    c->unk0 = size;
    c->unk14 = D_801468A0[3];
    c->unk4 = D_8011FECC;
    memcpy(c->unk60C, D_800FD1F0, D_8011FECC);
}
