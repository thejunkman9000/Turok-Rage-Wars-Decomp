#include "q04_types.h"

typedef struct Q4V3 { f32 x, y, z; } Q4V3;
typedef struct Q4Gfx { u32 w0, w1; } Q4Gfx;
typedef struct { u8 pad[0xC]; s16 h0C; } Q4Sub;
typedef struct Q4B188 { s32 w[0x62]; } Q4B188;
typedef struct Q4Cam {
    u8 pad0[0x28];
    f32 f28;
    u8 pad2C[0x160 - 0x2C];
    u8 view[0x29C - 0x160];
    f32 f29C;
    f32 f2A0;
    u8 pad2A4[0x380 - 0x2A4];
    struct { f32 m[16]; } mtx380[4];
} Q4Cam;
typedef struct Q4Win {
    s16 id;
    u8 pad2[0x26];
    f32 f28;
    u8 pad2C[4];
    f32 f30;
    f32 f34;
    u8 pad38[8];
    Q4Cam *cam;
} Q4Win;
typedef struct Q4Part {
    s32 f0;
    s32 f4;
    s32 f8;
    Q4V3 pos;
    Q4V3 f18;
    u8 pad24[8];
    f32 f2C;
} Q4Part;
typedef struct Q4Fx {
    u8 pad0[8];
    Q4V3 pos8;
    u8 pad14[4];
    void *f18;
    u8 pad1C[0x50 - 0x1C];
    Q4V3 v50;
    u8 pad5C[0x6C - 0x5C];
    f32 f6C;
    u8 pad70[0x1C4 - 0x70];
    Q4V3 v1C4;
    u8 pad1D0[0x27C - 0x1D0];
    void *f27C;
    u8 pad280[0x2E8 - 0x280];
} Q4Fx;
typedef struct Q4X {
    s32 id;
    s32 f4;
    s32 f8;
    f32 fC;
    u8 pad10[8];
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0xF8 - 0x24];
    f32 fF8;
    u8 padFC[0x190 - 0xFC];
    Q4Fx fx;
    u8 padfx[0x478 - 0x190 - sizeof(Q4Fx)];
    s32 f478;
    f32 f47C;
} Q4X;
typedef struct Q4O {
    u8 pad0[8];
    u32 f8;
    u8 padC[8];
    Q4Part *f14;
    u8 pad18[8];
    Q4X *f20;
} Q4O;
extern Q4Gfx *D_80110634;
extern s32 D_800D297C;
extern s32 D_800D2980;
extern s32 D_800D2B40;
extern f32 D_800D2988;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800E5E70;
extern s32 D_801540E0;
extern u8 D_8011FE88[];
extern s32 D_800CE430[];
void *memset(void *, s32, u32);
extern f32 sinf(f32);
void *func_0028CF7C(void *, s32, s32);
void func_00272908(void *m, Q4V3 *in, Q4V3 *out);
void func_00246690(void *fx, s32 a, s32 b, s32 c, void *d, s32 e, s32 f, f32 g, Q4V3 h, s32 i, Q4V3 j, Q4V3 k, s32 l);
void func_0024B2C0(void *fx);
void func_0024B8B4(void *fx);
void func_00246E34(void *fx);
s32 func_0025471C();
void func_0025470C(s32 a);
void func_0028B250(void *a, void *b, s32 c, s32 d);
void func_0026D980();
void func_0026D9D0();
void func_00249E18(void *fx, void *cam);
extern void func_00443274();
extern void func_00443298();

