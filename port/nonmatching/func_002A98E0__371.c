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
    s32 unkC0;
    s32 unkC4;
} TxtGlob;

extern DlCmd *D_80110634;
extern TxtGlob D_8013B7B8[];
extern u32 D_8014D3D0;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_8011FE88[];
extern u8 D_8013B880[];
extern u8 D_8013B980[];
s32 func_0028BE88(u8 *, s32, s32, s32);
f32 func_0044239C(s32, s32, f32, f32);
void func_002AB19C(s32, s32, s16, s16, f32, f32, s32);
void func_002536F4(s32, s32);

#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

#define SW(dst) \
    switch (D_8014D3D0) { \
    case 0: dst = 24.0f; break; \
    case 1: dst = 12.0f; break; \
    case 2: case 6: dst = 8.0f; break; \
    case 3: dst = 6.0f; break; \
    case 4: case 5: dst = 16.0f; break; \
    default: dst = 1.0f; break; \
    }

void func_002A98E0(u8 *str, f32 x, f32 y, f32 w, f32 h, s32 flag, s32 alpha, s32 mode) {
    TxtGlob *g = D_8013B7B8;
    s32 sfx = 0;
    s32 font;
    s32 hd;
    s32 c, gl, nx, ysh;
    f32 kA, kB, adv, sx, sy;
    s32 ys;

    GFX(0xE7000000, 0)
    if (flag != 0) {
        GFX(0xFB000000, SHIFTL(alpha, 0, 8))
        GFX(0xFA000000, 0xFF)
        x += (f32)(g->unkC0 * (D_800E28D0 / 284));
        y += (f32)(g->unkC4 * (D_800E28D4 / 222));
    } else {
        GFX(0xFB000000, SHIFTL(g->c[0].v, 24, 8) | SHIFTL(g->c[1].v, 16, 8) | SHIFTL(g->c[2].v, 8, 8) | SHIFTL(alpha, 0, 8))
        GFX(0xFA000000, SHIFTL(g->c[3].v, 24, 8) | SHIFTL(g->c[4].v, 16, 8) | SHIFTL(g->c[5].v, 8, 8) | SHIFTL(0xFF, 0, 8))
    }
    switch (mode) {
    default:
        font = 2;
        break;
    case 0:
        font = 2;
        break;
    case 1:
        font = 1;
        sfx = font;
        break;
    case 2:
    case 3:
        font = 6;
        break;
    case 4:
    case 5:
        font = 5;
        break;
    case 6:
        font = 7;
        break;
    }
    hd = func_0028BE88(D_8011FE88, font, 0x10, 1);
    if (hd != 0) {
        if (str != NULL) {
            c = *str;
            if (c != 0) {
                ysh = (s32)y << 16;
                for (;;) {
                    if (c == '\n') {
                        break;
                    }
                    nx = str[1];
                    switch (mode) {
                    default:
                    case 0:
                        gl = D_8013B980[c];
                        SW(kA)
                        SW(kB)
                        adv = func_0044239C(c, nx, kA, kB);
                        break;
                    case 1:
                        gl = D_8013B880[c];
                        SW(adv)
                        break;
                    case 2:
                        gl = D_8013B880[c];
                        SW(adv)
                        break;
                    case 3:
                        gl = D_8013B880[c];
                        SW(adv)
                        break;
                    case 4:
                        gl = c;
                        if (c == 0xFF) {
                            gl = 0xFF;
                        }
                        SW(adv)
                        break;
                    case 5:
                        gl = c;
                        if (c == 0xFF) {
                            gl = 0xFF;
                        }
                        SW(adv)
                        break;
                    case 6:
                        gl = c;
                        if (c == 0xFF) {
                            gl = 0xFF;
                        }
                        SW(adv)
                        break;
                    }
                    sx = w;
                    sy = h;
                    if (sfx != 0) {
                        if ((gl & 0xFF) == 0x25 || (gl & 0xFF) == 0x2B || (gl & 0xFF) == 0x3D) {
                            sx = (f32)D_800E28D0 * 0.0035211267f;
                            sy = (f32)D_800E28D4 * 0.0045045046f;
                        }
                    }
                    if ((gl & 0xFF) != 0xFF) {
                        func_002AB19C(hd, gl & 0xFF, (s32)x, ysh >> 16, sx, sy, 1);
                    }
                    x += adv * sx;
                    str++;
                    if (str == NULL) {
                        break;
                    }
                    c = *str;
                    if (c == 0) {
                        break;
                    }
                }
            }
        }
        func_002536F4(0, hd);
    }
}
