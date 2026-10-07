#include "m05_types.h"

extern f32 D_800C9B00;
extern f32 D_800C9B04;
extern f32 D_800C9B08;
extern f32 D_800C9B0C;
extern f32 D_800C9B10;
extern f32 D_800C9B14;

void func_00276620(s8 h, u8 p1, u8 p2, u8 p3, u8 *o1, u8 *o2, u8 *o3) {
    s32 w0, w1, w2;
    s32 t;
    s32 c0, c1, c2;
    u32 a, b, c;
    s32 m;
    f32 mx, f;

    if (h != 0) {
        if (h < 0) {
            t = h + 0x55;
        } else {
            t = 0x55 - h;
        }
        if (t < 0) {
            w0 = 0;
        } else {
            w0 = (s32)((f32)(t * 100) * D_800C9B00);
        }
        if (h < -0x55) {
            t = h + 0xAA;
        } else {
            t = -h;
        }
        if (t < 0) {
            w1 = 0;
        } else {
            w1 = (s32)((f32)(t * 100) * D_800C9B04);
        }
        if (h >= 0x56) {
            t = (0xAA - h) * 25;
            w2 = (s32)((f32)(t * 4) * D_800C9B08);
        } else if (h >= 0) {
            t = h * 25;
            w2 = (s32)((f32)(t * 4) * D_800C9B08);
        } else {
            w2 = 0;
        }
        a = p3 & 0xFF;
        b = p1 & 0xFF;
        c = p2 & 0xFF;
        c0 = w1 * a + w0 * b + w2 * c;
        c1 = w1 * b + w0 * c + w2 * a;
        c2 = w1 * c + w0 * a + w2 * b;
        if (a < c) {
            if ((s32)c < (s32)b) goto bb;
            mx = (a < c) ? (f32)c : (f32)a;
        } else {
            if ((s32)a < (s32)b) goto bb;
            mx = (a < c) ? (f32)c : (f32)a;
        }
        goto cc;
bb:
        mx = (f32)b;
cc:
        m = c2;
        if (c2 < c1) m = c1;
        if (m < c0) m = c0;
        f = (f32)m;
        if (f == 0.0f) {
            *o1 = p1;
            *o2 = p2;
            *o3 = p3;
            return;
        }
        *o1 = (u32)((f32)c0 * mx / f);
        *o2 = (u32)((f32)c1 * mx / f);
        *o3 = (u32)((f32)c2 * mx / f);
    } else {
        *o1 = p1;
        *o2 = p2;
        *o3 = p3;
    }
}
