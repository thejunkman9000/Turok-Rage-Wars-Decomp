#include "m03_types.h"

typedef struct M03VBox { u8 pad0[0x1C]; u32 mask; } M03VBox;
typedef struct M03VAct M03VAct;
typedef struct M03VCam {
    /* 0x000 */ u8 pad0[0x64];
    /* 0x064 */ u32 mask;
    /* 0x068 */ u8 pad68[0x288];
    /* 0x2F0 */ u8 frustum[0x60];
    /* 0x350 */ f32 minx;
    /* 0x354 */ f32 miny;
    /* 0x358 */ f32 minz;
    /* 0x35C */ f32 maxx;
    /* 0x360 */ f32 maxy;
    /* 0x364 */ f32 maxz;
} M03VCam;
typedef struct M03VCtx {
    s32 vis;
    s32 vis2;
    M03VCam *cam;
    s32 *h1;
    s32 *h2;
    f32 *fl;
    s32 z;
} M03VCtx;
struct M03VAct {
    /* 0x000 */ u8 pad0[1];
    /* 0x001 */ s8 b1;
    /* 0x002 */ s8 b2;
    /* 0x003 */ u8 pad3[0x11];
    /* 0x014 */ M03VBox *box;
    /* 0x018 */ u8 pad18[0xA8];
    /* 0x0C0 */ M03Dl *dl;
    /* 0x0C4 */ s32 wC4;
    /* 0x0C8 */ u8 padC8[8];
    /* 0x0D0 */ s32 wD0;
    /* 0x0D4 */ u8 padD4[0x14];
    /* 0x0E8 */ f32 minx;
    /* 0x0EC */ f32 miny;
    /* 0x0F0 */ f32 minz;
    /* 0x0F4 */ f32 maxx;
    /* 0x0F8 */ f32 maxy;
    /* 0x0FC */ f32 maxz;
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0x6C];
    /* 0x170 */ u8 blk170[0x10C];
    /* 0x27C */ void (*drawFn)(M03VAct *, void *, M03VCtx *, M03Dl *);
    /* 0x280 */ u8 pad280[0xC];
    /* 0x28C */ void (*xformFn)(M03VAct *, void *);
};

extern M03Dl *D_80110634;
extern u8 D_800C8B10[];
extern s32 D_80146894;
s32 func_002484A0(M03VAct *a, s32 h, s32 n);
s32 *func_0024BFC4(M03VAct *a, s32 idx);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u8 *h, s32 i);
void func_002536F4(s32 a, s32 *p);
void func_0026D8F8(void);
void func_0026EE90(void *a, s32 b, void *c);
s32 func_0028FD94(s32 n, s32 i);
void func_00296FF8(void);
s32 func_00297B74(void *a, void *b);

void func_00249E18(M03VAct *a, M03VCam *vp_) {
    register M03VCam *v asm("$23");
    f32 z0;
    f32 fl[3];
    u8 unused[0x14];
    M03VCtx ctx;
    M03Dl *d1, *d2, *d3, *d4;
    M03Dl *e;
    M03Dl *dl;
    s32 *h;
    s32 *p;
    s32 *p2;
    s32 n;
    register s32 vis asm("$22");
    s32 vis2;
    u32 fg;

    v = vp_;
    fg = a->flags;
    if ((fg & 0x40000) && a->drawFn != 0) {
        if (!(fg & 0x2000)) {
            a->flags = fg & ~0x200;
            return;
        }
        h = func_002518DC(0, a->wC4, a->wC4, a->wD0, 0, 0, 0, D_800C8B10, 1);
        if (h != 0) {
            n = func_0028FD94(*h, 0);
            if (D_80146894 != 0) {
                a->xformFn(a, a->blk170);
                func_0026EE90((u8 *)a + 0x74, n, (u8 *)a + 0xE8);
            }
            if (a->flags & 0x200000) {
                vis = 1;
                vis2 = vis;
            } else {
                vis = 0;
                vis2 = vis;
                if ((a->box == 0 || (v->mask & a->box->mask)) && v->maxx > a->minx && v->minx < a->maxx &&
                    v->maxz > a->minz && v->minz < a->maxz && v->maxy > a->miny && v->miny < a->maxy &&
                    func_00297B74(v->frustum, &a->minx) != 0) {
                    vis = 1;
                    if (a->box != 0) {
                        vis2 = vis;
                    }
                }
            }
            if (vis != 0 || vis2 != 0) {
                func_0026D8F8();
                func_00296FF8();
                if (a->dl != 0) {
                    d1 = D_80110634++;
                    d1->w0 = 0xDE000000;
                    d1->w1 = (u32)a->dl;
                    func_002536F4(0, h);
                    goto done;
                } else {
                    p = func_0024BFC4(a, a->b1);
                    if (p != 0) {
                        if (!(a->flags & 0x200) && func_002484A0(a, *p, n) == 0) {
                            func_002536F4(0, p);
                        } else {
                        z0 = 0.0f;
                        fl[2] = z0;
                        fl[1] = z0;
                        fl[0] = z0;
                        if (vis2 != 0) {
                            p2 = func_0024BFC4(a, a->b2);
                            vis2 = p2 != 0;
                        } else {
                            p2 = 0;
                        }
                        ctx.vis2 = vis2;
                        ctx.vis = vis;
                        ctx.cam = v;
                        ctx.h1 = p;
                        ctx.h2 = p2;
                        ctx.fl = fl;
                        ctx.z = 0;
                        dl = D_80110634;
                        a->dl = dl;
                        d2 = D_80110634++;
                        d2->w0 = 0xDE010000;
                        d2->w1 = 0;
                        a->drawFn(a, a->blk170, &ctx, dl);
                        d3 = D_80110634++;
                        d3->w0 = 0xDF000000;
                        d3->w1 = 0;
                        e = a->dl++;
                        e->w0 = 0xDE010000;
                        e->w1 = (u32)D_80110634;
                        d4 = D_80110634++;
                        d4->w0 = 0xDE000000;
                        d4->w1 = (u32)a->dl;
                        func_002536F4(0, p);
                        if (p2 != 0) {
                            func_002536F4(0, p2);
                        }
                        }
                    }
                }
            }
            func_002536F4(0, h);
        }
    }
done:
    return;
}





