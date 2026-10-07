#include "b04_types.h"
extern f32 D_800C72F0, D_800C72F4, D_800C72FC, D_800C7300, D_800C7304, D_800C7308, D_800C730C;
extern DlCmd *D_80110634;
extern u8 D_801462DE;
typedef struct { u8 pad0[0x29C]; f32 f29C, f2A0, f2A4, f2A8; } B04Cam;
typedef struct { u8 pad0[0x5DC]; B04Cam *cam; } B04Pc;
typedef struct { u8 pad0[8]; f32 f8; u8 padC[0x10]; f32 f1C; } B04MenuX;
s32 func_0022EAFC(B04Pc *, s32);
void func_002AB940(s32, s32, s32 *, s32 *);
void func_002ABC18(s32, s32, s32, s32, f32, f32, s32);
#define RGBA(r, g, b, a) ((((r) & 0xFF) << 24) | (((g) & 0xFF) << 16) | (((b) & 0xFF) << 8) | ((a) & 0xFF))
void func_00217630(B04Menu *o, B04Draw *sel, s32 n, B04Pc *p) {
    s32 sp20, sp24;
    f32 fs3, fv, fs1, fs1f, X, Y, alpha;
    f32 k4;
    B04Cam *cam;
    DlCmd *g;
    s32 t, col, k, r, gg, bl;
    t = D_801462DE + 0x40;
    fv = D_800C72F0;
    if (t < 0x100)
        fv = (f32)t;
    fs3 = o->f8 * fv;
    for (k = n - 1; k != -1; k--, sel++) {
        k4 = D_800C72F4;
        cam = p->cam;
        fs1 = cam->f29C * D_800C72FC;
        fs1f = cam->f2A0 * D_800C7300;
        X = cam->f2A4 + cam->f29C * k4 + sel->v.x * k4 * cam->f29C;
        Y = cam->f2A8 + cam->f2A0 * k4 + sel->v.y * k4 * cam->f2A0;
        alpha = sel->f18;
        if (sel->u14 != 0) {
            func_002AB940(sel->u14, 0, &sp20, &sp24);
            if (o->w37C == sel->i) {
                alpha = D_800C730C;
                r = (s32)(cosf(o->f14) * D_800C7304 + D_800C7308);
                gg = bl = r;
            } else {
                r = 200;
                if (func_0022EAFC(p, sel->idx) == 0)
                    r = 100;
                gg = r;
                bl = r;
            }
            g = D_80110634++;
            g->w0 = 0xFB000000;
            g->w1 = RGBA(r, gg, bl, (u32)(alpha * fs3));
            func_002ABC18(sel->u14, 0, (s16)(s32)(X - (f32)sp20 * sel->f1C * fs1 * k4),
                          (s16)(s32)(Y - (f32)sp24 * sel->f1C * fs1f * k4), fs1 * sel->f1C, fs1f * sel->f1C, 1);
        }
    }
}
