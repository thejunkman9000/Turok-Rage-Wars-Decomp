#include "b10_types.h"

extern u8 D_80104338[];
extern void *D_80103FCC;
extern f32 D_800C8850;
extern u8 D_801040F0[];
s32 func_0023E168(B10Obj *o, Vec3f *p, f32 h, f32 a, f32 b, s32 c, s32 *ctx, s32 d);
s32 func_0023EA34(B10Obj *o, s32 *ctx, Vec3f *p, f32 h, s32 a);
s32 func_0023E8C4(B10Obj *o, s32 *ctx, s32 a);
void func_00240D10(s32 *ctx, B10Buf *q);
void func_00240DF0(s32 *ctx, B10Buf *q);
void func_00240ED0(s32 *ctx, B10Buf *q);
void func_00240FB0(s32 *ctx, B10Buf *q);
void func_00241090(s32 *ctx, B10Buf *q);
void func_00241170(s32 *ctx, B10Buf *q);
void func_00241940();
void func_00241B9C(B10Mv *mv, B10Mo *mo, B10Buf *buf, B10Ev *ev, B10T2 *t);
void func_00241F14(B10Mv *mv, B10Mo *mo, B10Buf *buf, B10Ev *ev, B10T2 *t);
void func_00271FD8(Vec3f *a, Vec3f *b, f32 *c);
void func_00271FA4(f32 *a, f32 *b, f32 *c);
f32 func_00241718(B10Dc *w, s32 x, s32 z);
f32 func_0024E454(B10Obj *o);
f32 func_0024D388(B10Obj *o);
f32 func_0024D274(B10Obj *o);
f32 func_0024E410(B10Obj *o);
s32 func_0024490C(B10Obj *o, Vec3f pos, Vec3f p, u8 *ctx, f32 a, f32 b, f32 c, f32 d);

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

void func_00242540(B10Mv *mv, B10T2 *t) {
    Vec3f sa;
    Vec3f sb;
    B10Ev ev;
    B10Buf buf;
    B10Mo *mo = mv->p0;
    B10Mkk *k = &mo->p18->k;
    if (mv->p40->flags & 0x40000) {
        sa = mv->a;
        sb = mv->b;
        mv->a = t->pos;
        func_00271FD8(&mv->b, &t->pos, &mv->f5C);
        ev.f4 = 0;
        ev.f8 = 1;
        ev.fC = 0;
        ev.f10 = 0;
        ev.f54 = (s32)t;
        ev.f58 = -1;
        func_00241940(mo, &buf, mv, t);
        switch (k->kind) {
        case 1:
            func_00241F14(mv, mo, &buf, &ev, t);
            break;
        case 2:
            func_00241B9C(mv, mo, &buf, &ev, t);
            break;
        }
        mv->a = sa;
        mv->b = sb;
    }
}

void func_002426BC(B10A *a, s32 arg1, B10Obj *o, B10Dc *w)
{
  B10Sc scratch;
  Vec3f p;
  void *saved;
  f32 h;
  f32 fa;
  f32 fb;
  f32 new_var;
  f32 fc;
  f32 fd;
  saved = D_80103FCC;
  D_80103FCC = &scratch;
  h = (fa = func_00241718(w, o->u8, o->u10));
  o->u34 = arg1;
  new_var = func_0024E454(o);
  fa = new_var;
  fb = func_0024D388(o);
  fc = func_0024D274(o);
  fd = func_0024E410(o);
  h += D_800C8850;
  p.x = *((f32 *) (&o->u8));
  p.y = h;
  p.z = *((f32 *) (&o->u10));
  if (func_0024490C(o, *((Vec3f *) (&o->u8)), p, D_801040F0, fa, fb, fc, fd))
  {
    a->dc = *w;
    a->f3C |= 8;
    o->f38 |= 0x10;
  }
  else
  {
    o->fC = p.y;
    if (o->v1C.y < 0.0f)
    {
      o->v1C.y = 0.0f;
    }
    a->f3C |= 0x20;
    if ((o->type == 1) && (o->flags100 & 0x300000))
    {
      a->f3C |= 0x40;
    }
    o->f38 = (o->f38 & (~3)) | 2;
  }
  D_80103FCC = saved;
}

void func_002428C0(B10A *a, B10A *b) {
    a->f3C |= 8;
    b->f38 |= 0x10;
}

void func_002428DC(B10A *a, B10A *b) {
    a->f3C |= 8;
    func_00271FA4(b->v1C, b->v1C, &a->f5C);
}
