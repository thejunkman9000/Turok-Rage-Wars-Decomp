#include "b19b_types.h"
typedef struct B19bG8 { u32 flags; u8 pad4[0xC]; u32 f10; } B19bG8;
extern B19bG8 D_801462C8;
typedef struct B19bLObj {
    /* 0x0 */ u8 pad0[4];
    /* 0x4 */ f32 f4;
    /* 0x8 */ B19bV3f pos;
    /* 0x14 */ u8 pad14[0xA4];
    /* 0xB8 */ u8 fB8;
    /* 0xB9 */ u8 padB9;
    /* 0xBA */ u8 fBA;
} B19bLObj;
void func_00272908(void *, void *, void *);
s32 func_00277198(void *, B19bV3f, void *, f32 *);
void func_00271FA4(void *, void *, void *);
void func_00272A80(void *, void *, void *);
void func_00271FD8(void *, void *, void *);
void func_002720EC(void *);
void func_0027200C(void *, void *, f32);
f32 func_00278900(void *);

void func_0028994C(B19bLObj **ents, s32 n, f32 *pos, u8 *out) {
    f32 w[128];
    B19bV3f dirs[128];
    B19bV3f t0, a, b, c, d, e, f, g, h, i, j;
    B19bLObj *last;
    B19bLObj *o;
    f32 scale, s0, s1, s2, x;
    s32 k, v;
    f32 *wp, *w1;
    B19bV3f *dp;
    B19bLObj **ep;
    scale = (f32)D_801462C8.f10 * 0.003921569f;
    last = 0;
    if (D_801462C8.flags & 0x4000) {
        out[4] = out[0] = 0;
        out[5] = out[1] = 0;
        out[6] = out[2] = 0;
        out[0xC] = out[8] = 0;
        out[0xD] = out[9] = 0;
        out[0xE] = out[0xA] = 0;
        out[0x10] = 0x7F;
        out[0x11] = 0;
        out[0x12] = 0;
        return;
    }
    k = 0;
    a.z = a.y = a.x = 0.0f;
    c.z = c.y = c.x = 0.0f;
    d.z = d.y = d.x = 0.0f;
    e.z = e.y = e.x = 0.0f;
    if (n > 0) {
        wp = w;
        ep = ents;
        dp = dirs;
        do {
            o = *ep;
            func_00272908((u8 *)o + 0x20, pos, &t0);
            if (func_00277198(o, t0, &g, wp) != 0) {
                func_00271FA4(&h, &g, &t0);
                func_00272A80((u8 *)o + 0x60, &h, &g);
                func_00271FD8(dp, pos, &g);
                func_002720EC(dp);
                b = o->pos;
                if (o->fBA != 0) {
                    x = func_00278900(o);
                    i.x = i.y = i.z = x;
                    func_0027200C(&f, &i, *wp * o->f4);
                    last = o;
                    if (o->fB8 != 0) func_0027200C(&f, &f, -1.0f);
                    func_00271FA4(&c, &c, &f);
                }
                s1 = o->f4 * 0.5f;
                s0 = 1.0f - s1;
                func_0027200C(&f, &b, *wp * s1);
                if (o->fB8 != 0) func_0027200C(&f, &f, -1.0f);
                func_00271FA4(&c, &c, &f);
                *wp *= s0;
                x = b.x;
                if (x < 0.0f) x = -x;
                if (!(b.y < 0.0f)) x = x + b.y; else x = x - b.y;
                if (!(b.z < 0.0f)) s0 = x + b.z; else s0 = x - b.z;
                func_0027200C(&f, dp, *wp);
                func_0027200C(&f, &f, s0);
                func_00271FA4(&a, &a, &f);
                if (o->fB8 != 0) *wp = -*wp;
            } else {
                dp->x = 0.0f;
                dp->y = 0;
                dp->z = 0;
                *wp = 0.0f;
            }
            wp++;
            dp++;
            k++;
            ep++;
        } while (k < n);
    }
    func_002720EC(&a);
    k = 0;
    if (n > 0) {
        wp = w;
        ep = ents;
        dp = dirs;
        s1 = 1.0f;
        w1 = w;
        do {
            s2 = a.x * dp->x + a.y * dp->y + a.z * dp->z;
            o = *ep;
            s0 = s1 - s2;
            if (s2 < 0.0f) s0 = s1;
            s0 = s0 * 0.5f;
            b = o->pos;
            s2 = s1 - s0;
            if (o == last) {
                x = func_00278900(o);
                i.x = i.y = i.z = x;
                func_0027200C(&j, &i, s2 * *w1);
                func_00271FA4(&e, &e, &j);
                func_0027200C(&j, &i, s0 * *w1);
                func_00271FA4(&d, &d, &j);
            }
            func_0027200C(&f, &b, s2 * *w1);
            func_00271FA4(&e, &e, &f);
            dp++;
            ep++;
            k++;
            func_0027200C(&f, &b, s0 * *w1);
            func_00271FA4(&d, &d, &f);
            w1++;
        } while (k < n);
    }
    func_0027200C(&d, &d, 0.5f);
    func_00271FA4(&c, &c, &d);
    if (c.x < 0.0f) e.x += c.x;
    if (c.y < 0.0f) e.y += c.y;
    if (c.z < 0.0f) e.z += c.z;
    x = c.x;
    if (!(x <= 255.0f)) x = 255.0f;
    if (!(5.0f <= x)) x = 5.0f;
    c.x = x * (1.0f - scale) + scale * 255.0f;
    x = c.y;
    if (!(x <= 255.0f)) x = 255.0f;
    if (!(5.0f <= x)) x = 5.0f;
    c.y = x * (1.0f - scale) + scale * 255.0f;
    x = c.z;
    if (!(x <= 255.0f)) x = 255.0f;
    if (!(5.0f <= x)) x = 5.0f;
    c.z = x * (1.0f - scale) + scale * 255.0f;
    x = e.x;
    if (!(x <= 255.0f)) x = 255.0f;
    if (!(5.0f <= x)) x = 5.0f;
    e.x = x * (1.0f - scale) + scale * 255.0f;
    x = e.y;
    if (!(x <= 255.0f)) x = 255.0f;
    if (!(5.0f <= x)) x = 5.0f;
    e.y = x * (1.0f - scale) + scale * 255.0f;
    x = e.z;
    if (!(x <= 255.0f)) x = 255.0f;
    if (!(5.0f <= x)) x = 5.0f;
    e.z = x * (1.0f - scale) + scale * 255.0f;
    v = (u32)c.x;
    out[4] = out[0] = v;
    v = (u32)c.y;
    out[5] = out[1] = v;
    v = (u32)c.z;
    out[6] = out[2] = v;
    v = (u32)e.x;
    out[0xC] = out[8] = v;
    v = (u32)e.y;
    out[0xD] = out[9] = v;
    v = (u32)e.z;
    out[0xE] = out[0xA] = v;
    out[0x10] = (s32)(a.x * 127.0f);
    out[0x11] = (s32)(a.y * 127.0f);
    out[0x12] = (s32)(a.z * 127.0f);
}
