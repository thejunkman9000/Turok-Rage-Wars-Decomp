#include "common.h"

/* view of the state block starting at D_8014AEBC */
typedef struct B21RecX {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s32 **unk10;
    /* 0x014 */ s32 *unk14;
    /* 0x018 */ s32 *unk18;
    /* 0x01C */ s32 *unk1C;
    /* 0x020 */ u8 pad20[0x2120 - 0x20];
    /* 0x2120 */ s32 *unk2120;
    /* 0x2124 */ s32 *unk2124;
    /* 0x2128 */ s32 *unk2128;
    /* 0x212C */ char buf212C[0x80];
} B21RecX;

typedef struct B21Ctx {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x2C];
    /* 0x50 */ s32 unk50;
} B21Ctx;

extern B21RecX D_8014AEBC;
extern s32 *D_8014AECC;
extern s32 *D_8014AED0;
extern s32 *D_8014AED4;
extern s32 *D_8014AED8;
extern s32 D_8014D068;
extern B21Ctx D_8011FE88[];
extern u8 D_800CA5D0[];
extern char D_800CA5E0[];
extern char D_800CA5F8[];
void func_00295B90();
void func_002536F4(s32 a, void *b);
s32 *func_0028FD94(s32 *n, s32 idx);
s32 func_0028FE1C(s32 a, s32 b, s32 c, s32 *out);
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *cb, void *g, s32 h);

void func_00294CA0(void) {
    s32 sp28;
    s32 **obj;
    s32 *s3;
    s32 *s2;
    s32 *s5;
    s32 v0;
    s32 s4;
    s32 s0;
    s32 *s1;
    s32 i;
    u8 *p;
    B21Ctx *c = D_8011FE88;

    if (D_8014AECC != NULL) {
        func_002536F4(0, D_8014AECC);
    }
    D_8014AECC = NULL;
    D_8014AED4 = NULL;
    D_8014AED8 = NULL;
    D_8014AED0 = NULL;
    v0 = func_0028FE1C(c->unk50, c->unk20, D_8014AEBC.unk0, &sp28);
    obj = func_002518DC(0, v0 - 1, v0, sp28, 9, -1, func_00295B90, D_800CA5D0, 1);
    s3 = *obj;
    s2 = func_0028FD94(s3, 1);
    s5 = func_0028FD94(s3, 2);
    while (D_8014AEBC.unk4 < 0) {
        D_8014AEBC.unk4 += *s2;
    }
    s4 = D_8014AEBC.unk4 % *s2;
    s0 = D_8014AEBC.unk4 % *s5;
    D_8014AEBC.unk10 = obj;
    D_8014AEBC.unk18 = func_0028FD94(s2, s4);
    D_8014AEBC.unk1C = func_0028FD94(s5, s0);
    D_8014AEBC.unk14 = func_0028FD94(s3, 0);
    D_8014AEBC.unkC = 0;
    D_8014AEBC.unk2120 = s3;
    D_8014AEBC.unk2124 = s2;
    D_8014AEBC.unk2128 = s5;
    if (*s3 == 4) {
        s1 = func_0028FD94(s3, 3);
        i = 0;
        while (i < (s32)strlen((u8 *)s1)) {
            p = (u8 *)s1 + i;
            i++;
            if (*p == 0x2E) {
                *p = 0;
                break;
            }
        }
        sprintf(D_8014AEBC.buf212C, D_800CA5E0, D_8014AEBC.unk0, s4, *s2, s1);
    } else {
        sprintf(D_8014AEBC.buf212C, D_800CA5F8, D_8014AEBC.unk0, s4, *s2);
    }
    D_8014D068 = 0;
}
