#include "o01_types.h"

typedef struct O01B70 { s32 w[0x1C]; } O01B70;
typedef struct O01B584 { s32 w[0x161]; } O01B584;
typedef struct O01CfgE {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ O01B70 blk18;
    /* 0x088 */ O01B584 blk88;
    /* 0x60C */ u8 unk60C[1];
} O01CfgE;
typedef struct O01GE {
    /* 0x00 */ u8 pad0[0x44];
    /* 0x44 */ s32 unk44;
} O01GE;
typedef struct O01Plr5 {
    /* 0x000 */ u8 pad0[0x5E0];
    /* 0x5E0 */ O01B70 unk5E0;
    /* 0x650 */ u8 pad650[0x48];
    /* 0x698 */ s32 unk698;
} O01Plr5;
typedef struct O01World {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
} O01World;
typedef struct O01SubE {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01SubE;
typedef struct O01OwnE {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ void *unk1C;
    /* 0x20 */ O01SubE *unk20;
    /* 0x24 */ s32 unk24;
} O01OwnE;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153784;
extern s32 D_80153780;
extern s32 D_8015378C;
extern O01World D_80145040;
extern O01GE D_8011FE88[];
extern O01CfgE *D_800E28BC;
extern u8 D_80146848;
extern O01B584 D_801462C8;
extern s32 D_801462CC;
extern f32 D_801468A0;
extern f32 D_801468A4;
extern f32 D_801468A8;
extern f32 D_801468AC;
extern s32 D_8013B2D4;
extern u8 D_800FD1F0[];
extern u8 D_8014561C[];
extern u8 D_0044F730[];
extern u8 D_0044F7C0[];
extern u8 D_0044F82C[];
s32 func_00406178(O01OwnE *o, s32 pad, s32 z);
O01Plr5 *func_0022A5B0(O01World *w, O01SubE *s);
s32 func_00404858(s32 pad, s32 idx);
void func_004426E4(u8 *a, void *b, void *c, s32 d, s32 e);

s32 func_00408870(s32 unused, O01OwnE *own) {
    s32 pad;
    O01Plr5 *plr;
    O01GE *g;
    u8 save;
    s32 i;
    O01CfgE *c;
    u8 *src;
    if (D_8015375C != 0) {
        pad = D_800E28C8;
    } else {
        pad = own->unk20->unk4;
    }
    if (func_00406178(own, pad, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_80153780 != 0) {
        plr = func_0022A5B0(&D_80145040, own->unk20);
        g = D_8011FE88;
        save = D_80146848;
        plr->unk5E0 = D_800E28BC->blk18;
        D_801462C8 = D_800E28BC->blk88;
        c = D_800E28BC;
        D_8013B2D4 = D_801462CC;
        D_801468A0 = c->unk8;
        D_801468A4 = c->unkC;
        D_801468A8 = c->unk10;
        D_80146848 = save;
        D_801468AC = c->unk14;
        src = c->unk60C;
        for (i = 0; i < g->unk44; i++) {
            D_800FD1F0[i] = src[i];
        }
        D_80145040.unk34 = 0;
        D_80145040.unk38 = 0;
        func_004426E4((u8 *)&D_80145040 + 0x5DC, D_0044F730, plr, plr->unk698, 0);
        return 1;
    }
    if (func_00404858(pad, D_8015378C) == 0) {
        func_004426E4(D_8014561C, D_0044F7C0, own->unk1C, own->unk20, own->unk24);
    } else {
        func_004426E4(D_8014561C, D_0044F82C, own->unk1C, own->unk20, own->unk24);
    }
    return 1;
}
