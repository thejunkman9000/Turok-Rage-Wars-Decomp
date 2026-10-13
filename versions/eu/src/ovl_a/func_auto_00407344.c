#include "o01_types.h"
extern u8 D_auto_80152789;
extern u8 D_auto_80152208[];

typedef struct O01Plr3 {
    /* 0x000 */ u8 pad0[0x698];
    /* 0x698 */ s32 unk698;
} O01Plr3;
typedef struct O01Sub9 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub9;
typedef struct O01OwnJ {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ O01Plr3 *unk1C;
    /* 0x20 */ O01Sub9 *unk20;
} O01OwnJ;
typedef struct O01Pad { s32 v; s32 freeb; s32 cnt; } O01Pad;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153750;
extern s32 D_800E28B0;
extern s32 D_800E28B4;
extern s32 D_800E28B8;
extern s32 D_800E28BC;
extern char *D_auto_800E25A4[];
extern char *D_auto_800E25D4[];
extern u8 D_80153738[];
extern u8 D_8014561C[];
extern u8 D_auto_0044FC6C[];
extern u8 D_auto_0044FDF8[];
extern u8 D_auto_0044FE88[];
extern u8 D_00451820[];
extern u8 D_00451844[];
extern u8 D_00451868[];
extern u8 D_0045188C[];
s32 func_004057EC(s32 n);
s32 func_00405160(s32 pad, s32 *out);
s32 func_004050CC(s32 pad, s32 *out);
s32 func_00405454(s32 pad, u8 *ext);
s32 func_auto_00404958(s32 pad, s32 size, u8 *buf, char *n1, u8 *ext, char *n2);
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
void func_004426E4(u8 *a, void *b, void *c, s32 d, void *e);

static inline u8 *O01Pick(O01Pad *sel) {
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

static inline void O01FreeAll(void) {
    if (D_800E28B0 != 0 || D_800E28B4 != 0) {
        func_002538A8(0);
    }
    if (D_800E28B0 != 0) {
        func_002537D8(0, D_800E28B0);
    }
    if (D_800E28B4 != 0) {
        func_002537D8(0, D_800E28B4);
    }
    D_800E28B0 = 0;
    D_800E28B4 = 0;
    D_800E28B8 = 0;
    D_800E28BC = 0;
}

s32 func_auto_00407344(s32 unused, O01OwnJ *own, s32 unused3) {
    O01Plr3 *plr;
    O01Plr3 *pp;
    s32 pv;
    u8 ext[8];
    O01Pad pad;
    s32 r = 0;
    s32 ok = 1;
    s32 flag = 0;
    s32 need;
    u32 nv;
    if (D_8015375C != 0) {
        pv = D_800E28C8;
        pp = 0;
    } else {
        pv = own->unk20->unk4;
        pp = own->unk1C;
    }
    pad.v = pv;
    plr = pp;
    if (D_80153750 != 0) {
        need = func_004057EC(0x18);
        r = func_00405160(pad.v, &pad.freeb);
        if (r == 0) {
            if (pad.freeb >= need) {
                r = func_004050CC(pad.v, &pad.cnt);
                if (r == 0 && pad.cnt != 0) {
                    ok = 0;
                    r = func_00405454(pad.v, ext);
                    if (r == 0) {
                        flag = 1;
                        nv = pad.v;
                        { u8 *lb = D_auto_80152208;
                        r = func_auto_00404958(nv, 0x18, D_80153738, D_auto_800E25A4[lb[0x581]], ext, D_auto_800E25D4[lb[0x581]]); }
                    }
                }
            }
            if (ok != 0) {
                func_004426E4(D_8014561C, D_auto_0044FC6C, plr, plr->unk698, (void *)own->unk14);
                return 0;
            }
        }
    }
    O01FreeAll();
    if (flag != 0) {
        if (r == 0) {
            func_004426E4(D_8014561C, D_auto_0044FDF8, plr, plr->unk698, O01Pick(&pad));
        } else {
            func_004426E4(D_8014561C, D_auto_0044FE88, plr, plr->unk698, O01Pick(&pad));
        }
    }
    return 1;
}
