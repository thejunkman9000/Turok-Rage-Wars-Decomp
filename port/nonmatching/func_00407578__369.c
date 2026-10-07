#include "o01_types.h"

typedef struct O01Plr3 {
    /* 0x000 */ u8 pad0[0x698];
    /* 0x698 */ s32 unk698;
} O01Plr3;
typedef struct O01Sub9 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub9;
typedef struct O01Own9 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ O01Plr3 *unk1C;
    /* 0x20 */ O01Sub9 *unk20;
} O01Own9;
typedef struct O01Pad { s32 v; s32 w; } O01Pad;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_8011FECC;
extern s32 D_80153750;
extern s32 D_800E28B0;
extern s32 D_800E28B4;
extern s32 D_800E28B8;
extern s32 D_800E28BC;
extern char *D_800D7704;
extern char *D_800D770C;
extern u8 D_8014561C[];
extern u8 D_0044FAFC[];
u32 func_004057EC(u32 n);
s32 func_00405160(s32 pad, s32 *out);
s32 func_004050CC(s32 pad, s32 *out);
s32 func_00405454(s32 pad, u8 *ext);
void func_00404958(s32 pad, s32 size, s32 buf, char *n1, u8 *ext, char *n2);
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
void func_004426E4(u8 *a, void *b, void *c, s32 d, s32 e);

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

s32 func_00407578(s32 unused, O01Own9 *own) {
    u8 ext[8];
    O01Pad pad;
    s32 freeb;
    s32 cnt;
    O01Plr3 *plr;
    O01Plr3 *p0;
    s32 ok = 1;
    s32 size;
    s32 need;
    if (D_8015375C != 0) {
        pad.v = D_800E28C8;
        plr = 0;
    } else {
        pad.v = own->unk20->unk4;
        plr = own->unk1C;
    }
    size = D_8011FECC + 0x610;
    if (D_80153750 != 0) {
        need = func_004057EC(size);
        if (func_00405160(pad.v, &freeb) == 0) {
            if (freeb >= need) {
                if (func_004050CC(pad.v, &cnt) == 0 && cnt != 0) {
                    ok = 0;
                    if (func_00405454(pad.v, ext) == 0) {
                        func_00404958(pad.v, size, D_800E28B8, D_800D7704, ext, D_800D770C);
                    }
                }
            }
            if (ok != 0) {
                func_004426E4(D_8014561C, D_0044FAFC, plr, plr->unk698, own->unk14);
                return 0;
            }
        }
    }
    O01FreeAll();
    return 1;
}
