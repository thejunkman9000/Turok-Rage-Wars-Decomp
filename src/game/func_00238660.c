#include "r03_types.h"

typedef struct R3Fx {
    u8 pad0[0x120];
    s32 unk120;
} R3Fx;

extern R3DlCmd *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
f32 r3_sqrtf(f32 x) __asm__("sqrtf");
void func_002ABC18(s32 a0, s32 a1, s16 a2, s16 a3, f32 a4, f32 a5, s32 a6);

void func_00238660(R3Fx *o, f32 px, f32 py, f32 alpha, s32 flag) {
    f32 sizes[7] = { 16.0f, 16.0f, 24.0f, 32.0f, 16.0f, 32.0f, 48.0f };
    s32 lens[7] = { 24, 24, 24, 24, 24, 24, 24 };
    s32 col[21] = {
        255, 150, 150, 255, 255, 150, 150, 255, 150, 150, 255, 255,
        150, 150, 255, 200, 150, 255, 255, 150, 255
    };
    f32 dx, dy, dist, dirx, diry, t, size, r, adx, fa, v;
    R3DlCmd *d;
    u32 x;
    register u32 y __asm__("$2");
    u32 cv;
    s32 i;
    register s32 a0v __asm__("$4");
    register s32 a1v __asm__("$5");

    if (alpha != 0.0f && o->unk120 == 0) {
        dx = (f32)(D_800E28D0 / 2) - px;
        dy = (f32)(D_800E28D4 / 2) - py;
        {
            R3DlCmd *d = D_80110634++;
            d->w0 = 0xE3001201;
            d->w1 = 0x2000;
        }
        dist = r3_sqrtf(dx * dx + dy * dy);
        if (flag == 0) {
            t = dist / r3_sqrtf((f32)(D_800E28D0 * D_800E28D0) * 0.25f + (f32)(D_800E28D4 * D_800E28D4) * 0.25f);
            if (1.0f < t) {
                alpha = 0.0f;
            } else {
                alpha = alpha * (1.0f - t);
            }
        }
        dist = dist * 0.4f;
        if (dx < 0.0f) adx = -dx; else adx = dx;
        if (dy < 0.0f ? (-dy < adx) : (dy < adx)) {
            dirx = -1.0f;
            if (0.0f < dx) dirx = 1.0f;
            diry = (dx < 0.0f) ? dy / -dx : dy / dx;
        } else {
            dirx = (dy < 0.0f) ? dx / -dy : dx / dy;
            diry = -1.0f;
            if (0.0f < dy) diry = 1.0f;
        }
        i = 0;
        if (flag) {
            f32 a, b, c, e, m, m2;
            register f32 kk __asm__("$f3");
            kk = 35.2f;
            a = (f32)D_800E28D4 + kk;
            b = (f32)D_800E28D0 + kk;
            c = px + kk;
            e = py + kk;
            m = a - py;
            if (!(m <= b - px)) m = b - px;
            if (!(m <= e)) m = e;
            if (!(m <= c)) m = c;
            if (!(m <= kk)) m = kk;
            if (m < 0.0f) {
                alpha = 0.0f;
            } else {
                m2 = a - py;
                if (!(m2 <= b - px)) m2 = b - px;
                if (!(m2 <= e)) m2 = e;
                if (!(m2 <= c)) m2 = c;
                if (!(m2 <= kk)) m2 = kk;
                alpha = alpha * (m2 / kk);
                __asm__ ("" : : "f"(kk));
            }
            if (!(1.0f < alpha)) {
                fa = 0.0f;
                if (!(alpha < 0.0f)) {
                    goto L80;
                }
            } else {
            L80:
                fa = alpha;
                if (1.0f < fa) fa = 1.0f;
            }
            alpha = fa;
            i = 0;
        }
        i = 0;
        do {
            px += dirx * dist;
            py += diry * dist;
            if (flag != 0 && i == 0) {
                size = 2.0f;
            } else {
                size = sizes[i] * 0.03125f;
            }
            t = size * 0.55f;
            r = t * 16.0f;
            if (-r < px && px < (f32)D_800E28D0 + r && -r < py && py < (f32)D_800E28D4 + r) {
                if (flag && i == 0) {
                    d = D_80110634++;
                    v = alpha * 255.0f;
                    d->w0 = 0xFB000000;
                    x = (u32)v;
                    __asm__ ("" : "=r"(a0v) : "0"(0x258));
                    __asm__ ("" : "=r"(a1v) : "0"(0));
                    y = -0x100;
                    d->w1 = x | y;
                    func_002ABC18(a0v, a1v, (s16)(s32)(px - r), (s16)(s32)(py - r), t, t, 1);
                } else {
                    d = D_80110634++;
                    d->w0 = 0xFB000000;
                    x = (((u32)(u8)col[i * 3]) << 24) | (((u32)(u8)col[i * 3 + 1]) << 16) | (((u32)(u8)col[i * 3 + 2]) << 8);
                    v = (f32)lens[i] * alpha;
                    cv = (u32)v;
                    __asm__ ("" : "=r"(a0v) : "0"(0x259));
                    __asm__ ("" : "=r"(a1v) : "0"(0));
                    y = cv & 0xFF;
                    d->w1 = x | y;
                    func_002ABC18(a0v, a1v, (s16)(s32)(px - r), (s16)(s32)(py - r), t, t, 1);
                }
                i++;
            } else {
                return;
            }
        } while (i < 7);
    }
}
