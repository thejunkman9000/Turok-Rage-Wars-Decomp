#include "b04_types.h"
extern f32 D_800C735C, D_800C7360, D_800C7368, D_800C736C, D_800C7370, D_800C7374, D_800C7378, D_800C737C, D_800C7380, D_800C7384;
extern s32 D_800E28D0, D_800E28D4;
extern u8 D_800C7350[];
extern DlCmd *D_80110634;
extern u8 D_801462DE;
typedef struct { u8 pad0[0x29C]; f32 f29C, f2A0, f2A4, f2A8; } B04Cam;
typedef struct { u8 pad0[0x5DC]; B04Cam *cam; } B04Pc;
void func_002AB940(s32, s32, s32 *, s32 *);
void func_002ABC18(s32, s32, s32, s32, f32, f32, s32);
void func_002A94E8();
void func_002ABB58(f32, f32);
void func_002ABB2C(s32, s32, s32, s32, s32, s32);
void func_002A9F18(u8 *, s32, s32, s32, s32, s32, f32, f32);
#define RGBA(r, g, b, a) ((((r) & 0xFF) << 24) | (((g) & 0xFF) << 16) | (((b) & 0xFF) << 8) | ((a) & 0xFF))
void func_002185D0(B04Menu *o, B04Sel *sel, s32 n, B04Pc *p) {
    s32 sp20, sp24;
    f32 fs3, fv, fs0f, fs1, X, Y, alpha, k5;
    B04Cam *cam, *cam0;
    DlCmd *g;
    s32 t, r, gg, bl, k;
    cam0 = p->cam;
    t = D_801462DE + 0x40;
    fv = D_800C735C;
    if (t < 0x100)
        fv = (f32)t;
    fs3 = o->f8 * fv;
    for (k = n - 1; k != -1; k--, sel++) {
        k5 = D_800C7360;
        cam = p->cam;
        fs0f = cam->f29C * D_800C7368;
        fs1 = cam->f2A0 * D_800C736C;
        X = cam->f2A4 + cam->f29C * k5 + sel->v.x * k5 * cam->f29C;
        Y = cam->f2A8 + cam->f2A0 * k5 + sel->v.y * k5 * cam->f2A0;
        alpha = sel->f14;
        if (sel->id != 0) {
            func_002AB940(sel->id, 0, &sp20, &sp24);
            if (o->w37C == sel->idx) {
                r = (s32)(cosf(o->f14) * D_800C7370 + D_800C7374);
                gg = bl = r;
                alpha = D_800C7378;
            } else {
                r = 0x96;
                gg = r;
                bl = r;
                alpha = alpha * D_800C737C;
            }
            g = D_80110634++;
            g->w0 = 0xFB000000;
            g->w1 = RGBA(r, gg, bl, (u32)(alpha * fs3));
            func_002ABC18(sel->id, 0, (s16)(s32)(X - (f32)sp20 * sel->f18 * fs0f * k5),
                          (s16)(s32)(Y - (f32)sp24 * sel->f18 * fs1 * k5), fs0f * sel->f18, fs1 * sel->f18, 1);
        }
    }
    fs1 = cam0->f2A0 / (f32)D_800E28D4;
    fs0f = cam0->f29C / (f32)D_800E28D0;
    func_002A94E8();
    func_002ABB58(D_800C7380, D_800C7380);
    func_002ABB2C(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    X = cam0->f2A4 + cam0->f29C * D_800C7384;
    Y = cam0->f2A8 + cam0->f2A0 * D_800C7384;
    func_002A9F18(D_800C7350, (s32)X, (s32)Y, 0xC8, 1, 1, fs0f, fs1);
}
