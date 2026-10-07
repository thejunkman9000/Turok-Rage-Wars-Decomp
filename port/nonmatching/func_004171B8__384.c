#include "o02_types.h"
typedef struct { u32 w0; u32 w1; } O02Gfx;
typedef struct { s32 f[5]; } O02Fl;
extern O02Gfx *D_80110634;
extern s32 D_800E32E4;
extern s32 D_800E32CC;
extern s32 D_800E32A0;
extern O02Fl D_80153F60;
void func_0041900C(void);
#define GFX(a, b) { O02Gfx *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
void func_004171B8(u32 m) {
    O02Fl fl;
    u32 hi, lo, sel, cmd;
    fl.f[0] = (m & 0x5) == 0x5;
    fl.f[1] = (m & 0x30) == 0x30;
    fl.f[2] = (m & 0x300) == 0x300;
    fl.f[3] = (m & 0x3000) == 0x3000;
    fl.f[4] = (m & 0x30000) == 0x30000;
    func_0041900C();
    D_800E32E4 = 0;
    D_800E32E4 = 1;
    GFX(0xE7000000, 0);
    if (fl.f[1]) {
        D_800E32CC = 0xC;
    } else {
        D_800E32CC = 0xB;
    }
    GFX(0xE3000A01, 0);
    GFX(0xD9D0F9FA, 0);
    GFX(0xD9FFFFFF, 0x200404);
    if (fl.f[4]) {
        GFX(0xD9FFFFFF, 1);
    }
    lo = 0;
    hi = 0;
    sel = lo < fl.f[3];
    if (fl.f[4]) sel += 2;
    switch (sel) {
    case 0:
        lo = 0x0C084000;
        hi = 0x03024000;
        cmd = 0xE200001C;
        break;
    case 1:
        lo = 0x404240;
        hi = 0x104240;
        cmd = 0xE200001C;
        break;
    case 2:
        lo = 0x442230;
        hi = 0x112230;
        cmd = 0xE200001C;
        break;
    case 3:
        lo = 0x404A50;
        hi = 0x104A50;
        cmd = 0xE200001C;
        break;
    default:
        cmd = 0xE200001C;
        break;
    }
    D_800E32A0 = 1;
    GFX(cmd, lo | hi);
    D_80153F60 = fl;
}
