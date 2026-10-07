#include "b10_types.h"

extern void *D_80103FCC;
extern f32 D_800C8848;
extern u8 D_801040F0[];
s32 func_0023E8C4(B10A *a, s32 *ctx, s32 f);
void func_00240D10(s32 *ctx, B10Buf *q);
void func_00240DF0(s32 *ctx, B10Buf *q);
void func_00240ED0(s32 *ctx, B10Buf *q);
void func_00240FB0(s32 *ctx, B10Buf *q);
void func_00241090(s32 *ctx, B10Buf *q);
void func_00241170(s32 *ctx, B10Buf *q);
f32 func_00241718(B10Dc *w, s32 x, s32 z);
f32 func_0024E454(B10Obj *o);
f32 func_0024D388(B10Obj *o);
f32 func_0024D274(B10Obj *o);
f32 func_0024E410(B10Obj *o);
s32 func_0024490C(B10Obj *o, Vec3f pos, Vec3f p, u8 *ctx, f32 a, f32 b, f32 c, f32 d);
void func_00271FA4(Vec3f *a, Vec3f *b, f32 *c);

void func_00241B9C(B10A *a, s32 arg1, B10Buf *q, B10Ev *ctx, B10Obj *o)
{
  B10Sc scratch;
  Vec3f p;
  void *saved;
  f32 h;
  f32 fa;
  f32 fb;
  f32 fc;
  f32 fd;
  s32 r;
  f32 new_var;
  if (a->f60 > 0.0f)
  {
    ctx->type = 3;
    func_00240D10(&ctx->type, q);
    if (func_0023E8C4(a, &ctx->type, 0))
    {
      saved = D_80103FCC;
      D_80103FCC = &scratch;
      new_var = func_00241718((B10Dc *) ctx, o->u8, o->u10);
      h = new_var;
      o->u34 = arg1;
      fa = func_0024E454(o);
      fb = func_0024D388(o);
      fc = func_0024D274(o);
      fd = func_0024E410(o);
      h += D_800C8848;
      p.x = *((f32 *) (&o->u8));
      p.y = h;
      p.z = *((f32 *) (&o->u10));
      if (func_0024490C(o, *((Vec3f *) (&o->u8)), p, D_801040F0, fa, fb, fc, fd))
      {
        a->dc = *((B10Dc *) ctx);
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
  }
  if (a->f60 < 0.0f)
  {
    ctx->type = 2;
    func_00240DF0(&ctx->type, q);
    if (func_0023E8C4(a, &ctx->type, 1))
    {
      a->f3C |= 8;
      o->f38 |= 0x10;
    }
  }
  if ((a->f5C != 0.0f) || (a->f64 != 0.0f))
  {
    ctx->type = 3;
    func_00240ED0(&ctx->type, q);
    r = func_0023E8C4(a, &ctx->type, 1);
    func_00240FB0(&ctx->type, q);
    r |= func_0023E8C4(a, &ctx->type, 1);
    func_00241090(&ctx->type, q);
    r |= func_0023E8C4(a, &ctx->type, 1);
    func_00241170(&ctx->type, q);
    r |= func_0023E8C4(a, &ctx->type, 1);
    if (r)
    {
      a->f3C |= 8;
      func_00271FA4(&o->v1C, &o->v1C, &a->f5C);
    }
  }
}
