#include "b24_types.h"

typedef struct Vp24 {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
} Vp24;

typedef struct Sub24b {
    u8 pad0[0x29C];
    Vp24 vp;
} Sub24b;

typedef struct Plr24c {
    u8 pad0[0x5DC];
    Sub24b *unk5DC;
} Plr24c;

extern DlCmd *D_80110634;
void func_002AB940(s32, s32, s32 *, s32 *);
void func_002ABC18(s32, s32, s16, s16, f32, f32, s32);

void func_002A78F0(AnimCtl *c, Plr24c *p) {
    AnimSlot *sl[4];
    AnimSlot *t0, *t1;
    s32 i, swapped, n;
    s32 w, h;
    s32 r, g, b;
    f32 acc, sx, sy, x0, y0, fs0;
    Vp24 *P;
    f32 kf;
    u32 rgba;

    acc = 0.0f;
    for (i = 0; i < 4; i++) {
        sl[i] = &c->slot[i];
    }
    do {
        swapped = 0;
        for (i = 0; i < 3; i++) {
            t0 = sl[i];
            t1 = sl[i + 1];
            if ((u32)t0->unk1C > (u32)t1->unk1C) {
                sl[i] = t1;
                sl[i + 1] = t0;
                swapped = 1;
            }
        }
    } while (swapped);
    r = g = b = 0xFF;
    i = 0;
    n = i;
    P = &p->unk5DC->vp;
    sx = P->a * 0.0015625f;
    sy = P->b * 0.0020833334f;
    for (; i < 4; i++) {
        AnimSlot *s;
        s16 a;
        s32 row, col;
        f32 f;
        f32 k01, k025, k075, k05;
        kf = 255.0f; k01 = 0.1f; k025 = 0.25f; k075 = 0.75f; k05 = 0.5f;
        s = sl[i];
        a = s->unk18;
        if ((f32)a < 0.0f) {
            a = -a;
        }
        if (s->unk0 != 0 && (s->unk4 != 0 || a != 0)) {
            func_002AB940(s->unk10, s->unk14, &w, &h);
            if (w != 0) {
                if (a != s->unk18) {
                    f = a;
                } else {
                    f = 5 - a;
                }
                do { fs0 = f * k01; } while (0);
                row = n / 4;
                col = n - row * 4;
                x0 = P->c + P->a * k05 + ((k075 - col * k025) + acc) * k05 * P->a;
                y0 = P->d + P->b * k05 + (k075 - row) * k05 * P->b;
                {
                    DlCmd *g1 = D_80110634++;
                    g1->w0 = 0xFB000000;
                    rgba = (r << 24) | (g << 16) | (b << 8);
                    g1->w1 = rgba | ((u32)(fs0 * kf) & 0xFF);
                }
                func_002ABC18(s->unk10, s->unk14, (s32)(x0 - w * sx * k05), (s32)(y0 - h * sy * k05), sx, sy, 1);
                if (a != s->unk18 && fs0 < k025) {
                    acc += k025 - fs0;
                }
                n++;
            }
        }
    }
    if (c->unk0 != 0) {
        i = 0;
        n = i;
        sx = P->a * 0.003125f;
        sy = P->b * 0.004166667f;
        kf = (f32)(c->unk1 * 0x33);
        for (; i < 4; i++) {
            AnimSlot *s;
            s32 a;
            s32 row, col;
            f32 f;
            s = &c->slot[i];
            if (s->unk0 != 0) {
                func_002AB940(s->unk10, s->unk14, &w, &h);
                if (w != 0) {
                    row = n / 4;
                    col = n - row * 4;
                    x0 = P->c + P->a * 0.5f + ((2.0f * col * 0.25f + -0.75f) * 0.5f * P->a);
                    y0 = P->d + P->b * 0.5f + ((2.0f * row + -0.5f) * 0.5f * P->b);
                    if (i == c->cur) {
                        a = c->unkE6;
                        if ((f32)a < 0.0f) {
                            a = -a;
                        }
                        /* HACK (match only): the dead second /5 (different dividend, same extended
                           basic block) lengthens the life of the 0x66666667 constant so loop.c hoists
                           it into s6 like the ROM; flow deletes the set because r is overwritten below.
                           The do{}while(0) is a scheduling barrier between the cvt and the r/g/b/mul. */
                        do { r = (a * 0xC1 + 3) / 5; f = (f32)((a * 0xBF) / 5 + 0x40); } while (0);
                        r = 0xFF; g = 0xFF; b = 0xFF;
                        fs0 = f * 0.00390625f;
                    } else {
                        r = 0x80;
                        g = 0x80;
                        b = 0x80;
                        /* HACK (match only): second-block reference makes f a global allocno ($f1) */
                        __asm__ volatile("" : "=f"(f));
                        fs0 = 0.5f;
                    }
                    {
                        DlCmd *g1 = D_80110634++;
                        g1->w0 = 0xFB000000;
                        g1->w1 = (r << 24) | (g << 16) | (b << 8) | ((u32)(fs0 * kf) & 0xFF);
                    }
                    n++;
                    func_002ABC18(s->unk10, s->unk14, (s32)(x0 - w * sx * 0.5f), (s32)(y0 - h * sy * 0.5f), sx, sy, 1);
                }
            }
        }
    }
}
