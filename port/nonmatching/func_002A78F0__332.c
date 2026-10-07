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
    AnimSlot *s, *t0, *t1;
    s32 i, swapped, n;
    s32 w, h;
    s16 a;
    s32 row, col;
    f32 acc, f, fs0, sx, sy, x, y, k;
    Vp24 *P;
    u32 al;
    s32 r, g, b;

    for (i = 0; i < 4; i++) {
        sl[i] = &c->slot[i];
    }
    swapped = 0;
    do {
        for (i = swapped; ; ) {
            t0 = sl[i];
            t1 = sl[i + 1];
            i = i + 1;
            if ((u32)t1->unk1C < (u32)t0->unk1C) {
                swapped = 1;
                sl[i - 1] = t1;
                sl[i] = t0;
            }
            if (i < 3) {
                continue;
            }
            break;
        }
        if (swapped == 0) {
            break;
        }
        swapped = 0;
    } while (1);
    n = 0;
    acc = 0.0f;
    P = &p->unk5DC->vp;
    sx = P->a * 0.0015625f;
    sy = P->b * 0.00208333f;
    for (i = 0; i < 4; i++) {
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
                fs0 = f * 0.1f;
                row = n / 4;
                col = n - row * 4;
                x = P->c + P->a * 0.5f + ((0.75f - col * 0.25f) + acc) * 0.5f * P->a - w * sx * 0.5f;
                y = P->d + P->b * 0.5f + (0.75f - row) * 0.5f * P->b - h * sy * 0.5f;
                {
                    DlCmd *g1 = D_80110634++;
                    g1->w0 = 0xFB000000;
                    g1->w1 = 0xFFFFFF00 | ((u32)(fs0 * 255.0f) & 0xFF);
                }
                func_002ABC18(s->unk10, s->unk14, (s32)x, (s32)y, sx, sy, 1);
                n++;
                if (a != s->unk18 && fs0 < 0.25f) {
                    acc += 0.25f - fs0;
                }
            }
        }
    }
    if (c->unk0 != 0) {
        n = 0;
        sx = P->a * 0.003125f;
        sy = P->b * 0.00416667f;
        k = (f32)(c->unk1 * 0x33);
        for (i = 0; i < 4; i++) {
            s = &c->slot[i];
            if (s->unk0 != 0) {
                func_002AB940(s->unk10, s->unk14, &w, &h);
                if (w != 0) {
                    row = n / 4;
                    col = n - row * 4;
                    x = P->c + P->a * 0.5f + ((2.0f * col * 0.25f + -0.75f) * 0.5f * P->a);
                    if (i == c->cur) {
                        a = c->unkE6;
                        if ((f32)a < 0.0f) {
                            a = -a;
                        }
                        r = 0xFF;
                        g = 0xFF;
                        b = 0xFF;
                        fs0 = (f32)((a * 0xBF) / 5 + 0x40) * 0.00390625f;
                    } else {
                        r = 0x80;
                        g = 0x80;
                        b = 0x80;
                        fs0 = 0.5f;
                    }
                    {
                        DlCmd *g1 = D_80110634++;
                        g1->w0 = 0xFB000000;
                        al = (u32)(fs0 * k);
                        g1->w1 = (r << 24) | (g << 16) | (b << 8) | (al & 0xFF);
                    }
                    n++;
                    y = P->d + P->b * 0.5f + ((2.0f * row + -0.5f) * 0.5f * P->b);
                    func_002ABC18(s->unk10, s->unk14, (s32)(x - w * sx * 0.5f), (s32)(y - h * sy * 0.5f), sx, sy, 1);
                }
            }
        }
    }
}
