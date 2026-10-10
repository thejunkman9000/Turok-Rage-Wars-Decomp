
#include "q01_types.h"
typedef struct Q01V3 { s32 x, y, z; } Q01V3;
typedef struct Q01M76 { s32 w0, w1; s32 unk70; s32 unk74; s32 rest[15]; } Q01M76;
typedef struct Q01Obj { u8 pad0[8]; Q01V3 pos; u8 pad14[0x6C-0x14]; f32 f6C; } Q01Obj;
typedef struct Q01Anim {
    s32 *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad14[4];
    Q01Obj *unk18;
    f32 f1C, f20, f24, f28, f2C, f30, f34;
    s32 unk38;
    u8 pad3C[4];
    s32 unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    u8 pad5C[0xC];
    Q01M76 m68;
    u8 padB4[4];
    s32 unkB8;
    u8 padBC[0xE0-0xBC];
    s32 unkE0, unkE4, unkE8;
    u8 padEC[4];
    Q01V3 vF0;
    f32 fFC;
} Q01Anim;
typedef struct Q01Item { u8 pad0[0x24]; } Q01Item;
typedef struct Q01W { s32 unk0; s32 n; Q01Item items[1]; } Q01W;
typedef struct Q01Key { u8 pad0[0x10]; f32 f10; } Q01Key;
typedef struct Q01KeyHdr { s32 unk0; s32 n; Q01Key k[1]; } Q01KeyHdr;
typedef struct Q01Dat { u8 pad0[0x34]; s32 f34; u8 pad38[0x74-0x38]; s32 f74; } Q01Dat;
extern Q01Anim *D_800E2830;
extern Q01Dat D_8011FE88[];
extern s32 D_8011FEBC;
extern s32 D_8011FEFC;
extern Q01Obj *D_80145060;
extern f32 D_800E0B48;
extern u8 D_800E0B40[];
extern u8 D_800E0B2C[];
void func_00245B18();
s32 func_0028FE1C(s32 a, s32 b, s32 c, s32 *d);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
void func_0040067C();
s32 func_00403A64();
Q01W *func_00403A90(s32 i);
Q01KeyHdr *func_00403ADC();
void func_002536F4(s32 a, s32 *b);

s32 func_004009F4(s32 arg0) {
    s32 sp28, sp2C;
    Q01Obj *s3 = D_80145060;
    s32 s5 = D_800E2830->unk58;
    s32 *p, *q;
    s32 v;
    s32 s0, s1;
    s32 ga, gb;
    Q01Anim *pp;
    register s32 z __asm__("a2");
    Q01Key *s2;
    f32 fs0;
    Q01KeyHdr *hdr;
    Q01W *w;
    Q01Item *items;
    s32 n;
    Q01M76 *src;
    Q01M76 *a2, *a3;
    if (D_8011FE88->f34 == 0 || D_8011FE88->f74 == 0) { ret0: return 0; }
    if (D_800E2830->unk38 != 0) func_00245B18();
    v = func_0028FE1C(D_8011FE88->f74, D_8011FE88->f34, arg0 + 1, &sp28);
    p = func_002518DC(0, v, v, sp28, 0x33, 0, func_0040067C, D_800E0B40, 1);
    if (p == 0) goto ret0;
    s0 = 0;
    fs0 = 0.0f;
    D_800E2830->unk0 = p;
    D_800E2830->unk4 = *p;
    hdr = func_00403ADC();
    s2 = hdr->k;
    s1 = hdr->n;
    while (s0 < func_00403A64()) {
        w = func_00403A90(s0);
        n = w->n;
        items = w->items;
        if (n > 0) fs0 += *(f32 *)((u8 *)(items + n) - 8);
        s0++;
    }
    s0 = 0;
    D_800E2830->f30 = 0.0f;
    D_800E2830->f34 = fs0;
    D_800E2830->f28 = 0.0f;
    D_800E2830->f2C = fs0;
    if (s1 > 0) {
        do {
            if (D_800E2830->f28 > s2[s0].f10) D_800E2830->f28 = s2[s0].f10;
            if (D_800E2830->f2C < s2[s0].f10) D_800E2830->f2C = s2[s0].f10;
            s0++;
        } while (s0 < s1);
    }
    pp = D_800E2830;
    __asm__ volatile("" : "+r"(pp));
    z = 0;
    __asm__ volatile("" : "+r"(z));
    pp->f1C = pp->f28;
    pp->f20 = pp->f28;
    pp->f24 = pp->f28;
    ga = D_8011FEFC;
    gb = D_8011FEBC;
    __asm__("");
    s0 = pp->m68.unk70;
    v = func_0028FE1C(ga, gb, z, &sp2C);
    if (v == 0) {
        q = 0;
    } else {
        q = func_002518DC(0, v, v, sp2C, 0x33, 0, 0, D_800E0B2C, 1);
    }
    {
        u8 *b = (u8 *)*q + 8;
        src = (Q01M76 *)(arg0 * 0x4C + (u32)b);
    }
    D_800E2830->unk54 = s5;
    D_800E2830->unk38 = 1;
    D_800E2830->m68 = *src;
    D_800E2830->unk50 = 0;
    D_800E2830->unk40 = 0;
    D_800E2830->unk44 = 0;
    D_800E2830->unk48 = 0;
    D_800E2830->unkE0 = D_800E2830->m68.unk70;
    if (D_800E2830->m68.unk74 & 1) {
        if (D_800E2830->unk18 != 0) {
            D_800E2830->vF0 = D_800E2830->unk18->pos;
            D_800E2830->fFC = D_800E2830->unk18->f6C + D_800E0B48;
        }
    }
    if (D_800E2830->m68.unk74 & 2) {
        if (s3 != 0) {
            D_800E2830->vF0 = s3->pos;
            D_800E2830->fFC = s3->f6C;
        } else {
            D_800E2830->vF0.x = 0;
            D_800E2830->vF0.y = 0;
            D_800E2830->vF0.z = 0;
            D_800E2830->fFC = 0.0f;
        }
    }
    func_002536F4(0, q);
    if (s5 != 0) {
        s32 a0 = D_800E2830->unkE4;
        s32 a1 = D_800E2830->unkE8;
        D_800E2830->unk54 = 1;
        D_800E2830->unk4C = 0;
        D_800E2830->unkE4 = 0;
        D_800E2830->unkE8 = 0;
        D_800E2830->unkB8 = D_800E2830->m68.unk74 & 8;
        D_800E2830->unkC = a0;
        D_800E2830->unk10 = a1;
        if ((u32)(D_800E2830->unkE0 - 0xA) < 0x47U) D_800E2830->unkB8 = 0;
        if ((u32)(D_800E2830->unkE0 - 0x190) < 4U) D_800E2830->unkB8 = 0;
    } else {
        if (D_800E2830->m68.unk70 < 3) D_800E2830->unkE0 = s0;
        D_800E2830->unk54 = 0;
        D_800E2830->f1C = D_800E2830->f30;
    }
    if (D_800E2830->m68.unk70 == 0x9F) D_800E2830->unkB8 = 0;
    return 1;
}


