#include "o03_types.h"
typedef struct Q2It { u8 pad0[0x14]; u16 f14; } Q2It;
typedef struct Q2Lb {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ Q2It *a;
    /* 0x24 */ u16 pad24;
    /* 0x26 */ u16 da;
    /* 0x28 */ Q2It *b;
    /* 0x2C */ u16 pad2C;
    /* 0x2E */ u16 db;
    /* 0x30 */ s32 state;
    /* 0x34 */ s32 timer;
    /* 0x38 */ void *w38;
    /* 0x3C */ void *w3C;
    /* 0x40 */ void *w40;
    /* 0x44 */ void *w44;
    /* 0x48 */ void *w48;
    /* 0x4C */ void *w4C;
    /* 0x50 */ u8 pad50[0xC];
    /* 0x5C */ s32 w5C;
    /* 0x60 */ s32 w60;
    /* 0x64 */ s32 pad64;
    /* 0x68 */ void *w68;
} Q2Lb;
typedef struct Q2Scr { u8 pad0[0x3C]; s32 f3C; } Q2Scr;
extern Q2Lb *D_800E4518;
extern Q2Scr *D_800E2830;
extern s32 D_800E28E0;
extern s32 D_80154024;
extern s32 D_80146894[];
extern u8 D_8011FE88[];
s32 func_0043C4E8(void *p);
void func_002A3358(void);
s32 func_00245788(void);
void func_0040E958(void *it, s32 on);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0029A1D4(s32 a);
void func_0029A73C(void);
void func_00419FD8(void *p, s32 n);
s32 func_00419FB8(void *p);
void func_00419FA4(void *p);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
s32 func_0025471C(void);
void func_0025470C(s32 a);
void func_0025DF54(s32 a);
s32 func_auto_00422B94(void) {
    s32 *g, *q;
    s32 s0;
    s32 x, y, t;
    Q2Lb *p;
    if (D_800E28E0 > 0) {
        goto ret0;
    }
    if (func_0043C4E8(D_800E4518) != 1 && D_800E4518->w5C == 0) {
        D_800E4518->w5C = 1;
        func_002A3358();
        return 0;
    }
    s0 = D_800E2830->f3C;
    if (s0 == 1 && func_00245788() == s0) {
        func_0040E958(D_800E4518->w68, 0);
        func_0040E958(D_800E4518->w44, 0);
        func_0040E958(D_800E4518->w4C, 0);
        D_800E2830->f3C = 0;
    }
    g = &D_80154024;
    if (g[0] == 1) {
        g[0] = 0;
        if (g[-1] != -1) {
            func_0040E958(D_800E4518->w48, 0);
            func_0040E958(D_800E4518->w40, 0);
            func_0029A73C();
            func_00299368(g[-1]);
            return 0;
        }
        func_0040E958(D_800E4518->w48, 1);
        func_0040E958(D_800E4518->w40, 1);
        func_0029A1D4(0x373);
    }
    switch (D_800E4518->state) {
    case 1:
        D_800E4518->a->f14 = D_800E4518->a->f14 + D_800E4518->da;
        D_800E4518->b->f14 = D_800E4518->b->f14 - D_800E4518->db;
        D_800E4518->timer = D_800E4518->timer - 1;
        if (D_800E4518->timer <= 0) {
            func_0040E958(D_800E4518->w3C, 1);
            func_0040E958(D_800E4518->w48, 1);
            func_00419FD8(D_800E4518->w38, 4);
            D_800E4518->state = 4;
            D_800E4518->timer = 4;
        }
        break;
    case 2:
        D_800E4518->a->f14 = D_800E4518->a->f14 - D_800E4518->da;
        D_800E4518->b->f14 = D_800E4518->b->f14 + D_800E4518->db;
        D_800E4518->timer = D_800E4518->timer - 1;
        if (D_800E4518->timer <= 0) {
            q = D_80146894;
            q[0] = 0;
            D_800E4518->state = 3;
            func_0044AFC0((u8 *)q - 0x180C, 0);
            func_0044A600((u8 *)q - 0x1854, 0, 0);
            func_00286A78(D_8011FE88, 0, 0);
            if (func_0025471C() == 0) {
                func_0025470C(1);
            }
            q[-7] = 8;
            func_0029A73C();
            func_00299368(D_800E4518->w60);
            return 0;
        }
        break;
    case 4:
        p = D_800E4518;
        y = p->timer;
        x = y - 1;
        if (x >= 0) {
            t = y - (y >= x);
        } else {
            t = 0;
        }
        p->timer = t;
        if (D_800E4518->timer <= 0) {
            if (func_00419FB8(D_800E4518->w38) != 0) {
                func_00419FA4(D_800E4518->w38);
                D_800E4518->state = 3;
            }
        }
        break;
    case 5:
        func_0025DF54(0xE78);
        func_0040E958(D_800E4518->w3C, 0);
        func_0040E958(D_800E4518->w48, 0);
        func_0040E958(D_800E4518->w44, 1);
        func_0040E958(D_800E4518->w4C, 1);
        func_0040E958(D_800E4518->w68, 1);
        D_800E4518->state = 2;
        D_800E4518->timer = 4;
        break;
    case 3:
        break;
    }
    if (D_800E4518->state != 3) {
        return 0;
    }
ret0:
    return 0;
}
