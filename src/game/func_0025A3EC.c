#include "m04_types.h"

extern f32 D_800C9028;
extern f32 D_800C902C;
extern f32 D_800C9030;
extern f32 D_800C9034;
extern f32 D_800C9038;
extern f32 D_800C903C;
extern f32 D_800D0D10;
f32 Trunc16ToF32(u16 x);
s32 alSndpGetState(void *p);
void alSndpSetSound(void *p, s16 id);
void alSndpSetVol(void *p, s16 vol);
void alSndpStop(void *p);
s32 func_00245774();
f32 func_00274878(f32 a, f32 b, f32 c);

void func_0025A3EC(M04Emitter *o)
{
  M04Ctx **new_var;
  M04VP *vp;
  M04Rec12 *env;
  M04Ctx *c;
  M04Ctx *c2;
  M04Tgt *tg;
  register f32 m1 asm("$f1");
  f32 t;
  f32 k;
  f32 vf;
  f32 fa;
  f32 fs;
  f32 fv;
  f32 d2;
  f32 new_var2;
  f32 x;
  s32 new_var3;
  s32 neg;
  s32 n;
  register u8 *pl asm("$17");
  M04Vec3 *p;
  M04Vec3 *q;
  do
  {
    t = o->ctx->tgt->f528;
  }
  while (0);
  m1 = (t < D_800C9028) ? (D_800C9028) : (t);
  D_800D0D10 = m1 * ((t < D_800C9028) ? (D_800C9028) : (t));
  switch (o->vp.mode)
  {
    case 2:
      k = D_800C902C;
      D_800D0D10 = D_800D0D10 + (D_800D0D10 * k);
      break;

    case 1:
      k = D_800C9030;
      D_800D0D10 = D_800D0D10 + (D_800D0D10 * k);
      break;

    case 0:
      break;

  }

  vp = &o->vp;
  env = &o->env2;
  c2 = o->ctx;
  if (o->flags & 0x200)
  {
    vf = c2->volC;
  }
  else
  {
    vf = c2->volA;
    if ((o->unkC4 != 0) && (c2->unk2BB8 != 0))
    {
      vf = vf * D_800C9034;
    }
  }
  if (((o->flags & 0x400) && (o->resetFlag == 0)) && (!(o->flags & 0x800)))
  {
    tg = o->ctx->tgt;
    p = &vp->pos;
    q = (M04Vec3 *) (&tg->x);
    d2 = (((p->x - q->x) * (p->x - q->x)) + ((p->y - q->y) * (p->y - q->y))) + ((p->z - q->z) * (p->z - q->z));
    if (D_800D0D10 <= d2)
    {
      fa = 0.0f;
    }
    else
    {
      fa = D_800C9038 - (d2 / D_800D0D10);
    }
    switch (vp->mode)
    {
      case 2:
        fs = fa;
        break;

      case 0:
        fa = fa * fa;
        fa = fa * fa;

      case 1:
        fs = fa * fa;
        break;

      default:
        fs = 0.0f;
        break;

    }

    if (func_00245774() != 0)
    {
      vp->scale = func_00274878(vp->scale, fs, 0.017f);
    }
    else
    {
      vp->scale = fs;
    }
  }
  else
  {
    vp->scale = D_800C903C;
  }
  if (o->flags & 4)
  {
    if ((*((s16 *) (&o->env2.w4))) > 0)
    {
      o->env2.w4 = o->env2.w4 - 1;
    }
    else
    {
      neg = 0;
      if (o->env2Slope < 0.0f)
      {
        neg = 1;
      }
      if (neg)
      {
        if (o->env2A < Trunc16ToF32(env->w2))
        {
          goto blk;
        }
      }
      else
        if (Trunc16ToF32(env->w2) < o->env2A)
      {
        blk:
        o->env2A = o->env2A - o->env2Slope;

        if (neg)
        {
          if (Trunc16ToF32(env->w2) < o->env2A)
          {
            o->env2A = Trunc16ToF32(env->w2);
          }
        }
        else
          if (o->env2A < Trunc16ToF32(env->w2))
        {
          if ((o->env2A = Trunc16ToF32(env->w2)) == 0.0f)
          {
            c = o->ctx;
            o->unkAC = 1;
            *((s32 *) (((u8 *) o) + 0x50)) = 0;
            if ((*((s32 *) (((u8 *) o) + 0x10))) != (*(new_var = &c))->unk104)
            {
              alSndpSetSound(c->player, c->snd[o->w0]);
              if (alSndpGetState(c->player) != 0)
              {
                alSndpStop(c->player);
              }
              o->w4 = -1;
            }
          }
        }
      }
    }
    n = (vp->vol = (s32) (Trunc16ToF32(o->env2.w0) * o->env2A));
    fv = ((f32) n) * vp->scale;
  }
  else
  {
    if (o->flags & 0x400)
    {
      x = vp->scale;
    }
    else
    {
      x = vp->f20;
    }
    fv = ((f32) vp->vol) * x;
  }
  c = o->ctx;
  do
  {
    new_var3 = o->w0;
    n = (s32) (fv * vf);
    pl = c->player;
    alSndpSetSound(pl, c->snd[new_var3]);
  }
  while (0);
  new_var2 = o->unkC8;
  alSndpSetVol(pl, (s16) ((s32) (((f32) n) * new_var2)));
}