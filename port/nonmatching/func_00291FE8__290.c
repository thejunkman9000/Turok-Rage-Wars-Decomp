#include "m05_types.h"

typedef struct M5Dl { u32 w0; u32 w1; } M5Dl;
typedef struct M5Gfx { u8 pad0[0x110]; u32 fb; } M5Gfx;

extern M5Dl *D_80110634;
extern M5Gfx *D_8011FE80;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern f32 D_800CA51C;
extern f32 D_800CA520;
extern f32 D_800CA524;
extern f32 D_800CA528;
extern f32 D_800CA52C;
extern f32 D_800CA530;
extern f32 D_800CA534;
extern s32 D_8013B878;
extern s32 D_8013B87C;

void func_00291BF8(s32, s32, s32, s32, s32, s32);
void func_002A94E8();
void func_002ABB2C(s32, s32, s32, s32, s32, s32);
void func_002ABB58(f32, f32);
void func_002A9F18(char *, s32, s32, s32, s32, s32, f32, f32);

#define DL(a, b) { M5Dl **pp = &D_80110634; M5Dl *q = (*pp)++; q->w0 = (a); q->w1 = (b); }

void func_00291FE8(s32 unused, s32 bg, char **names, s32 x, s32 y, s32 lineh, f32 sx, f32 sy) {
    M5Gfx *g = D_8011FE80;
    char **p;
    f32 s;

    y = (y * D_800E28D4) / 222;
    if (bg != 0) {
        func_00291BF8(0, 0, D_800E28D0, 0, D_800E28D4, 0);
        DL(0xED000000, (((s32)((f32)(D_800E28D0 - 1) * D_800CA51C) & 0xFFF) << 12) | ((s32)((f32)(D_800E28D4 - 1) * D_800CA51C) & 0xFFF));
        DL(((D_800E28D0 - 1) & 0xFFF) | 0xFF100000, g->fb);
        DL(0xE3000A01, 0x300000);
        DL(0xFCFFFFFF, 0xFFFE793C);
        DL(0xE200001C, 0);
        DL(0xF7000000, 0x10001);
        DL(((D_800E28D0 & 0x3FF) << 14) | (((D_800E28D4 & 0x3FF) * 4) | 0xF6000000), 0);
    }
    func_002A94E8();
    func_002ABB2C(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    sx = sx * (f32)D_800E28D0 * D_800CA520;
    sy = sy * (f32)D_800E28D4 * D_800CA524;
    s = D_800CA528;
    if (D_800E28D4 >= 0xDF) {
        s = D_800CA52C;
    }
    sx = sx * s;
    sy = sy * D_800CA530;
    func_002ABB58(sx, sy);
    D_8013B878 = 1;
    D_8013B87C = 1;
    if (*names != 0) {
        sx = D_800CA534;
        p = names;
        do {
            func_002A9F18(*p, x, y, 0xFF, 1, 1, sx, sx);
            p++;
            y = (s32)((f32)y + (f32)lineh * sy);
        } while (*p != 0);
    }
}
