#include "o03_types.h"
extern s32 D_800E32B0;
extern s32 D_800E32BC;
extern u32 D_800E32DC;
extern s32 D_800E32E0;
extern s32 D_80153F60;
extern s32 q2_pad[] __asm__("D_80153F68");
extern f32 D_800E1430;
void func_004170B4(s32 a);
void func_00416D74(s32 a);
void func_00416F4C(s32 a);
void func_00415D10(f32 a, f32 b, f32 c, f32 d, u32 e, u32 f, u32 g, u32 h);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_004192F8(s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h);
void func_00418224(s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h);
static inline void Q2_SetColor(u32 color) {
    if (color != D_800E32DC) {
        D_800E32DC = color;
        O3_PUSH(0xFB000000, ((color >> 16) << 24) | ((color & 0xFF00) << 8) | ((color & 0xFF) << 8));
        O3_PUSH(0xFA000000, ((color >> 16) << 24) | ((color & 0xFF00) << 8) | ((color & 0xFF) << 8) | (color >> 24));
    }
}
void func_00417BA0(f32 x, f32 y, s32 unused, f32 w, f32 h, f32 u0, f32 v0, f32 u1, f32 v1, u32 color) {
    s32 x0, y0, x1, y1;
    s32 cl, ct, cr, cb;
    f32 t;
    s32 *pad = q2_pad;
    if (pad[0] == 0 || pad[-1] == 0) {
        D_800E32E0 = 0;
        D_800E32E4 = 0;
        func_004170B4(0xC);
        func_00416D74(5);
        O3_SetModeA(7);
        O3_SetModeB(0xE);
        if (D_80153F60 == 0) {
            func_00416F4C(9);
            func_00415D10(x, y, w, h, color, color, color, color);
        }
    } else if (pad[-2] == 0) {
        D_800E32E4 = 0;
        func_004170B4(0xC);
        O3_SetModeB(0xD);
        Q2_SetColor(color);
        O3_SetModeA(7);
        func_00416D74(D_800E32BC != 0 ? 1 : 2);
        x0 = (s32)x;
        y0 = (s32)y;
        D_800E32E0 = 0x13;
        x1 = (s32)((x + w) - D_800E1430);
        y1 = (s32)((y + h) - D_800E1430);
        if (x1 < x0) {
            t = (f32)x0;
            x0 = x1;
            x1 = (s32)t;
            t = u0;
            u0 = u1;
            u1 = t;
            w = -w;
        }
        if (y1 < y0) {
            t = (f32)y0;
            y0 = y1;
            y1 = (s32)t;
            t = v0;
            v0 = v1;
            v1 = t;
            h = -h;
        }
        func_002A2898(&cl, &ct, &cr, &cb);
        if (cr < x1 || x0 < cl || cb < y1 || y0 < ct) {
            if (cr >= x0 && cb >= y0 && x1 >= cl && y1 >= ct) {
                if (y0 < ct) {
                    f32 rt0 = (f32)(ct - y0) / h;
                    f32 t0 = rt0 * (v1 - v0);
                    __asm__("" : : "f"(rt0));
                    y0 = ct;
                    h = (f32)((y1 - y0) + 1);
                    v0 += t0;
                }
                if (cb < y1) {
                    f32 rt1 = (f32)(cb - y0) / h;
                    f32 t1 = rt1 * (v1 - v0);
                    __asm__("" : : "f"(rt1));
                    y1 = cb;
                    
                    v1 = v0 + t1;
                }
                if (x0 < cl) {
                    f32 rt2 = (f32)(cl - x0) / w;
                    f32 t2 = rt2 * (u1 - u0);
                    __asm__("" : : "f"(rt2));
                    x0 = cl;
                    w = (f32)((x1 - x0) + 1);
                    u0 += t2;
                }
                if (cr < x1) {
                    f32 rt3 = (f32)(cr - x0) / w;
                    f32 t3 = rt3 * (u1 - u0);
                    __asm__("" : : "f"(rt3));
                    x1 = cr;
                    
                    u1 = u0 + t3;
                }
                goto draw;
            }
        } else {
draw:
            if (u1 < u0 || v1 < v0 || D_800E32B0 != 0) {
                func_00418224(x0, y0, x1, y1, u0, v0, u1, v1);
            } else {
                func_004192F8(x0, y0, x1, y1, u0, v0, u1, v1);
            }
        }
    }
}