typedef struct { s32 id; } Q4IdS;
void func_004409A8(Q4O *o, Q4IdS *idp, s32 unused, Q4Win *w) {
    Q4V3 v50;
    Q4V3 v60;
    Q4V3 v70;
    Q4V3 v80;
    Q4X *x;
    Q4X *x2;
    Q4Cam *c;
    Q4Part *p;
    Q4Fx *fx;
    Q4B188 *src;
    Q4B188 *dst;
    void *s3;
    s32 s2;
    Q4Gfx *d;
    f32 k;
    f32 k2;
    f32 tt;
    f32 ta, tb;
    memset(&v50, 0, 12);
    if (o->f20 != 0) {
        x = o->f20;
        p = o->f14;
        fx = &x->fx;
        if (x->f478 != 0) {
            { Q4Gfx **pp = &D_80110634; d = (*pp)++;
            d->w0 = 0xDA380007;
            d->w1 = (u32)&w->cam->mtx380[D_800D297C]; }
            c = w->cam;
            k = c->f29C / (f32)D_800E28D0;
            k2 = c->f2A0 / (f32)D_800E28D4;
            v80.x = p->f18.x * k;
            v80.z = p->f18.z * k;
            v80.y = p->f18.y * k2;
            x->f47C = x->fF8;
            s3 = 0;
            if (!(o->f8 & 0x2000000)) {
                s2 = p->f4;
                x2 = o->f20;
                src = func_0028CF7C(D_8011FE88, s2, p->f8);
                if (src == 0) {
                    x2->f478 = 0;
                } else {
                    x2->id = s2;
                    x2->f478 = 1;
                    *(Q4B188 *)&x2->f4 = *src;
                    s3 = &x2->f4;
                    x2->f4 = 0;
                    x2->f8 = 0;
                    x2->f18 = 0;
                    x2->f1C = 0;
                    x2->f20 = 0;
                    x2->fC = 10240.0f;
                    x2->f47C = x2->fF8;
                }
            }
            v60 = p->pos;
            v60.y = v60.y - x->f47C * v80.y * 0.8f;
            func_00272908(w->cam->view, &v60, &v70);
            if (s3 != 0 && !(o->f8 & 0x2000000)) {
                func_00246690(fx, -1, p->f0, D_800D2B40, s3, -1, 0, w->cam->f28 + 3.141593f, v70, 0, p->f18, v50, 0);
                func_0024B2C0(fx);
                o->f8 = o->f8 | 0x2000000;
            }
            tt = sinf((f32)(u32)(D_800D2980 * 10) * 0.017453294f); ta = w->f30; tb = w->f34; D_801540E0 = (s32)(ta * tb * ((tt + 1.0f) * 50.0f + 50.0f));
            
            if (w->id == idp->id) {
                fx->f27C = (void *)func_00443298;
            } else {
                fx->f27C = (void *)func_00443274;
            }
            if (func_0025471C() == 0) {
                func_0025470C(1);
            }
            if (x->id == 0xB) {
                func_0028B250(D_8011FE88, fx, D_800CE430[((Q4Sub *)fx->f18)->h0C], 1);
            }
            if (D_800E5E70 != 4) {
                D_800E5E70 = 4;
                { Q4Gfx **pp = &D_80110634; Q4Gfx *q = (*pp)++; q->w0 = 0xE7000000; q->w1 = 0; }
                { Q4Gfx **pp = &D_80110634; Q4Gfx *q = (*pp)++; q->w0 = 0xE3000A01; q->w1 = 0x100000; }
                { Q4Gfx **pp = &D_80110634; Q4Gfx *q = (*pp)++; q->w0 = 0xE3000C00; q->w1 = 0x80000; }
                { Q4Gfx **pp = &D_80110634; Q4Gfx *q = (*pp)++; q->w0 = 0xE3001201; q->w1 = 0x2000; }
            }
            fx->v50 = v80;
            fx->pos8 = v70;
            fx->v1C4 = v70;
            func_0024B8B4(fx);
            fx->pos8 = v70;
            fx->v1C4 = v70;
            func_00246E34(fx);
            fx->f6C = fx->f6C + p->f2C * D_800D2988;
            fx->pos8 = v70;
            fx->v1C4 = v70;
            func_0026D980();
            func_00249E18(fx, w->cam);
            func_0026D9D0();
        }
    }
}
