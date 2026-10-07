#include "b24_types.h"

typedef struct ColB {
    u8 pad[3];
    u8 v;
} ColB;

typedef struct TxtGlob {
    u8 pad0[0xA0];
    ColB c[6];
    f32 f0;
    f32 f1;
} TxtGlob;

extern DlCmd *D_80110634;
extern TxtGlob D_8013B7B8[];
extern u32 D_8014D3D0;
extern s32 D_800E28D0;
f32 func_00442460(s32, f32, f32);
void func_002A98E0(s32, f32, f32, f32, f32, s32, s32, s32);

#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_002A9F18(s32 a0, s32 x, s32 y, s32 alpha, s32 doScale, s32 flagB, f32 sc1, f32 sc2) {
    TxtGlob *g = D_8013B7B8;
    f32 k1, k2, r, t, fx, fy, fw, fh;
    s32 mode;
    if (doScale != 0) {
        switch (D_8014D3D0) {
        case 0:
            k1 = 24.0f;
            break;
        case 1:
            k1 = 12.0f;
            break;
        case 2:
        case 6:
            k1 = 8.0f;
            break;
        case 3:
            k1 = 6.0f;
            break;
        case 4:
        case 5:
            k1 = 16.0f;
            break;
        default:
            k1 = 1.0f;
            break;
        }
        t = g->f0 * sc1 * k1;
        switch (D_8014D3D0) {
        case 0:
            k2 = 24.0f;
            break;
        case 1:
            k2 = 12.0f;
            break;
        case 2:
        case 6:
            k2 = 8.0f;
            break;
        case 3:
            k2 = 6.0f;
            break;
        case 4:
        case 5:
            k2 = 16.0f;
            break;
        default:
            k2 = 1.0f;
            break;
        }
        r = func_00442460(a0, t, k2);
        if ((f32)(D_800E28D0 - 0x2C) < r) {
            t = (f32)(D_800E28D0 - 0x2C) / r;
            sc1 = sc1 * t;
            r = r * t;
        }
        x -= (s32)(r * 0.5f);
    }
    fx = x;
    GFX(0xE7000000, 0)
    GFX(0xFB000000, SHIFTL(g->c[0].v, 24, 8) | SHIFTL(g->c[1].v, 16, 8) | SHIFTL(g->c[2].v, 8, 8) | SHIFTL(alpha, 0, 8))
    GFX(0xFA000000, SHIFTL(g->c[3].v, 24, 8) | SHIFTL(g->c[4].v, 16, 8) | SHIFTL(g->c[5].v, 8, 8) | SHIFTL(0xFF, 0, 8))
    fw = g->f0 * sc1;
    mode = D_8014D3D0;
    fy = y;
    fh = g->f1 * sc2;
    if (flagB != 0) {
        func_002A98E0(a0, fx, fy, fw, fh, 1, alpha, mode);
    }
    func_002A98E0(a0, fx, fy, fw, fh, 0, alpha, mode);
}
