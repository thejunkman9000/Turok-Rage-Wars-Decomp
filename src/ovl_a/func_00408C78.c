#include "o01_types.h"

typedef struct O01Save {
    /* 0x0 */ u16 w[4];
    /* 0x8 */ u8 b0;
    /* 0x9 */ u8 b1;
    /* 0xA */ u8 b2;
    /* 0xB */ u8 b3;
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
} O01Actor;
typedef struct O01Sub8 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub8;
typedef struct O01Own8 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ O01Actor *unk1C;
    /* 0x20 */ O01Sub8 *unk20;
    /* 0x24 */ s32 unk24;
} O01Own8;
extern O01Save D_80153738;
extern u8 D_80153744[8];
extern s8 D_80153720[];
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153784;
extern s32 D_80153730;
extern s32 D_8015378C;
extern u8 D_80145040[];
extern u8 D_8014561C[];
extern u8 D_00450698[];
extern u8 D_0044F7C0[];
extern u8 D_0044F82C[];
s32 func_00406178(O01Own8 *o, s32 pad, s32 z);
O01Actor *func_0022A5B0(u8 *world, O01Sub8 *s);
void func_0044AD14(O01Actor *a, s32 b);
void func_00442934(u8 *a, O01Own8 *o, u8 *c);
s32 func_00404858(s32 pad, s32 idx);
void func_004426E4(u8 *a, void *b, void *c, void *d, void *e);

static inline void O01Restore(O01Actor *a) {
    O01SaveSrc *p = a->save;
    s32 i;
    p->b0 = D_80153738.b0;
    p->w[0] = D_80153738.w[0];
    p->w[1] = D_80153738.w[1];
    p->w[2] = D_80153738.w[2];
    p->w[3] = D_80153738.w[3];
    for (i = 0; i < 8; i++) {
        p->tail[i] = D_80153744[i];
    }
}

s32 func_00408C78(s32 unused, O01Own8 *own) {
    s32 pad;
    O01Actor *plr;
    if (D_8015375C != 0) {
        pad = D_800E28C8;
    } else {
        pad = own->unk20->unk4;
    }
    if (func_00406178(own, pad, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_80153730 != 0) {
        plr = func_0022A5B0(D_80145040, own->unk20);
        own->unk1C = plr;
        O01Restore(plr);
        func_0044AD14(plr, D_80153720[0]);
        func_00442934(plr->unk5DC + 0x554, own, D_00450698);
        return 1;
    }
    if (func_00404858(pad, D_8015378C) == 0) {
        func_004426E4(D_8014561C, D_0044F7C0, own->unk1C, own->unk20, (void *)own->unk24);
    } else {
        func_004426E4(D_8014561C, D_0044F82C, own->unk1C, own->unk20, (void *)own->unk24);
    }
    return 1;
}
