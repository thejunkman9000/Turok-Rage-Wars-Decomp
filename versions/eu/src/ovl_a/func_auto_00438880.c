#include "q04_types.h"

typedef struct Q4W { u8 pad0[0x10]; u8 b10; u8 pad11[0x27]; void *f38; } Q4W;
typedef struct Q4M {
    u8 pad0[0x1C];
    s32 f1C;
    Q4W *f20;
    Q4W *f24;
    u8 pad28[0x50 - 0x28];
    char buf50[0x90 - 0x50];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    u8 padA0[0xAC - 0xA0];
    s32 fAC;
    u8 padB0[0x18C - 0xB0];
    char buf18C[0x1C0 - 0x18C];
    s32 f1C0;
    u8 pad1C4[4];
} Q4M;
typedef struct Q4Rec {
    u8 pad0[0xD];
    s8 bD;
    s8 bE;
    u8 bF;
    u8 pad10[7];
    u8 b17;
    u8 pad18[0x4A - 0x18];
    u8 b4A[0xA];
    u8 b54[0x2A];
    u8 b7E[0x94 - 0x7E];
    s32 f94[8];
    u8 padB4[0x125 - 0xB4];
    u8 b125[0x190 - 0x125];
} Q4Rec;
typedef struct Q4G {
    u8 pad0[0xD];
    u8 mode;
    u8 padE[0x581 - 0xE];
    u8 lang;
    u8 pad582[0x680 - 0x582];
    s32 f680;
} Q4G;
typedef struct { u8 pad[0x14]; f32 f14; u8 pad18[0xA8 - 0x18]; s32 fA8; } Q4S;
typedef struct Q4Rw { u8 pad0[0x78]; u8 b78; u8 pad79[0x96 - 0x79]; } Q4Rw;
typedef struct Q4Info { u8 pad[0x24]; u8 b24; } Q4Info;
extern Q4M *D_800E5830;
extern Q4Rec D_80102B00[];
extern Q4G D_801462C8[];
extern Q4Rw D_80146398[];
extern u8 D_80146418[];
extern u8 D_80102B54[];
extern s32 D_80146894[];
extern s32 D_80154028;
extern s32 D_8015402C;
extern s32 q4_g402C[] __asm__("D_8015402C");
extern u8 *D_800E4680;
extern s32 D_auto_800E2034[], D_auto_800E2044[], D_auto_800E2054[], D_auto_800E2074[], D_auto_800E2084[], D_auto_800E2094[], D_auto_800E20A4[], D_auto_800E20B4[];
extern u8 D_auto_80152789;
extern u8 D_8011FE88[];
extern s32 D_80102B94[];
typedef struct Q4Tb { s32 *f0; u8 pad[0x6C]; } Q4Tb;
extern Q4Tb D_800E3ABC[];
void *func_00252FFC(s32 n);
s32 func_00265670();
void func_002656A8();
void func_0028D35C(void *a, s32 b, void *c, s32 d);
void func_002A125C(void *dst, void *src);
s32 func_002A1494(void *s);
void func_002A1C08(void *dst, s32 fmt, s32 v);
void func_002A338C(void);
void func_0040E958(void *w, s32 a);
void func_0040E9D0(void *w, s32 a);
Q4W *func_0040ECB0(void *p, s32 id);
void func_0041B190(s32 a);
s32 func_0041F1B0(s32 a);
s32 func_004251F4(s32 a);
s32 func_auto_00425CBC(s32 a);
s32 func_00425854(s32 a);
void func_00425BC0(s32 a);
Q4Info *func_00425E50(s32 a, s32 b, s32 c);
void func_00425EF4(s32 a);
void func_0043847C(void);
void func_004387F4(void);
void func_00438C68(s32 a, s32 b);
void func_0043C3F0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0043C458(void *p);
void *memset(void *, s32, u32);

