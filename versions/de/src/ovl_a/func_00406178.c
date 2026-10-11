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

typedef struct O01OwnB {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ void *unk1C;
    /* 0x20 */ O01Sub3 *unk20;
} O01OwnB;
extern s32 D_80153784;
extern u8 D_8014561C[];
extern u8 D_0044F6E8[];
extern u8 D_0044F634[];
extern u8 D_0044F67C[];
extern u8 D_0044F658[];
extern u8 D_0044F994[];
extern u8 D_0044F610[];
void func_00404E28(s32 ch);
s32 func_00404F04(s32 ch);
s32 func_002645A0(s32 ch);
s32 func_00404F3C(s32 ch);
s32 func_00405598(s32 ch);
void func_004426E4(u8 *a, void *b, void *c, void *d, void *e);

s32 func_00406178(O01OwnB *own, s32 pad, s32 mode) {
    u8 *msg;
    register s32 st __asm__("$18");
    s32 v;
    u8 *a1;
    func_00404E28(pad);
    st = func_00404F04(pad);
    msg = O01GetMsg((O01Obj3 *)own);
    if (msg == 0) {
        return 0;
    }
    v = func_002645A0(pad);
    if (!((st != 0 && v == 0) || st == -2)) {
        if (v == 0) {
            return st;
        }
        func_004426E4(D_8014561C, D_0044F6E8, own->unk1C, own->unk20, msg);
        return -1;
    }
    if (func_00404F3C(pad) != 0) {
        D_80153784 = 1;
        if (D_8015375C != 0) {
            a1 = D_0044F634;
        } else if (D_80153750 != 0) {
            a1 = D_0044F658;
        } else {
            a1 = D_0044F67C;
        }
        func_004426E4(D_8014561C, a1, own->unk1C, own->unk20, msg);
        return st;
    }
    if (mode == 0) {
        D_80153784 = 1;
        if (func_00405598(pad) != 0) {
            func_004426E4(D_8014561C, D_0044F994, own->unk1C, own->unk20, msg);
            return st;
        } else {
            func_004426E4(D_8014561C, D_0044F610, own->unk1C, own->unk20, msg);
            return st;
        }
    }
    if (st != -2) {
        st = 0;
    }
    return st;
}
