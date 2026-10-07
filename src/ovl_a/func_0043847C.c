#include "o05_types.h"

typedef struct {
    u8 pad0[0x20];
    void *f20;
    u8 pad24[4];
    char buf28[10];
    char buf32[10];
    char buf3C[10];
    char buf46[0x94 - 0x46];
    s32 f94;
    s32 f98;
} O05M30;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    u8 pad[0x80 - 0xA];
    s8 b80;
    u8 pad81[150 - 0x81];
} O05R150c;
typedef struct { s32 f0; u8 pad[108]; } O05T112;
typedef struct { u8 pad[0x10]; u8 b10; u8 pad11[0x2C - 0x11]; void *f2C; u8 pad30[8]; void *f38; } O05Wd2;
extern O05M30 *D_800E5830;
extern O05R150c D_80146398[];
extern O05Rec D_80102B00[];
extern O05T112 D_800E3A58[];
extern s32 D_80103140[];
extern s32 D_80102AE0[];
extern s32 D_80154028;
extern s32 D_800E4200[];
O05Wd2 *func_0040ECB0(void *w, s32 id);
void func_0040E958(void *w, s32 a);
s32 func_0041F1B0(s32 a);
void *func_00424FC8(s32 a);
void func_002A1C08(char *buf, const char *fmt, s32 v);

void func_0043847C(void) {
    s32 sel = D_800E5830->f94;
    O05R150c *r = &D_80146398[sel];
    O05Wd2 *w;
    O05Wd2 *w6;
    s32 a;
    u8 col = 0xAF;
    char *fmt = "%d";
    w = func_0040ECB0(D_800E5830->f20, 0x279);
    func_0040E958(w, 1);
    w->b10 = 0x96;
    w->f2C = (void *)D_800E3A58[func_0041F1B0(r->b80)].f0;
    w = func_0040ECB0(D_800E5830->f20, 0x27A);
    func_0040E958(w, 1);
    w->b10 = col;
    w->f38 = &D_80102B00[sel];
    w = func_0040ECB0(D_800E5830->f20, 0x27B);
    func_0040E958(w, 1);
    w->b10 = 0x73;
    w->f38 = func_00424FC8(sel);
    w = func_0040ECB0(D_800E5830->f20, 0x27C);
    func_0040E958(w, 1);
    w->b10 = col;
    func_002A1C08(D_800E5830->buf28, fmt, r->h4);
    w->f38 = D_800E5830->buf28;
    w = func_0040ECB0(D_800E5830->f20, 0x27D);
    func_0040E958(w, 1);
    w->b10 = col;
    func_002A1C08(D_800E5830->buf32, fmt, r->h2 + r->h0);
    w->f38 = D_800E5830->buf32;
    w = func_0040ECB0(D_800E5830->f20, 0x27E);
    func_0040E958(w, 1);
    w->b10 = col;
    a = 0;
    if (D_80103140[sel] > 0) {
        a = D_80102AE0[sel] * 100 / D_80103140[sel];
    }
    func_002A1C08(D_800E5830->buf3C, "%d%%", a);
    w->f38 = D_800E5830->buf3C;
    w = func_0040ECB0(D_800E5830->f20, 0x27F);
    func_0040E958(w, 1);
    w->b10 = col;
    w6 = w;
    switch (D_80154028) {
    case 0:
        func_002A1C08(D_800E5830->buf46, fmt, r->h8);
        break;
    case 1:
        func_002A1C08(D_800E5830->buf46, fmt, r->h6);
        break;
    default:
        func_002A1C08(D_800E5830->buf46, "%d", 0);
        break;
    }
    w6->f38 = D_800E5830->buf46;
    if (D_800E5830->f98 != -1) {
        w = func_0040ECB0(D_800E5830->f20, 0x280);
        w->b10 = 0x96;
        func_0040E958(w, 1);
        w->f2C = D_800E4200[D_800E5830->f98];
    }
}