s32 func_auto_00438880(void *arg0) {
    s32 t5; u8 *t6;
    s32 i;
    s32 one;
    s32 id;
    s32 s0;
    s32 t;
    s32 r;
    Q4W *w;
    Q4W *w2;
    Q4S *s1;
    Q4Info *inf;
    Q4G *settings;
    char buf[0x40];
    D_800E5830 = func_00252FFC(0x1C8);
    D_800E5830->f20 = arg0;
    func_0040E958(arg0, 0);
    func_0043C3F0(D_800E5830, 0x67, 0, 0, 0);
    func_0043C458(D_800E5830);
    D_800E5830->f1C = 1;
    func_0040ECB0(arg0, 0x26F)->b10 = 0x6E;
    func_0040ECB0(arg0, 0x274)->b10 = 0x14;
    func_0040ECB0(arg0, 0x271)->b10 = 0x14;
    func_0040ECB0(arg0, 0x284)->b10 = 0x19;
    D_800E5830->f94 = 0;
    i = 0;
    one = 1;
    for (; i < 4; i++) {
        Q4Rw *e = &D_80146398[i];
        if (e->b78 == one) {
            D_800E5830->f94 = i;
            break;
        }
    }
    func_00438C68(i, one);
    D_800E5830->f98 = -1;
    switch (D_801462C8->mode) {
    case 1:
        if (D_801462C8->f680 == 1) {
            func_00425EF4(D_800E5830->f94);
            D_800E5830->f9C = -1;
            if (*D_800E4680 != 0 && func_00265670(&D_80102B00[D_800E5830->f94].b125[D_80102B00[D_800E5830->f94].bF * 5], D_8015402C, D_80102B00[D_800E5830->f94].bF) == 1) {
                w = func_0040ECB0(D_800E5830->f20, 0x282);
                func_0040E958(w, 1);
                w->b10 = 0xAF;
                w->f38 = (void *)D_auto_800E2054[D_801462C8->lang];
            } else {
                D_800E5830->fAC = func_auto_00425CBC(D_800E5830->f9C = func_004251F4(D_800E5830->f94));
            }
            D_800E5830->f98 = -1;
            switch (D_8015402C) {
            case 4: id = 0x2D; break;
            case 9: id = 0x2E; break;
            case 0x16: id = 0x2F; break;
            case 0x23: id = 0x30; break;
            default: id = -1; break;
            }
            if (id != -1 && func_00265670(D_80102B00[D_800E5830->f94].b4A, id) == 0) {
                func_002656A8(D_80102B00[D_800E5830->f94].b4A, id, 1);
                D_800E5830->f98 = id;
                func_00425BC0(D_800E5830->f94);
            }
            if (D_80102B00[D_800E5830->f94].b17 >= 0x12) {
                func_002656A8(D_80102B00[D_800E5830->f94].b7E - 1, 1, 1);
            }
            if (D_80102B00[D_800E5830->f94].b17 >= 0x24) {
                func_002656A8(D_80102B00[D_800E5830->f94].b7E - 1, 2, 1);
            }
            if (D_8015402C >= 0x23) {
                 t5 = (s8)D_80146418[D_800E5830->f94 * 150]; func_002656A8((u8 *)D_80102B54 + D_800E5830->f94 * 400, t5, 1);
                
                memset((u8 *)(D_80102B54 + 0x2A) + D_800E5830->f94 * 400, 0, 5);
                r = func_00425854(D_800E5830->f94);
                settings = D_801462C8;
                __asm__ volatile ("" : : "r"(settings));
                if (r >= 0) {
                    t = func_0041F1B0(r);
                    func_002A1C08(D_800E5830->buf18C, D_auto_800E2034[settings->lang], D_800E3ABC[t].f0[settings->lang]);
                    w = func_0040ECB0(D_800E5830->f20, 0x283);
                    w->b10 = 0xAF;
                    func_0040E958(w, 1);
                    w->f38 = D_800E5830->buf18C;
                }
            }
        } else {
            func_002A125C(D_800E5830->buf18C, (void *)D_auto_800E2044[D_801462C8->lang]);
            w = func_0040ECB0(D_800E5830->f20, 0x283);
            w->b10 = 0xAF;
            func_0040E958(w, 1);
            w->f38 = D_800E5830->buf18C;
        }
        break;
    case 3:
        s1 = (Q4S *)((u8 *)D_801462C8 + 0x5D8);
        if (s1->fA8 == 1) {
            func_00425EF4(D_800E5830->f94);
            inf = func_00425E50(q4_g402C[0], 3, 0);
            t = (s32)(s1->f14 * 0.06666667f);
            if (D_80102B00[D_800E5830->f94].f94[q4_g402C[0]] == 0) {
                D_80102B00[D_800E5830->f94].f94[q4_g402C[0]] = inf->b24 - t;
            } else {
                s0 = inf->b24 - t;
                if (s0 < D_80102B00[D_800E5830->f94].f94[q4_g402C[0]]) {
                    D_80102B00[D_800E5830->f94].f94[q4_g402C[0]] = s0;
                }
            }
            if (q4_g402C[0] == 0x23) {
                w = func_0040ECB0(D_800E5830->f20, 0x283);
                w->b10 = 0xAF;
                func_0040E958(w, 1);
                w->f38 = (void *)D_auto_800E20B4[D_auto_80152789];
            }
        } else {
            func_002A125C(D_800E5830->buf18C, (void *)D_auto_800E2044[D_801462C8->lang]);
            w = func_0040ECB0(D_800E5830->f20, 0x283);
            w->b10 = 0xAF;
            func_0040E958(w, 1);
            w->f38 = D_800E5830->buf18C;
        }
        break;
    case 4:
        if (D_801462C8->f680 == 1) {
            func_00425EF4(D_800E5830->f94);
            if (D_8015402C == 0x23) {
                w = func_0040ECB0(D_800E5830->f20, 0x283);
                w->b10 = 0xAF;
                func_0040E958(w, 1);
                w->f38 = (void *)D_auto_800E20A4[D_801462C8->lang];
            }
        } else {
            func_002A125C(D_800E5830->buf18C, (void *)D_auto_800E2044[D_801462C8->lang]);
            w = func_0040ECB0(D_800E5830->f20, 0x283);
            w->b10 = 0xAF;
            func_0040E958(w, 1);
            w->f38 = D_800E5830->buf18C;
        }
        break;
    }
    func_0043847C();
    func_004387F4();
    func_0041B190(0x272);
    func_0041B190(0x273);
    func_0041B190(0x277);
    func_0040E9D0(func_0040ECB0(arg0, 0x273), 1);
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].bD >= 0) {
            if (D_80102B00[i].bE == 0) {
                func_0040E9D0(func_0040ECB0(arg0, 0x273), 0);
                break;
            }
        }
    }
    func_0040ECB0(D_800E5830->f20, 0x275)->f38 = (void *)D_auto_800E2074[D_801462C8->lang];
    w = func_0040ECB0(D_800E5830->f20, 0x276);
    switch (D_80154028) {
    case 0:
        w->f38 = (void *)D_auto_800E2094[D_801462C8->lang];
        break;
    case 1:
        w->f38 = (void *)D_auto_800E2084[D_801462C8->lang];
        break;
    default:
        w->f38 = (void *)D_auto_800E2084[D_auto_80152789];
        break;
    }
    w = func_0040ECB0(arg0, 0x270);
    func_0028D35C(D_8011FE88, D_8015402C, buf, 0x3F);
    func_002A125C(D_800E5830->buf50, (void *)func_002A1494(buf));
    w->f38 = D_800E5830->buf50;
    D_800E5830->f24 = func_0040ECB0(arg0, 0x278);
    D_800E5830->f1C0 = 1;
    D_80146894[0] = 1;
    D_800E5830->f90 = 0;
    func_002A338C();
    return 0;
}
