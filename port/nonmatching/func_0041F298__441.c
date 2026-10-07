#include "o03_types.h"
typedef struct Q2It { u8 pad0[0x10]; u8 alpha; u8 pad11[3]; u16 f14; u16 f16; s16 f18; } Q2It;
typedef struct Q2Rec {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 state;
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ u8 sub[0x4A8];
} Q2Rec;
typedef struct Q2Pg {
    /* 0x0000 */ Q2Rec rec[4];
    /* 0x1320 */ s32 f1320;
    /* 0x1324 */ s32 f1324;
    /* 0x1328 */ Q2It *a;
    /* 0x132C */ s32 ta;
    /* 0x1330 */ Q2It *b;
    /* 0x1334 */ s32 tb;
    /* 0x1338 */ s32 state;
    /* 0x133C */ s32 timer;
    /* 0x1340 */ s32 w20;
    /* 0x1344 */ void *w24;
    /* 0x1348 */ void *w28;
    /* 0x134C */ s32 f2C;
    /* 0x1350 */ s32 tick;
    /* 0x1354 */ s32 f34;
} Q2Pg;
typedef struct { s32 key; O3Id a1; O3Id a2; O3Id b[3]; O3Id c[3]; } Q2IdRow;
extern Q2Pg *D_800E42D0;
extern Q2IdRow D_800E42D4[];
extern O3Row D_800E3A50[];
extern O3Pl4 D_80146398[];
extern f32 D_800E1570;
void *func_00252FFC(s32 size);
s32 func_0041B690(s32 p, s32 n);
void func_0041B768(s32 p, s32 i, s32 id);
void func_0042EB80();
s32 func_0041F1FC(s32 key);
s32 func_0041F248(s32 key);
void func_0041CB48(void *o, s32 a, s32 b, s32 c, s32 d, O3Vec3 v, O3V3i w, f32 f, s32 g);
Q2It *func_0040ECB0(s32 p, u16 id);
void func_0040E958(void *it, s32 on);
s32 func_00419ED4(s32 a, s32 b);
void func_0041FF9C(void);
void func_00420378(s32 i);
void func_002A338C();
s32 func_0041F298(s32 root) {
    O3Vec3 v;
    s32 i, k, key, ch, row, t, r;
    Q2It *ia, *ia2, *ib, *ib2;
    Q2Rec *p;
    D_800E42D0 = func_00252FFC(0x1358);
    D_800E42D0->rec[0].f0 = root;
    D_800E42D0->rec[0].f4 = func_0041B690(root, 4);
    func_0041B768(root, 0, 0x7A);
    func_0041B768(root, 1, 0x7A);
    func_0041B768(root, 2, 0x7A);
    func_0041B768(root, 3, 0x7A);
    func_0042EB80(0, 0);
    D_800E42D0->tick = 0;
    v.x = D_800E1570;
    v.y = D_800E1570;
    v.z = D_800E1570;
    i = 0;
    do {
        p = &D_800E42D0->rec[i];
        p->fC = 0;
        key = D_800E42D4[i].key;
        p->f8 = 0;
        p->state = 0;
        p->f18 = 0;
        *(s32 *)((u8 *)p + 0x4C8) = 0;
        p->f10 = key;
        ch = func_0041F248(key);
        row = func_0041F1FC(D_800E42D0->rec[i].f10);
        v.x = D_800E3A50[row].fC[i];
        v.y = D_800E3A50[row].fC[i];
        v.z = D_800E3A50[row].fC[i];
        func_0041CB48((u8 *)D_800E42D0 + (i * 0x4C8 + 8) + 0x18, 9, ch + 0x38F, 0x4B, 0x5DC0, v, D_800E3A50[row].v2C[i], D_800E3A50[row].f1C[i], D_800E3A50[row].f5C[i]);
        func_0040ECB0(D_800E42D0->rec[0].f0, D_800E42D4[i].a2.id)->alpha = 0x6E;
        for (k = 0; k < 3; k++) {
            func_0040ECB0(D_800E42D0->rec[0].f0, D_800E42D4[i].b[k].id)->alpha = 0x50;
            func_0040E958(func_0040ECB0(D_800E42D0->rec[0].f0, D_800E42D4[i].c[k].id), 1);
        }
        i++;
    } while (i < 4);
    D_800E42D0->state = 1;
    D_800E42D0->timer = 4;
    ia = func_0040ECB0(root, 0xAC);
    D_800E42D0->a = ia;
    ia->f14 = ia->f14 - ia->f18;
    t = D_800E42D0->a->f18;
    if (t < 0) {
        t += 3;
    }
    t >>= 2;
    D_800E42D0->ta = t;
    ia2 = D_800E42D0->a;
    r = ia2->f18 - t * 4;
    ia2->f14 = ia2->f14 + r;
    ib = func_0040ECB0(root, 0x93);
    D_800E42D0->b = ib;
    ib->f14 = ib->f14 + ib->f18;
    t = D_800E42D0->b->f18;
    if (t < 0) {
        t += 3;
    }
    k = 0;
    t >>= 2;
    D_800E42D0->tb = t;
    ib2 = D_800E42D0->b;
    r = ib2->f18 - t * 4;
    ib2->f14 = ib2->f14 - r;
    func_0040ECB0(root, 0x76)->alpha = 0x6E;
    func_0040ECB0(root, 0x79)->alpha = 0x19;
    D_800E42D0->w20 = func_00419ED4(0x74, 0xFF);
    D_800E42D0->w24 = func_0040ECB0(root, 0x74);
    func_0040E958(D_800E42D0->w24, k);
    D_800E42D0->w28 = func_0040ECB0(root, 0x7B);
    func_0040E958(D_800E42D0->w28, k);
    ((u8 *)D_800E42D0->w28)[0x10] = 0;
    D_800E42D0->f2C = 0x32;
    func_0041FF9C();
    for (i = 0; i < 4; i++) {
        if (D_80146398[i].f78 == 1) {
            func_00420378(i);
        }
    }
    func_002A338C();
    D_800E42D0->f34 = -1;
    return 0;
}
