#include "b10_types.h"

extern void *D_80103FCC;
extern f32 D_800C884C;
extern u8 D_801040F0[];
s32 func_0023EA34(B10A *a, s32 *ctx, Vec3f *p, f32 h, s32 f);
s32 func_0023E168(B10A *a, Vec3f *p, f32 h, f32 x, f32 y, s32 c, s32 *ctx, s32 d);
void func_00240D10(s32 *ctx, B10Buf *q);
void func_00240DF0(s32 *ctx, B10Buf *q);
f32 func_00241718(B10Dc *w, s32 x, s32 z);
f32 func_0024E454(B10Obj *o);
f32 func_0024D388(B10Obj *o);
f32 func_0024D274(B10Obj *o);
f32 func_0024E410(B10Obj *o);
s32 func_0024490C(B10Obj *o, Vec3f pos, Vec3f p, u8 *ctx, f32 a, f32 b, f32 c, f32 d);
void func_00271FA4(Vec3f *a, Vec3f *b, f32 *c);

void func_00241F14(B10A *a, B10Mo *t, B10Buf *q, B10Ev *ctx, B10Obj *o) {
    B10Sc scratch;
    Vec3f p;
    void *saved;
    Vec3f *tp = &t->pos;
    B10Mkk *k = &t->p18->k;
    f32 h, h2, fa, fb, fc, fd, new_var;
    h = k->f8 + func_0024D388(o);
    if (a->f60 > 0.0f) {
        ctx->type = 3;
        func_00240D10(&ctx->type, q);
        if (func_0023EA34(a, &ctx->type, tp, h, 0)) {
            saved = D_80103FCC;
            D_80103FCC = &scratch;
            h2 = (fa = func_00241718((B10Dc *)ctx, o->u8, o->u10));
            o->u34 = (s32)t;
            new_var = func_0024E454(o);
            fa = new_var;
            fb = func_0024D388(o);
            fc = func_0024D274(o);
            fd = func_0024E410(o);
            h2 += D_800C884C;
            p.x = *(f32 *)&o->u8;
            p.y = h2;
            p.z = *(f32 *)&o->u10;
            if (func_0024490C(o, *(Vec3f *)&o->u8, p, D_801040F0, fa, fb, fc, fd)) {
                a->dc = *(B10Dc *)ctx;
                a->f3C |= 8;
                o->f38 |= 0x10;
            } else {
                o->fC = p.y;
                if (o->v1C.y < 0.0f) {
                    o->v1C.y = 0.0f;
                }
                a->f3C |= 0x20;
                if (o->type == 1 && (o->flags100 & 0x300000)) {
                    a->f3C |= 0x40;
                }
                o->f38 = (o->f38 & ~3) | 2;
            }
            D_80103FCC = saved;
        }
    }
    if (a->f60 < 0.0f) {
        ctx->type = 2;
        func_00240DF0(&ctx->type, q);
        if (func_0023EA34(a, &ctx->type, tp, h, 1)) {
            a->f3C |= 8;
            o->f38 |= 0x10;
        }
    }
    if (a->f5C != 0.0f || a->f64 != 0.0f) {
        ctx->type = 3;
        if (func_0023E168(a, tp, h, q->f4, q->f34, 1, &ctx->type, 1)) {
            a->f3C |= 8;
            func_00271FA4(&o->v1C, &o->v1C, &a->f5C);
        }
    }
}
