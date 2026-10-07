#include "r02_gen.h"

extern s32 D_800CE47C[];
extern u8 D_800CED30[];
extern s16 D_800CF21A;
extern s16 D_800CF21E;
extern s16 D_800CF222;
extern u8 D_800CF1E8[];
extern f32 D_800D2988;
typedef struct { u8 pad0[0x1D]; u8 b1D; u8 pad1E[0x60E]; s32 w62C; } R2G5;
extern R2G5 D_801462C8[];

f32 sinf(f32);
f32 cosf(f32);
s32 func_0024E61C(R2A5 *);
void func_002227D0(R2P5 *, R2A5 *, s32);
void func_002748E0(f32 *, f32, f32);
f32 func_00274710(f32, f32, f32);
f32 func_00274810(f32, f32);
void func_0025DE74(s16, s32, s32, s32, s32, s32);

void func_002251B8(R2P5 *p, R2A5 *a) {
    f32 fs0;
    f32 t;
    f32 w;
    f32 x;
    f32 x1, x2;
    f32 m;
    s32 ok;
    s32 pos;
    s32 neg;
    s32 r;
    u32 fl;

    if (!(a->flags38 & 0x100)) {
        p->f724 = 0.0f;
        p->f16C0 = 0.0f;
        if (func_0024E61C(a) == 0) {
            fs0 = 2.048f;
            p->f6E8 = p->f6E8 - sinf(a->f6C) * fs0;
            p->f6F0 = p->f6F0 - cosf(a->f6C) * fs0;
        }
        func_002227D0(p, a, 5);
        return;
    }
    if (0.1f < p->f69C || p->f69C < 0.1f) {
        p->f16C0 = p->f16C0 + p->f69C * 0.0625f;
    }
    if (1.0f < p->f16C0) {
        p->f16C0 = 1.0f;
    } else if (p->f16C0 < -1.0f) {
        p->f16C0 = -1.0f;
    }
    func_002748E0(&p->f728, p->f16C0 * 0.78539824f, 0.5f);
    {
        f32 c = -p->f6A0 * 100.0f;
        if (c < -90.0f) {
            c = -90.0f;
        } else if (90.0f < c) {
            c = 90.0f;
        }
        func_002748E0(&p->f724, c * 0.017453294f, 0.0625f);
    }
    if (p->unk7E8 != 0 || 11.25f < p->f6E4) {
        ok = 0;
    } else if (a->flags38 & 0xC0000) {
        ok = 0;
    } else if (!(a->def->flags14 & 2)) {
        ok = 0;
    } else if (!(p->unk6B0 & 0x10)) {
        ok = 0;
    } else if (!(p->f11D8 <= 0.0f)) {
        ok = 0;
    } else {
        func_002227D0(p, a, 5);
        ok = 1;
    }
    if (ok != 0) {
        {
            f32 y = a->f6C + p->f728;
            f32 z;
            a->f6C = y;
            z = p->f728;
            if (1.5707965f <= z) {
                a->f6C = y + 3.141593f;
            } else if (z <= -1.5707965f) {
                a->f6C = y - 3.141593f;
            }
        }
        w = sinf(a->f6C + (fs0 = 6.2831855f));
        m = cosf(a->f6C + fs0);
        a->f1C = a->f1C + w * 384.0f;
        a->f24 = a->f24 + m * 384.0f;
        {
            f32 z = p->f728;
            if (1.5707965f <= z) {
                a->f6C = a->f6C + 3.141593f;
            } else if (z <= -1.5707965f) {
                a->f6C = a->f6C - 3.141593f;
            }
        }
        p->f728 = 0.0f;
        p->f16C0 = 0.0f;
        return;
    }
    w = sinf(p->f658 * 0.06981318f);
    t = p->f6E0 * p->f6C0 * w;
    x = p->f6A8;
    if (x > 0.0f || x < 0.0f) {
        func_002748E0(&p->f72C, t, 0.25f);
    } else {
        func_002748E0(&p->f72C, 0.0f, 0.9f);
    }
    x1 = p->f6A8;
    pos = x1 > 0.0f ? 1 : 0;
    neg = x1 < 0.0f ? 1 : 0;
    fs0 = p->f6C0;
    if (pos != 0 || neg != 0) {
        p->f6C0 = func_00274710(p->f6C0, x1 * 6.144f, x1 < 0.0f ? -x1 * 20.48f : x1 * 20.48f);
    } else {
        p->f6C0 = func_00274810(fs0, 4.096f);
    }
    x2 = p->f6A4;
    if (x2 != 0.0f) {
        p->f6C4 = func_00274710(p->f6C4, x2 * 6.144f, x2 < 0.0f ? -x2 * 20.48f : x2 * 20.48f);
    } else {
        p->f6C4 = func_00274810(p->f6C4, 4.096f);
    }
    if (p->f6C0 == 0.0f && p->f6C4 == 0.0f) {
        p->f658 = 0.0f;
        if (fs0 != 0.0f) {
            p->f6E0 = -p->f6E0;
        }
    } else {
        t = p->f658;
        if (8.4375f < t) {
            p->f6E0 = -p->f6E0;
            p->f658 = t - 8.4375f;
            p->f6C0 = p->f6C0 * 0.1f;
            p->f6C4 = p->f6C4 * 0.1f;
            if (D_801462C8->b1D != 0 && (p->stats->b8F != 1 || D_801462C8->w62C == 0)) {
                fl = p->flags38;
                if (fl & 0x200) {
                    func_0025DE74(D_800CF21A, a->w8, a->wC, a->w10, 0, -1);
                } else if (fl & 0x400) {
                    func_0025DE74(D_800CF21E, a->w8, a->wC, a->w10, 0, -1);
                } else if (fl & 0x800) {
                    func_0025DE74(D_800CF222, a->w8, a->wC, a->w10, 0, -1);
                } else {
                    func_0025DE74(*(s16 *)(D_800CF1E8 + 6 + p->unk5E0 * 4), a->w8, a->wC, a->w10, 0, -1);
                }
            }
        }
    }
    fs0 = 1.5707964f;
    w = sinf(a->f6C - fs0);
    m = cosf(a->f6C - fs0);
    p->f6E8 = p->f6E8 + w * p->f6C4 * p->f66C;
    p->f6F0 = p->f6F0 + m * p->f6C4 * p->f66C;
    p->f6EC = p->f6EC + p->f6C0 * (D_800D2988 * 1.5f);
    if (p->unkE4 == D_800CE47C[0]) goto a46;
    if (p->f6C0 > 0.0f) {
        if (p->unk13B4 != D_800CED30) goto a46;
        r = 0x5E28;
        goto st;
    }
    if (p->unk13B4 == D_800CED30) {
        r = 0x5E27;
    } else {
        r = 0xA3C;
    }
    goto st;
a46:
    r = 0xA46;
st:
    p->unk86C = r;
}
