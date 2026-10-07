#include "o01_types.h"

typedef struct O01Sel {
    /* 0x0 */ u8 pad0[4];
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u8 pad6[4];
    /* 0xA */ u16 unkA;
} O01Sel;
typedef struct O01Rec {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x3C];
} O01Rec;
extern s32 D_800E2838;
extern s32 *D_8011FEFC;
extern u8 *D_8011FEBC;
extern O01Ctx *D_800E2830;
extern u8 D_800E0B2C[];
void *func_0028FE1C(s32 *tbl, u8 *base, s32 idx, s32 *size);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
void func_002536F4(s32 a, void *b);

void func_00402FB4(s32 arg, O01Sel *sel) {
    s32 found = -1;
    s32 size;
    s32 *p;
    s32 *r;
    s32 i;
    s32 n;
    O01Rec *e;
    s32 k4;
    s32 k0;
    if (D_800E2838 != 0) {
        k4 = sel->unk4;
        k0 = sel->unkA;
        p = func_0028FE1C(D_8011FEFC, D_8011FEBC, 0, &size);
        if (p == 0) {
            r = 0;
        } else {
            r = func_002518DC(0, (s32)p, (s32)p, size, 0x33, 0, 0, D_800E0B2C, 1);
        }
        n = *D_8011FEFC - 1;
        e = (O01Rec *)(*r + 8);
        for (i = 0; i < n; i++, e++) {
            if (e->unk4 == k4) {
                if (e->unk0 == k0) {
                    found = i;
                }
            }
        }
        if (found != -1) {
            D_800E2830->unk18 = arg;
            D_800E2830->unkD8 = k0;
            D_800E2830->unkDC = found;
            D_800E2830->unk58 = 1;
        }
        func_002536F4(0, r);
    }
}
