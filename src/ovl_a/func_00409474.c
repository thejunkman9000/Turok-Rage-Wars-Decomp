#include "o01_types.h"

typedef struct O01Sub3 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub3;
typedef struct O01Obj3 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ O01Sub3 *unk20;
} O01Obj3;
#define O01PAD(o) (D_8015375C != 0 ? D_800E28C8 : (o)->unk20->unk4)
typedef struct O01Sel { s32 v; s32 w; } O01Sel;
extern s32 D_80153750;
extern s32 D_8015377C;
extern s32 D_80153760;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern u8 D_00451820[];
extern u8 D_00451844[];
extern u8 D_00451868[];
extern u8 D_0045188C[];
extern u8 D_00450BD0[];
extern u8 D_0045077C[];
extern u8 D_0044F148[];

static inline u8 *O01Pick(O01Sel *sel) {
    u8 *p;
    switch (sel->v) {
    default:
    case 0:
        p = D_00451820;
        break;
    case 1:
        p = D_00451844;
        break;
    case 2:
        p = D_00451868;
        break;
    case 3:
        p = D_0045188C;
        break;
    }
    return p;
}

static inline u8 *O01GetMsg(O01Obj3 *a) {
    u8 *r = 0;
    O01Sel sel;
    if (D_80153750 != 0) {
        if (D_8015377C != 0) {
            if (D_8015375C != 0) {
                sel.v = D_800E28C8;
            } else {
                sel.v = a->unk20->unk4;
            }
            r = O01Pick(&sel);
        }
    } else if (D_80153760 != 0) {
        r = D_00450BD0;
        if (D_8015377C != 0) {
            r = D_0045077C;
        }
    } else if (D_8015375C != 0) {
        r = D_0044F148;
    }
    return r;
}

typedef struct O01Plr9 {
    /* 0x000 */ u8 pad0[0x5DC];
    /* 0x5DC */ u8 *unk5DC;
} O01Plr9;
typedef struct O01OwnI {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ O01Plr9 *unk1C;
    /* 0x20 */ O01Sub3 *unk20;
    /* 0x24 */ s32 unk24;
} O01OwnI;
extern s32 D_80153778;
extern s32 D_80153784;
extern s32 D_80153710;
extern s32 D_8014ADA0;
extern u8 D_8014561C[];
s32 func_00406178(O01OwnI *o, s32 pad, s32 z);
void func_004426E4(u8 *a, void *b, void *c, void *d, s32 e);

s32 func_00409474(s32 unused, O01OwnI *own) {
    s32 pad;
    u8 *msg;
    u8 *a0;
    switch (D_80153778) {
    case 4:
        if (D_8015375C != 0) {
            pad = D_800E28C8;
        } else {
            pad = own->unk20->unk4;
        }
        if (func_00406178(own, pad, 1) != 0) {
            D_80153784 = 1;
            func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        } else {
            func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        }
        break;
    case 3:
        if (D_8015375C != 0) {
            pad = D_800E28C8;
        } else {
            pad = own->unk20->unk4;
        }
        if (func_00406178(own, pad, 1) != 0) {
            D_80153784 = 1;
            func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        } else {
            func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        }
        break;
    case 0:
        if (D_8015375C != 0) {
            pad = D_800E28C8;
        } else {
            pad = own->unk20->unk4;
        }
        if (func_00406178(own, pad, 1) != 0) {
            D_80153784 = 1;
            func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        } else {
            func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        }
        break;
    case 1:
    case 2:
        D_80153784 = 1;
        D_80153710 = 0;
        if (D_8015375C != 0) {
            D_8014ADA0 = 1;
            return 1;
        }
        msg = O01GetMsg((O01Obj3 *)own);
        if (msg == 0) {
            msg = (u8 *)own->unk24;
        }
        if (own->unk1C != 0) {
            a0 = own->unk1C->unk5DC + 0x554;
        } else {
            a0 = D_8014561C;
        }
        func_004426E4(a0, msg, own->unk1C, own->unk20, 0);
        break;
    }
    return 1;
}
