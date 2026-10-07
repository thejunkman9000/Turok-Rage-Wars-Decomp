#include "o01_types.h"

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
s32 func_00293424(s32 a, void *b);

void func_00403200(s32 a) {
    s32 size;
    s32 *p;
    s32 *r;
    s32 i;
    s32 n;
    O01Rec *e;
    O01Rec *ents;
    if (D_800E2838 != 0) {
        p = func_0028FE1C(D_8011FEFC, D_8011FEBC, 0, &size);
        if (p == 0) {
            r = 0;
        } else {
            r = func_002518DC(0, (s32)p, (s32)p, size, 0x33, 0, 0, D_800E0B2C, 1);
        }
        i = 0;
        n = *D_8011FEFC - 1;
        ents = (O01Rec *)(*r + 8);
        for (; i < n; i++) {
            e = &ents[i];
            if (func_00293424(a, (u8 *)e + 0x18) == 0) {
                D_800E2830->unkE0 = e->unk8;
                D_800E2830->unkD8 = e->unk0;
                D_800E2830->unkDC = i;
                D_800E2830->unk58 = 1;
                break;
            }
        }
        func_002536F4(0, r);
    }
}
