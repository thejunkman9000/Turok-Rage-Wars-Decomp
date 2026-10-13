#include "q03_types.h"
extern Q03Lob *D_800E54A4;
extern u32 D_800E54A0;
extern O05GameState D_801462C8[];
extern s32 D_800E3510;
extern s32 D_800E3514;
extern O05Rec D_80102B00[];
void *func_00252FFC(s32 size);
void func_0043C3F0(void *p, s32 a, s32 b, s32 c, s32 d);
void *func_0041B690(void *a, s32 b);
void func_0041B768(void *a, s32 b, s32 c);
Q03WdU *func_0040ECB0(void *a, s32 b);
void func_0040E958(void *w, s32 a);
void *func_00419ED4(s32 a, s32 b);
void func_00433DA8(s32 a);
void func_00432488(s32 a);
void func_00264790(s32 a);
void func_0022EF20(void *p);
void *memset(void *p, s32 c, u32 n);
void func_00404E28();
s32 func_00404F04();
void func_0040C4A8(s32 a);
void func_002A338C(void);
void func_002A3410(s32 a);
void func_0025DF54(s32 a);
s32 func_auto_0042EF50(void *arg0) {
    s32 i;
    s32 j;
    s32 m;
    s32 m2;
    s32 id;
    Q03WdU *w;
    Q03WdU *t;
    D_800E54A4 = func_00252FFC(0x3474);
    D_800E54A4->h.f0 = arg0;
    func_0043C3F0(&D_800E54A4->h.blk8, 0x67, 0, 0, 0);
    D_800E54A4->h.f4 = func_0041B690(arg0, 4);
    func_0041B768(arg0, 0, 0x281);
    func_0041B768(arg0, 1, 0x281);
    func_0041B768(arg0, 2, 0x281);
    func_0041B768(arg0, 3, 0x281);
    for (i = 3; i >= 0; i--) {
        D_800E54A4->h.w2C[i] = 0;
    }
    D_800E54A4->h.f4C = 1;
    i = 4;
    D_800E54A4->h.f50 = i;
    D_800E54A4->h.f3C = (Q03WdS *)func_0040ECB0(arg0, 0x29E);
    D_800E54A4->h.f3C->u14 = D_800E54A4->h.f3C->u14 - D_800E54A4->h.f3C->w18.u;
    D_800E54A4->h.f40 = D_800E54A4->h.f3C->w18.s / 4;
    m = D_800E54A4->h.f3C->w18.s - D_800E54A4->h.f40 * 4;
    { s32 r = m; D_800E54A4->h.f3C->u14 = D_800E54A4->h.f3C->u14 + r; }
    D_800E54A4->h.f44 = (Q03WdS *)func_0040ECB0(arg0, 0x2F7);
    D_800E54A4->h.f44->u14 = D_800E54A4->h.f44->u14 + D_800E54A4->h.f44->w18.u;
    D_800E54A4->h.f48 = D_800E54A4->h.f44->w18.s / 4;
    m = D_800E54A4->h.f44->w18.s - D_800E54A4->h.f48 * 4;
    { s32 r = m; D_800E54A4->h.f44->u14 = D_800E54A4->h.f44->u14 - r; }
    func_0040ECB0(arg0, 0x282)->b10 = 0x6E;
    D_800E54A4->h.f24 = func_00419ED4(0x283, 0xFF);
    t = func_0040ECB0(arg0, 0x283);
    D_800E54A4->h.f28 = t;
    func_0040E958(t, 0);
    D_800E54A4->plr[0].f10 = func_0040ECB0(arg0, 0x29F);
    D_800E54A4->plr[1].f10 = func_0040ECB0(arg0, 0x2F8);
    D_800E54A4->plr[2].f10 = func_0040ECB0(arg0, 0x2F6);
    D_800E54A4->plr[3].f10 = func_0040ECB0(arg0, 0x2F9);
    D_800E54A4->h.f54 = D_800E54A0;
    for (i = 0; i < 4; i++) {
        D_800E54A4->slot[i].a = -1;
        D_800E54A4->slot[i].b = 0;
        D_800E54A4->slot[i].c = 2;
    }
    switch (D_800E54A4->h.f54) {
    case 7:
        break;
    case 5:
        w = func_0040ECB0(arg0, 0x289);
        func_0040E958(w, 1);
        w->b10 = 0xFF;
        i = 0;
        break;
    case 6:
        w = func_0040ECB0(arg0, 0x287);
        func_0040E958(w, 1);
        w->b10 = 0xFF;
        i = 0;
        break;
    case 4:
        w = func_0040ECB0(arg0, 0x284);
        func_0040E958(w, 1);
        w->b10 = 0xFF;
        i = 0;
        break;
    case 0:
        w = func_0040ECB0(arg0, 0x288);
        func_0040E958(w, 1);
        w->b10 = 0xFF;
        i = 0;
        break;
    case 3:
        w = func_0040ECB0(arg0, 0x285);
        func_0040E958(w, 1);
        w->b10 = 0xFF;
        i = 0;
        break;
    case 1:
        w = func_0040ECB0(arg0, 0x28A);
        func_0040E958(w, 1);
        w->b10 = 0xFF;
        for (i = 0; i < 4; i++) {
            if (D_80102B00[i].bD >= 0) {
                if (D_80102B00[i].bE == 1) {
                    D_80102B00[i].bD = -1;
                    D_80102B00[i].bE = 0;
                }
                if (D_80102B00[i].bD >= 0) {
                    D_800E54A4->slot[i].a = 0;
                    D_800E54A4->slot[i].b = i;
                    D_800E54A4->slot[i].c = 1;
                }
            }
        }
        func_00433DA8(-1);
        i = 0;
        break;
    case 2:
        w = func_0040ECB0(arg0, 0x294);
        func_0040E958(w, 1);
        w->b10 = 0xFF;
        i = 0;
        break;
    default:
        i = 0;
        break;
    }
    for (i = 0; i < 4; i++) {
        D_800E54A4->plr[i].state = 0;
        D_800E54A4->plr[i].fC = 0;
        D_800E54A4->plr[i].f14 = -1;
        func_00432488(i);
        func_00264790(i);
        for (j = 0; j < 4; j++) {
            func_0022EF20(&D_800E54A4->plr[i].rec[j]);
        }
        for (j = 0; j < 16; j++) {
            memset(&D_800E54A4->plr[i].items[j].b[0x28], 0, 0x14);
            memset(&D_800E54A4->plr[i].items[j].b[0x3C], 0, 0xA);
        }
        memset(&D_800E54A4->plr[i].padAB8[0x14], 0, 0xA);
        memset(&D_800E54A4->plr[i].padAB8[0xA], 0, 0xA);
        memset(&D_800E54A4->plr[i].padAB8[0], 0, 0xA);
        D_800E54A4->plr[i].scroll = 0;
        D_800E54A4->plr[i].fAEC = 0;
        for (j = 0; j < 4; j++) {
            D_800E54A4->plr[i].tabAF0[j] = 2;
            D_800E54A4->plr[i].wdB00[j] = 0;
        }
        { u8 *P = (u8 *)D_800E54A4 + i * 0xB68;
        *(s32 *)(P + 0xB84) = 0;
        *(s32 *)(P + 0xB88) = 0;
        *(s32 *)(P + 0xBBC) = 0;
        *(s32 *)(P + 0x5C) = 0;
        *(s32 *)(P + 0x60) = -1;
        *(s32 *)(P + 0xB80) = -1; }
    }
    D_800E54A4->f3470 = -1;
    switch (D_800E54A4->h.f54) {
    case 5:
        id = 14;
        for (i = 3; i >= 0; i--) {
            D_800E54A4->plr[i].state = id;
        }
        for (i = 0; i < 4; i++) {
            if (D_80102B00[i].bE == 0) {
                if (D_80102B00[i].bD >= 0 && ((O05GameState *)D_801462C8)->rec[i].b0 == 1 && ((O05GameState *)D_801462C8)->rec[i].b19 == 0) {
                    D_800E54A4->plr[D_80102B00[i].bD].f14 = 2;
                    D_800E54A4->plr[D_80102B00[i].bD].state = 2;
                    D_800E54A4->plr[D_80102B00[i].bD].f8 = 6;
                }
            }
        }
        i = 0;
        do {
            func_00432488(i);
            i++;
        } while (i < 4);
        break;
    case 6:
        if (D_800E3514 == 0) {
            for (i = 0; i < 4; i++) {
                func_00404E28(i);
                m2 = func_00404F04(i);
                if (m2 >= -4 && (m2 < -2 || (m2 <= 0 ? m2 >= -1 : 0))) {
                    D_800E54A4->plr[i].f14 = 2;
                    D_800E54A4->plr[i].state = 2;
                    D_800E54A4->plr[i].f8 = 4;
                    func_00432488(i);
                }
            }
        } else {
            func_00404E28(D_800E3510);
            m2 = func_00404F04(D_800E3510);
            if (m2 >= -4 && (m2 < -2 || (m2 <= 0 ? m2 >= -1 : 0))) {
                D_800E54A4->plr[D_800E3510].f14 = 2;
                D_800E54A4->plr[D_800E3510].state = 2;
                D_800E54A4->plr[D_800E3510].f8 = 4;
                func_00432488(D_800E3510);
            }
        }
        break;
    case 7:
        D_800E54A4->plr[0].f14 = 2;
        D_800E54A4->plr[0].state = 2;
        D_800E54A4->plr[0].f8 = 0xD;
        D_800E54A4->plr[0].f4 = 6;
        func_00432488(0);
        break;
    }
    func_0040C4A8(0);
    func_002A338C();
    func_002A3410(0);
    func_0025DF54(0xE78);
    return 0;
}
