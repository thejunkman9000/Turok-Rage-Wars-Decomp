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

u8 *func_0040A0C8(O01Obj3 *a) {
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
