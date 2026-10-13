#include "o05_types.h"

typedef struct { u8 pad0[0x20]; void *f20; u8 pad24[0x94 - 0x24]; s32 f94; s32 f98; } O05M5830;
typedef struct { u8 pad[0x10]; u8 b10; u8 pad11[0x2C - 0x11]; s32 f2C; u8 pad30[8]; s32 f38; } O05Wd;
typedef struct { s16 h0; s16 h2; s16 h4; s16 h6; s16 h8; u8 pad[0x80 - 0xA]; s8 b80; u8 pad81[0x96 - 0x81]; } O05Q;
typedef struct { s32 w0; u8 pad[0x70 - 4]; } O05T112;
typedef struct { u8 pad[0x190]; } O05Row;
extern O05M5830 *D_800E5830;
extern O05Q D_80146398[];
extern O05T112 D_800E3A58[];
extern O05Row D_80102B00[];
extern s32 D_80102AE0[];
extern s32 D_80103140[];
extern s32 D_800E4200[];
extern s32 D_80154028;
O05Wd *func_0040ECB0(void *p, s32 id);
void func_0040E958(void *w, s32 a);
s32 func_0041F1B0(s32 a);
s32 func_00424FC8(s32 a);
s32 func_002A1C08(char *buf, char *fmt, ...);

void func_auto_0043829C(void) {
    s32 idx = D_800E5830->f94;
    O05Q *q = &D_80146398[idx];
    O05Wd *w;
    O05Wd *w2;
    s32 a;
    s32 sel;
    s32 c = 0xAF;
    char *fmt;
    w = func_0040ECB0(D_800E5830->f20, 0x275);
    func_0040E958(w, 1);
    w->b10 = 0x96;
    w->f2C = D_800E3A58[func_0041F1B0(q->b80)].w0;
    w = func_0040ECB0(D_800E5830->f20, 0x276);
    func_0040E958(w, 1);
    w->b10 = c;
    w->f38 = (s32)&D_80102B00[idx];
    w = func_0040ECB0(D_800E5830->f20, 0x277);
    func_0040E958(w, 1);
    w->b10 = 0x73;
    w->f38 = func_00424FC8(idx);
    w = func_0040ECB0(D_800E5830->f20, 0x278);
    func_0040E958(w, 1);
    w->b10 = c;
    fmt = "%d";
    func_002A1C08((char *)D_800E5830 + 0x28, fmt, q->h4);
    w->f38 = (s32)((char *)D_800E5830 + 0x28);
    w = func_0040ECB0(D_800E5830->f20, 0x279);
    func_0040E958(w, 1);
    w->b10 = c;
    func_002A1C08((char *)D_800E5830 + 0x32, fmt, q->h2 + q->h0);
    w->f38 = (s32)((char *)D_800E5830 + 0x32);
    w = func_0040ECB0(D_800E5830->f20, 0x27A);
    func_0040E958(w, 1);
    w->b10 = c;
    a = 0;
    if (D_80103140[idx] > 0) {
        a = D_80102AE0[idx] * 100 / D_80103140[idx];
    }
    func_002A1C08((char *)D_800E5830 + 0x3C, "%d%%", a);
    w->f38 = (s32)((char *)D_800E5830 + 0x3C);
    w = func_0040ECB0(D_800E5830->f20, 0x27B);
    func_0040E958(w, 1);
    w->b10 = c;
    sel = D_80154028;
    w2 = w;
    switch (sel) {
    case 0:
        func_002A1C08((char *)D_800E5830 + 0x46, fmt, q->h8);
        break;
    case 1:
        func_002A1C08((char *)D_800E5830 + 0x46, fmt, q->h6);
        break;
    default:
        func_002A1C08((char *)D_800E5830 + 0x46, "%d", 0);
        break;
    }
    w2->f38 = (s32)((char *)D_800E5830 + 0x46);
    if (D_800E5830->f98 != -1) {
        w = func_0040ECB0(D_800E5830->f20, 0x27C);
        w->b10 = 0x96;
        func_0040E958(w, 1);
        w->f2C = D_800E4200[D_800E5830->f98];
    }
}
