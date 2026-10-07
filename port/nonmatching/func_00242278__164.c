#include "b10_types.h"

extern u8 D_80104338[];
s32 func_0023E168(B10Obj *o, Vec3f *p, f32 h, f32 a, f32 b, s32 c, s32 *ctx, s32 d);
s32 func_0023EA34(B10Obj *o, s32 *ctx, Vec3f *p, f32 h, s32 a);
s32 func_0023E8C4(B10Obj *o, s32 *ctx, s32 a);
void func_00240D10(s32 *ctx, B10Buf *q);
void func_00240DF0(s32 *ctx, B10Buf *q);
void func_00240ED0(s32 *ctx, B10Buf *q);
void func_00240FB0(s32 *ctx, B10Buf *q);
void func_00241090(s32 *ctx, B10Buf *q);
void func_00241170(s32 *ctx, B10Buf *q);
void func_00241940(B10Mo *mo, B10Buf *buf, B10Obj *o, s32 a);

inline s32 func_00242A84(B10Obj *o, B10Mo *t, B10Buf *q, s32 *ctx) {
    s32 r = 0;
    Vec3f *p = &t->pos;
    f32 h = t->p18->k.f8 + o->fC;
    if (o->f5C != 0.0f || o->f64 != 0.0f) {
        *ctx = 3;
        r = func_0023E168(o, p, h, q->f4, q->f34, 1, ctx, 1);
    }
    if (o->f60 > 0.0f) {
        *ctx = 2;
        func_00240DF0(ctx, q);
        r |= func_0023EA34(o, ctx, p, h, 1);
    }
    if (o->f60 < 0.0f) {
        *ctx = 9;
        func_00240D10(ctx, q);
        r |= func_0023EA34(o, ctx, p, h, 1);
    }
    return r;
}

inline s32 func_00242910(B10Obj *o, s32 unused, B10Buf *q, s32 *ctx) {
    s32 r = 0;
    if (o->f60 > 0.0f) {
        *ctx = 2;
        func_00240DF0(ctx, q);
        r = func_0023E8C4(o, ctx, 1);
    }
    if (o->f5C != 0.0f || o->f64 != 0.0f) {
        *ctx = 3;
        func_00240ED0(ctx, q);
        r |= func_0023E8C4(o, ctx, 1);
        func_00240FB0(ctx, q);
        r |= func_0023E8C4(o, ctx, 1);
        func_00241090(ctx, q);
        r |= func_0023E8C4(o, ctx, 1);
        func_00241170(ctx, q);
        r |= func_0023E8C4(o, ctx, 1);
    }
    if (o->f60 < 0.0f) {
        *ctx = 9;
        func_00240D10(ctx, q);
        r |= func_0023E8C4(o, ctx, 1);
    }
    return r;
}

void func_00242278(B10Obj *o, B10Mo *t) {
    B10Ev ev;
    B10Buf buf;
    B10Mkk *k = &t->p18->k;
    B10Fl *fl = o->p40;
    if (fl != (B10Fl *)D_80104338 && fl->b4 != 0) {
        func_00241940(t, &buf, o, *(s32 *)o);
        ev.f4 = 0;
        ev.f8 = 2;
        ev.fC = 0;
        ev.f10 = 0;
        ev.f54 = (s32)t;
        ev.f58 = -1;
        switch (k->kind) {
        case 1:
            func_00242A84(o, t, &buf, &ev.type);
            break;
        case 2:
            func_00242910(o, 0, &buf, &ev.type);
            break;
        }
    }
}
