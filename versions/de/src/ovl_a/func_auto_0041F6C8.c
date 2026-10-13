#include "o03_types.h"
typedef struct Q2It { u8 pad0[0x10]; u8 alpha; u8 pad11[3]; u16 f14; u16 f16; s16 f18; } Q2It;
typedef struct Q2W { u8 pad0[0x10]; u8 alpha; u8 pad11[3]; s16 f14; s16 f16; } Q2W;
typedef struct Q2Dsc { u8 pad0[0xC]; s16 f0C; u8 padE[6]; s16 f14; s16 f16; } Q2Dsc;
typedef struct Q2Rec {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 f4;
    /* 0x08 */ Q2W *w8;
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
    /* 0x1340 */ void *w20;
    /* 0x1344 */ void *w24;
    /* 0x1348 */ Q2W *w28;
    /* 0x134C */ s32 f2C;
    /* 0x1350 */ s32 tick;
    /* 0x1354 */ s32 f34;
} Q2Pg;
extern Q2Pg *D_800E42D0;
extern O3Row D_800E3A50[];
extern f32 cosf(f32 x);
void func_0025DF54(s32 a);
void func_0040E958(void *it, s32 on);
void func_00419FD8(void *p, s32 n);
s32 func_00419FB8(void *p);
void func_00419FA4(void *p);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_002A3358(void);
Q2Dsc *func_0041B87C(s32 m, s32 i);
s32 func_0040EC50(void *p);
s32 func_0041F248(s32 key);
s32 func_0041F1FC(s32 key);
void func_0041CB48(void *o, s32 a, s32 b, s32 c, s32 d, O3Vec3 v, O3V3i w, f32 f, s32 g);
void func_004208C0(s32 i);
void func_004204A8(s32 i);
s32 func_auto_0041F6C8(s32 a0, s32 a1, s32 dt) {
    s32 i, x, y, t, ch, row;
    Q2Dsc *d;
    O3Vec3 v;
    Q2Pg *p;
    f32 fv;
    switch (D_800E42D0->state) {
    case 1:
        D_800E42D0->a->f14 = D_800E42D0->a->f14 + (u16)D_800E42D0->ta;
        D_800E42D0->b->f14 = D_800E42D0->b->f14 - (u16)D_800E42D0->tb;
        D_800E42D0->timer = D_800E42D0->timer - 1;
        if (D_800E42D0->timer <= 0) {
            func_0025DF54(0xE79);
            func_0040E958(D_800E42D0->w24, 1);
            func_00419FD8(D_800E42D0->w20, 4);
            D_800E42D0->state = 4;
            D_800E42D0->timer = 4;
        }
        break;
    case 2:
        D_800E42D0->a->f14 = D_800E42D0->a->f14 - (u16)D_800E42D0->ta;
        D_800E42D0->b->f14 = D_800E42D0->b->f14 + (u16)D_800E42D0->tb;
        D_800E42D0->timer = D_800E42D0->timer - 1;
        if (D_800E42D0->timer <= 0) {
            D_800E42D0->state = 3;
            func_0029A73C();
            func_00299368(D_800E42D0->f34);
            return 0;
        }
        break;
    case 3:
        func_002A3358();
        break;
    case 4:
        p = D_800E42D0;
        y = p->timer;
        x = y - 1;
        if (x >= 0) {
            t = y - (y >= x);
        } else {
            t = 0;
        }
        p->timer = t;
        if (D_800E42D0->timer <= 0) {
            if (func_00419FB8(D_800E42D0->w20) != 0) {
                func_00419FA4(D_800E42D0->w20);
                D_800E42D0->state = 6;
                D_800E42D0->timer = 4;
                func_0040E958(D_800E42D0->w28, 1);
            }
        }
        break;
    case 5:
        func_0025DF54(0xE78);
        D_800E42D0->state = 2;
        D_800E42D0->timer = 4;
        func_0040E958(D_800E42D0->w24, 0);
        func_0040E958(D_800E42D0->w28, 0);
        break;
    case 6:
        D_800E42D0->w28->alpha = D_800E42D0->w28->alpha + (u8)D_800E42D0->f2C;
        D_800E42D0->timer = D_800E42D0->timer - 1;
        if (D_800E42D0->timer <= 0) {
            D_800E42D0->w28->alpha = 0xC8;
            D_800E42D0->state = 3;
        }
        break;
    case 7:
        break;
    }
    if (D_800E42D0->state != 3) {
        return 0;
    }
    D_800E42D0->tick = D_800E42D0->tick + dt;
    for (i = 0; i < 4; i++) {
        if (D_800E42D0->rec[i].state == 1) {
            if (D_800E42D0->rec[i].w8 != 0) {
                fv = cosf((f32)i + (f32)D_800E42D0->tick * 0.0033333334f) * 70.0f + 170.0f;
                D_800E42D0->rec[i].w8->alpha = (u32)fv;
            }
            d = func_0041B87C(D_800E42D0->rec[0].f4, i);
            if (D_800E42D0->rec[i].w8->f14 != d->f14 - 2 || D_800E42D0->rec[i].w8->f16 != d->f16 - 2) {
                func_0025DF54(0xE7F);
                if (func_0040EC50(d) == 0) {
                    if (d->f0C != 0x7F) {
                        D_800E42D0->rec[i].f10 = d->f0C;
                        ch = func_0041F248(D_800E42D0->rec[i].f10);
                        row = func_0041F1FC(D_800E42D0->rec[i].f10);
                        v.x = D_800E3A50[row].fC[i];
                        v.y = D_800E3A50[row].fC[i];
                        v.z = D_800E3A50[row].fC[i];
                        func_0041CB48(((Q2Rec *)(i * 0x4C8 + (s32)D_800E42D0))->sub, 9, ch + 0x38F, 0x4B, 0x5DC0, v, D_800E3A50[row].v2C[i], D_800E3A50[row].f1C[i], D_800E3A50[row].f5C[i]);
                    } else {
                        func_004208C0(i);
                    }
                } else {
                    D_800E42D0->rec[i].f10 = -1;
                }
                func_004204A8(i);
            } else if (d->f0C == 0x7F) {
                func_004208C0(i);
            }
            D_800E42D0->rec[i].w8->f14 = d->f14 - 2;
            D_800E42D0->rec[i].w8->f16 = d->f16 - 2;
        }
    }
    return 0;
}
