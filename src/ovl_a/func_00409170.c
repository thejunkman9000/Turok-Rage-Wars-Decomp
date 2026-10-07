#include "o01_types.h"

typedef struct O01SubH {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01SubH;
typedef struct O01OwnH {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ void *unk1C;
    /* 0x20 */ O01SubH *unk20;
    /* 0x24 */ s32 unk24;
} O01OwnH;
extern s32 D_80153778;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153784;
extern s32 D_80153754;
extern s32 D_8015378C;
extern s32 D_80146D6C;
extern u8 D_8014561C[];
extern u8 D_0044F7C0[];
extern u8 D_0044F82C[];
extern u8 D_0044F7E4[];
extern u8 D_0044F970[];
s32 func_00406178(O01OwnH *o, s32 pad, s32 z);
void func_00404E28(s32 ch);
s32 func_00404858(s32 pad, s32 idx);
s32 func_004051D4(s32 pad);
s32 func_00407578(s32 a, O01OwnH *o, s32 c);
void func_004426E4(u8 *a, void *b, void *c, void *d, s32 e);

s32 func_00409170(s32 a, O01OwnH *own, s32 c) {
    s32 pad;
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
            func_00404E28(pad);
            if (func_00404858(pad, D_80153754) == 0) {
                func_004426E4(D_8014561C, D_0044F7C0, own->unk1C, own->unk20, own->unk24);
            } else {
                func_004426E4(D_8014561C, D_0044F82C, own->unk1C, own->unk20, own->unk24);
            }
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
            func_00404E28(pad);
            if (func_00404858(pad, D_8015378C) == 0) {
                func_00407578(a, own, c);
                return 1;
            } else {
                func_004426E4(D_8014561C, D_0044F82C, own->unk1C, own->unk20, own->unk24);
            }
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
            func_00404E28(pad);
            if (func_004051D4(pad) == 0) {
                func_004426E4(D_8014561C, D_0044F7E4, own->unk1C, own->unk20, own->unk24);
            } else {
                func_004426E4(D_8014561C, D_0044F970, own->unk1C, own->unk20, own->unk24);
            }
        }
        break;
    case 1:
    case 2:
        if (D_8015375C != 0) {
            D_80146D6C = 1;
        }
        func_004426E4(D_8014561C, (void *)own->unk24, own->unk1C, own->unk20, 0);
        break;
    }
    return 1;
}
