#include "o03_types.h"
typedef struct Q2It { u8 pad0[0x10]; u8 alpha; u8 pad11[3]; u16 f14; u16 f16; s16 f18; } Q2It;
typedef struct Q2Lb {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 w1C;
    /* 0x20 */ Q2It *a;
    /* 0x24 */ s32 ta;
    /* 0x28 */ Q2It *b;
    /* 0x2C */ s32 tb;
    /* 0x30 */ s32 state;
    /* 0x34 */ s32 timer;
    /* 0x38 */ void *w38;
    /* 0x3C */ void *w3C;
    /* 0x40 */ void *w40;
    /* 0x44 */ void *w44;
    /* 0x48 */ void *w48;
    /* 0x4C */ void *w4C;
    /* 0x50 */ void *w50;
    /* 0x54 */ void *w54;
    /* 0x58 */ void *w58;
    /* 0x5C */ s32 w5C;
    /* 0x60 */ s32 w60;
    /* 0x64 */ s32 w64;
    /* 0x68 */ void *w68;
} Q2Lb;
typedef struct Q2Cfg { u8 pad0[0xD]; u8 f0D; u8 pad0E[2]; s32 f10; u8 pad14[7]; u8 f1B; u8 pad1C[0x148 - 0x1C]; struct { u8 f0; u8 pad[0x19]; u8 f19; } pl[8]; } Q2Cfg;
extern Q2Lb *D_800E4518;
extern s32 D_80146894;
extern s32 D_80154024;
extern char *D_800D749C[];
extern char *D_800D74A4[];
extern char *D_800D74A8[];
extern char *D_800D74B4[];
extern char *D_800D74B8[];
extern char *D_800D74BC[];
extern Q2Cfg D_801462C8[];
void *func_00252FFC(s32 n);
s32 func_0025E2E4(void);
void func_0025E2F4(s32 a);
void func_0025E3A4(void);
void func_0025E234(s32 a);
Q2It *func_0040ECB0(s32 p, u16 id);
void func_0040E958(void *it, s32 on);
void func_0040E9D0(void *it, s32 on);
s32 func_00419ED4(s32 a, s32 b);
void func_0041B190(s32 a);
void *func_0041AC40(s32 a, s32 b);
void func_0041ADB4(void *p, char *s);
void func_0041AD90(void *p, s32 a);
s32 func_00265370(void);
void *func_0041A600(s32 a, s32 b, s32 c);
void func_0041A76C(void *p, s32 a);
s32 func_0042B108(void);
void func_002A338C(void);
void func_0043C3F0(void *a, s32 b, s32 c, s32 d, s32 e);
void func_0043C458(void *a);
void func_00422218(void);
s32 func_00422728(s32 root) {
    Q2It *it, *ia, *ia2, *ib, *ib2;
    Q2Lb *d;
    s32 t, m, r;
    s32 i;
    Q2Cfg *c;
    void *h;
    D_800E4518 = func_00252FFC(0x6C);
    D_800E4518->w64 = func_0025E2E4();
    func_0025E2F4(0x34);
    func_0025E3A4();
    func_0025E234(-1);
    D_800E4518->state = 1;
    D_800E4518->timer = 4;
    ia = func_0040ECB0(root, 0x381);
    d = D_800E4518;
    d->a = ia;
    ia->f14 = ia->f14 - ia->f18;
    t = d->a->f18;
    if (t < 0) {
        t += 3;
    }
    t >>= 2;
    d->ta = t;
    ia2 = d->a;
    r = ia2->f18 - t * 4;
    ia2->f14 = ia2->f14 + r;
    ib = func_0040ECB0(root, 0x388);
    d = D_800E4518;
    d->b = ib;
    ib->f14 = ib->f14 + ib->f18;
    t = d->b->f18;
    if (t < 0) {
        t += 3;
    }
    t >>= 2;
    d->tb = t;
    ib2 = d->b;
    r = ib2->f18 - t * 4;
    ib2->f14 = ib2->f14 - r;
    D_800E4518->w38 = (void *)func_00419ED4(0x373, 0x6E);
    D_800E4518->w3C = func_0040ECB0(root, 0x372);
    func_0040E958(D_800E4518->w3C, 0);
    func_0040ECB0(root, 0x386)->alpha = 0x6E;
    D_800E4518->w40 = func_0040ECB0(root, 0x387);
    ((u8 *)D_800E4518->w40)[0x10] = 0x8C;
    D_800E4518->w44 = func_0040ECB0(root, 0x370);
    D_800E4518->w4C = func_0040ECB0(root, 0x384);
    func_0040E958(D_800E4518->w4C, 1);
    func_0040ECB0(root, 0x385)->alpha = 0x6E;
    D_800E4518->w48 = func_0040ECB0(root, 0x374);
    func_0040E958(D_800E4518->w48, 0);
    func_0041B190(0x377);
    func_0041B190(0x37C);
    D_800E4518->w54 = func_0041AC40(0x375, 0x376);
    func_0041ADB4(D_800E4518->w54, D_800D749C[0]);
    func_0041ADB4(D_800E4518->w54, D_800D74A4[0]);
    func_0041ADB4(D_800E4518->w54, D_800D74A8[0]);
    c = D_801462C8;
    func_0041AD90(D_800E4518->w54, c->f1B);
    D_800E4518->w58 = func_0041AC40(0x378, 0x379);
    func_0041ADB4(D_800E4518->w58, D_800D74B4[0]);
    if (func_00265370() != 0x400000) {
        func_0041ADB4(D_800E4518->w58, D_800D74B8[0]);
        func_0041ADB4(D_800E4518->w58, D_800D74BC[0]);
    }
    func_0041AD90(D_800E4518->w58, ((u8 *)c)[0x580]);
    D_800E4518->w50 = func_0041A600(0x37A, 0x37B, 0x80);
    func_0041A76C(D_800E4518->w50, c->f10);
    if (c->f0D == 0) {
        if (func_0042B108() == 0) {
            func_0040E9D0(func_0040ECB0(root, 0x37E), 1);
        }
        it = func_0040ECB0(root, 0x380);
        func_0040E9D0(it, 1);
        for (i = 0; i < 8; i++) {
            if (c->pl[i].f0 == 1 && ((u8 *)c)[0x161 + i * 0x96] == 0) {
                func_0040E9D0(it, 0);
                break;
            }
        }
    } else if (c->f0D >= 0 && c->f0D < 5) {
        func_0040E9D0(func_0040ECB0(root, 0x380), 1);
        func_0040E9D0(func_0040ECB0(root, 0x37E), 1);
    }
    func_0041B190(0x380);
    func_0041B190(0x37D);
    func_0041B190(0x37E);
    func_0041B190(0x37F);
    D_800E4518->w5C = 0;
    func_002A338C();
    func_0043C3F0(D_800E4518, 0x67, 0, 0, 0);
    func_0043C458(D_800E4518);
    m = -1;
    D_800E4518->w1C = 0;
    D_800E4518->w60 = m;
    func_0040E958((void *)root, 0);
    D_80146894 = 1;
    D_80154024 = 0;
    (&D_80154024)[-1] = m;
    func_00422218();
    D_800E4518->w68 = func_0040ECB0(root, 0x371);
    func_0040E958(D_800E4518->w68, 1);
    return 0;
}
