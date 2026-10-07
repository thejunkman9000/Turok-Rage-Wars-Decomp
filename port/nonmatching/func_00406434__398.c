#include "o01_types.h"

typedef struct O01Save {
    /* 0x0 */ u16 w[4];
    /* 0x8 */ u8 b0;
    /* 0x9 */ u8 b1;
    /* 0xA */ u8 b2;
    /* 0xB */ u8 b3;
    /* 0xC */ u8 padC[8];
    /* 0x14 */ u32 crc;
} O01Save;
typedef struct O01SaveSrc {
    /* 0x00 */ u16 w[4];
    /* 0x08 */ u8 pad8[0x78];
    /* 0x80 */ u8 b0;
    /* 0x81 */ u8 pad81[3];
    /* 0x84 */ u8 tail[8];
} O01SaveSrc;
typedef struct O01Actor {
    /* 0x000 */ u8 pad0[0x5D8];
    /* 0x5D8 */ O01SaveSrc *save;
    /* 0x5DC */ u8 *unk5DC;
    /* 0x5E0 */ u8 pad5E0[0xB8];
    /* 0x698 */ s32 unk698;
} O01Actor;
typedef struct O01SubC {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01SubC;
typedef struct O01OwnC {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ O01Actor *unk1C;
    /* 0x20 */ O01SubC *unk20;
} O01OwnC;
typedef struct O01Sel { s32 v; s32 w; } O01Sel;
extern s32 D_80153750;
extern s32 D_8015376C;
extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_800E28C4;
extern s32 D_80153784;
extern s32 D_8015375C;
extern s32 D_800E28C0;
extern s32 D_800E28C8;
extern O01Save D_80153738;
extern u8 D_80153744[8];
extern u8 D_8014561C[];
extern u8 D_0044F658[];
extern u8 D_0044F994[];
extern u8 D_0044F610[];
extern u8 D_0044F0DC[];
extern u8 D_00451820[];
extern u8 D_00451844[];
extern u8 D_00451868[];
extern u8 D_0045188C[];
void func_00404E28(s32 ch);
s32 func_00404F04(s32 ch);
s32 func_00404F3C(s32 ch);
s32 func_00405598(s32 ch);
void func_00405F48(O01OwnC *o);
u32 func_004057F8(u8 *data, s32 len, u32 crc);
void func_004426E4(u8 *a, void *b, void *c, s32 d, void *e);

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

static inline void O01Capture(O01Actor *a) {
    O01SaveSrc *p = a->save;
    s32 i;
    D_80153738.b0 = p->b0;
    D_80153738.w[0] = p->w[0];
    D_80153738.w[1] = p->w[1];
    D_80153738.w[2] = p->w[2];
    D_80153738.w[3] = p->w[3];
    D_80153738.b1 = 0;
    D_80153738.b2 = 0;
    D_80153738.b3 = 0;
    for (i = 0; i < 8; i++) {
        D_80153744[i] = p->tail[i];
    }
}

void func_00406434(O01OwnC *own) {
    O01Actor *plr;
    O01Sel sel;
    u8 *msg;
    s32 pad;
    D_80153750 = 1;
    D_8015376C = 1;
    D_80153760 = 0;
    D_8015377C = 1;
    D_800E28C4 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    sel.v = own->unk20->unk4;
    plr = own->unk1C;
    msg = O01Pick(&sel);
    if (D_800E28C0 != 0) {
        D_80153784 = 1;
        func_004426E4(own->unk1C->unk5DC + 0x554, msg, plr, plr->unk698, 0);
    } else {
        if (D_8015375C != 0) {
            pad = D_800E28C8;
        } else {
            pad = own->unk20->unk4;
        }
        func_00404E28(pad);
        if (func_00404F04(sel.v) == 0) {
            O01Capture(plr);
            D_80153738.crc = func_004057F8((u8 *)&D_80153738, 0x14, 4);
            func_00405F48(own);
        } else {
            D_80153784 = 1;
            if (func_00404F3C(sel.v) != 0) {
                func_004426E4(D_8014561C, D_0044F658, plr, plr->unk698, msg);
            } else if (func_00405598(sel.v) != 0) {
                func_004426E4(D_8014561C, D_0044F994, plr, plr->unk698, D_0044F0DC);
            } else {
                func_004426E4(D_8014561C, D_0044F610, plr, plr->unk698, msg);
            }
        }
    }
}
