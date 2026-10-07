#include "o03_types.h"
extern O3Pg *D_800E3518;
extern s32 D_800E3510;
extern s32 D_800E3514;
extern s32 D_800E28CC;
extern s32 D_800D7700;
extern s32 D_8010F190;
extern s32 D_80146D60;
extern s32 D_8014AD94;
void func_0029A1D4(s32 a);
void func_0029A73C();
void func_00299368(s32 a);
void func_002A3358();
void func_002A1C08();
s32 func_00264634(s32 a);
void func_00404E28(s32 a);
s32 func_00404F04(s32 a);
s32 func_00404BE8(s32 a, s32 b, void *c);
s32 func_00435560(s32 a, u32 *b);
void func_00435190(s32 a);
void func_0040E958(s32 it, s32 on);
O3TxtItem *func_0040ECB0(s32 p, s32 id);
void func_0041C21C(void);
void func_0041C2C4();
void func_0041BF10(void) {
    s32 sp10[1];
    u32 sp14;
    s32 res;
    s32 ok;
    s32 bad;
    s32 r;
    O3TxtItem *it;
    s32 snd;
    func_0029A1D4(0x3C2);
    func_0040E958(D_800E3518->w2, 0);
    bad = 0;
    func_0040E958(D_800E3518->w3, bad);
    ok = 1;
    func_0040E958(D_800E3518->w4, bad);
    res = func_00264634(bad);
    if (res == 1) {
        func_0041C21C();
        if (D_800E3518->f1C == 1) {
            func_00404E28(D_800E3510);
            r = func_00404F04(D_800E3510);
            switch (r) {
            case 0:
                if (func_00404BE8(D_800D7700, D_800E3510, sp10) == 0 && func_00435560(D_800E3510, &sp14) == 0) {
                    ok = bad < sp14;
                }
                break;
            case -4:
            case -3:
            case -1:
                bad = 1;
                break;
            }
        }
    }
    if (res == 0) {
        D_800E3518->f18 = 1;
        D_800E3518->f14 = 0;
        func_0040E958(D_800E3518->w1, 0);
        func_0040E958(D_800E3518->w3, 1);
        goto done;
    }
    if (D_800E3518->f1C == 0) {
        D_800E3518->f18 = 2;
        D_800E3518->f14 = 0;
        func_0040E958(D_800E3518->w1, 0);
        func_0040E958(D_800E3518->w2, 1);
        snd = 0x3CB;
        goto play;
    }
    if (bad == 1 || (D_8010F190 & 0x1000)) {
        func_0029A73C();
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
        if (bad == 0) {
            D_800E3514 = 0;
        } else {
            D_800E3514 = 2;
        }
        func_00435190(6);
        func_00299368(0x13);
        return;
    }
    if (ok == 1) {
        func_0041C2C4();
        return;
    }
    it = func_0040ECB0(D_800E3518->parent, 0x3C8);
    func_002A1C08(D_800E3518->buf, "%d", D_800E3510 + 1);
    it->txt = D_800E3518->buf;
    D_800E3518->f18 = 3;
    D_800E3518->f14 = 0;
    func_0040E958(D_800E3518->w1, 0);
    func_0040E958(D_800E3518->w4, 1);
    snd = 0x3C6;
play:
    func_0029A1D4(snd);
done:
    func_002A3358();
}
