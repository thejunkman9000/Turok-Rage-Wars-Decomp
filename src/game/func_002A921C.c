#include "b24_types.h"

extern u8 D_8011FE88[];
s32 func_0028BE88(u8 *, s32, s32, s32);
void func_002AB19C(s32, s32, s16, s16, f32, f32, s32);
void func_002ABC18(s32, s32, s16, s16, f32, f32, s32);
void func_002536F4(s32, s32);

void func_002A921C(s32 n, f32 x, f32 y, f32 sx, f32 sy, s32 flt, s32 rev, s32 mindig) {
    s32 h;
    s32 neg;
    s32 d3, d2, d1, d0;
    s32 r1, r2;
    s32 top;
    s32 i, v, d;
    f32 wf, w;

    h = func_0028BE88(D_8011FE88, 4, 0x10, 1);
    if (h != 0) {
        neg = 0;
        if (n < 0) {
            n = -n;
            neg = 1;
        }
        if (n >= 0) {
            d3 = (s32)((f32)n * 0.001f);
            r1 = n - d3 * 1000;
            d2 = (s32)((f32)r1 * 0.01f);
            r2 = r1 - d2 * 100;
            d1 = (s32)((f32)r2 * 0.1f);
            d0 = r2 - d1 * 10;
            top = 3;
            if (d3 == 0) {
                top = 2;
                if (d2 == 0) {
                    top = d1 != 0;
                }
            }
            if (top < mindig - 1) {
                top = mindig - 1;
            }
            if (neg != 0) {
                func_002ABC18(4, 10, (s32)x, (s32)y, sx, sy, flt);
                x += sx * 13.0f;
            }
            for (i = top; i >= 0; i--) {
                v = i;
                if (rev != 0) {
                    v = top - i;
                }
                switch (v) {
                case 3:
                    d = d3;
                    break;
                case 2:
                    d = d2;
                    break;
                case 1:
                    d = d1;
                    break;
                case 0:
                default:
                    d = d0;
                    break;
                }
                wf = 1.0f;
                if (d == 1) {
                    wf = 0.7f;
                }
                w = wf * (sx * 13.0f);
                if (rev != 0) {
                    x -= w;
                }
                if ((u32)d < 10) {
                    func_002AB19C(h, d, (s32)x, (s32)y, sx, sy, flt);
                }
                if (rev == 0) {
                    x += w;
                }
            }
        }
        func_002536F4(0, h);
    }
}
