#include "o01_types.h"

typedef struct O01Plr2 {
    /* 0x000 */ u8 pad0[0x5DC];
    /* 0x5DC */ u8 *unk5DC;
    /* 0x5E0 */ u8 pad5E0[0xB8];
    /* 0x698 */ s32 unk698;
} O01Plr2;
typedef struct O01Sub6 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub6;
typedef struct O01Own6 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ O01Plr2 *unk1C;
    /* 0x20 */ O01Sub6 *unk20;
} O01Own6;
typedef struct O01Sel { s32 v; s32 w; } O01Sel;
extern s32 D_80153750;
extern s32 D_800E28C8;
extern s32 D_8015376C;
extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_800E28C4;
extern s32 D_80153784;
extern s32 D_8015375C;
extern s32 D_800E28C0;
extern u8 *D_800E28B8;
extern s32 D_8011FECC;
extern u8 D_8014561C[];
extern u8 D_0044F658[];
extern u8 D_0044F994[];
extern u8 D_0044F124[];
void func_00404E28(s32 ch);
s32 func_00404F04(s32 ch);
s32 func_00404F3C(s32 ch);
s32 func_00405598(s32 ch);
void func_00405DC0(O01Plr2 *p);
void func_00405F48(O01Own6 *o);
u32 func_004057F8(u8 *data, s32 len, u32 crc);
void func_004426E4(u8 *a, void *b, void *c, s32 d, void *e);

void func_00406F7C(O01Own6 *own) {
    O01Plr2 *plr;
    O01Sel sel;
    register O01Plr2 *pp __asm__("$2");
    s32 pv;
    D_80153750 = 1;
    D_8015376C = 1;
    D_80153760 = 0;
    D_8015377C = 0;
    D_800E28C4 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    pv = own->unk20->unk4;
    sel.v = pv;
    pp = own->unk1C;
    __asm__ volatile("");
    if (D_800E28C0 != 0) {
        D_80153784 = 1;
    } else {
        plr = pp;
        __asm__ volatile("");
        func_00404E28(own->unk20->unk4);
        if (func_00404F04(sel.v) == 0) {
            func_00405DC0(plr);
            { register u8 *bb __asm__("$5"); register s32 oo __asm__("$3"); u32 r = func_004057F8(D_800E28B8, D_8011FECC + 0x60C, 0xB); bb = D_800E28B8; oo = D_8011FECC; oo += (s32)bb; *(u32 *)(oo + 0x60C) = r; }
            func_00405F48(own);
        } else {
            s32 one;
            __asm__("" : "=r"(one) : "0"(1));
            D_80153784 = one;
            if (func_00404F3C(sel.v) != 0) {
                func_004426E4(plr->unk5DC + 0x554, D_0044F658, plr, plr->unk698, (void *)one);
            } else if (func_00405598(sel.v) != 0) {
                func_004426E4(D_8014561C, D_0044F994, plr, plr->unk698, D_0044F124);
            }
        }
    }
}
