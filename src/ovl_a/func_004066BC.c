#include "o01_types.h"

typedef struct O01Plr2 {
    /* 0x000 */ u8 pad0[0x5DC];
    /* 0x5DC */ u8 *unk5DC;
} O01Plr2;
typedef struct O01Sub6 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub6;
typedef struct O01Fl6 {
    /* 0x000 */ u8 pad0[0x328];
    /* 0x328 */ u32 unk328;
} O01Fl6;
typedef struct O01Own6 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ O01Fl6 *unkC;
    /* 0x10 */ u8 pad10[0xC];
    /* 0x1C */ O01Plr2 *unk1C;
    /* 0x20 */ O01Sub6 *unk20;
} O01Own6;
extern s32 D_80153750;
extern s32 D_8015376C;
extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_800E28C4;
extern s32 D_80153784;
extern s32 D_8015375C;
extern s32 D_800E28C0;
extern u8 D_8014561C[];
extern u8 D_0045077C[];
extern u8 D_0044F67C[];
extern u8 D_0044F994[];
extern u8 D_0044F0B8[];
extern u8 D_0044F610[];
void func_00404E28(s32 ch);
s32 func_00404F04(s32 ch);
s32 func_00404F3C(s32 ch);
s32 func_00405598(s32 ch);
void func_00405F48(O01Own6 *o);
void func_004426E4(u8 *a, void *b, void *c, void *d, void *e);

void func_004066BC(O01Own6 *own) {
    s32 pad;
    D_80153750 = 0;
    D_8015376C = 0;
    D_80153760 = 1;
    D_8015377C = 1;
    D_800E28C4 = 1;
    D_80153784 = 0;
    D_8015375C = 0;
    own->unkC->unk328 &= 0xFEFFFFFF;
    pad = own->unk20->unk4;
    if (D_800E28C0 != 0) {
        D_80153784 = 1;
        func_004426E4(own->unk1C->unk5DC + 0x554, D_0045077C, own->unk1C, own->unk20, 0);
    } else {
        func_00404E28(pad);
        if (func_00404F04(pad) == 0) {
            func_00405F48(own);
        } else {
            D_80153784 = 1;
            if (func_00404F3C(pad) != 0) {
                func_004426E4(D_8014561C, D_0044F67C, own->unk1C, own->unk20, D_0045077C);
            } else if (func_00405598(pad) != 0) {
                func_004426E4(D_8014561C, D_0044F994, own->unk1C, own->unk20, D_0044F0B8);
            } else {
                func_004426E4(D_8014561C, D_0044F610, own->unk1C, own->unk20, D_0045077C);
            }
        }
    }
}
