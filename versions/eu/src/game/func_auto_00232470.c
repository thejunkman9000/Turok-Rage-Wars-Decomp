#include "m02_gen.h"
extern f32 D_800C80C0;
extern s32 D_800E0D44[];
extern u8 D_80152789;
extern M2Row190 D_80102B00[];
extern u8 D_80145040[];
extern u8 D_80145088[];
extern u8 D_801462D5;
void func_00214178(M2Act *a, M2St *s, s32 id);
s32 func_0022A590(void *w, M2Own *o);
void func_0022AFFC(M2Own *o);
void func_0022B974(M2Own *o);
s32 func_0022F54C(void *r, s32 w);
s32 func_002301E4(M2Act *a, M2St *s);
void func_002398F8(void *w, M2Pawn *p, s32 x, s32 y, f32 f);
void func_0025DE74(s32 id, Vec3f pos, Vec3f *pp, s32 x);
void func_0025DF54(s32 id);
void func_auto_00232470(M2Act *a, M2St *s)
{
  M2Own *o;
  s32 w;
  s32 ok;
  s32 ok2;
  s32 t;
  s32 xx;
  s32 yy;
  o = a->owner;
  if (s->unkCB != 0)
  {
    w = o->unk62E;
    if (w == 4)
    {
      goto zero;
    }
    if (w == 14)
    {
      goto zero;
    }
    if (w == 15)
    {
      goto zero;
    }
    if (w != 10)
    {
      goto not10;
    }
    if (!(o->unk6AC & 0x4000))
    {
      ok = 0;
      goto done;
    }
    if (o->unk5F8 == 0)
    {
      goto zero;
    }
    ok = 1;
    goto done;
    not10:
    if (w != 3)
    {
      goto dflt;
    }

    if ((o->unk6AC & 0x6000) == 0x6000)
    {
      if (o->unk5F4 != 0)
      {
        ok = o->unk5F6;
        if (ok != 0)
          goto ok1;
      }
    }
    zero:
    ok = 0;

    goto done;
    dflt:
    ok = func_002301E4(a, s);
    goto done;
    ok1:
    ok = 1;

    done:
    if (ok != 0)
    {
      s->unkCB = 0;
      s->unk35 = -1;
    }
    else
    {
      if (o->unk62E == 5)
      {
        func_0022AFFC(o);
        func_0025DE74(0x460, o->pos, &o->pos, -1);
      }
      if (o->unk62E == 3)
      {
        if (o->unk11D8 > 0.0f)
        {
          ok2 = 0;
        }
        else
          if (o->unk1450 != 0)
        {
          ok2 = 1;
        }
        else
          if (D_801462D5 != 1)
        {
          ok2 = 1;
        }
        else
        {
          t = func_0022F54C(&D_80102B00[o->unk5D4], 3);
          if (t == 0)
          {
            func_0025DF54(0xD4D);
            if (o->pawn != 0)
            {
              yy = func_0022A590(D_80145040, o);
              xx = D_800E0D44[D_80152789];
              func_002398F8(D_80145088, o->pawn, xx, yy, D_800C80C0);
            }
          }
          ok2 = t;
        }
        if (ok2 != 0)
        {
          if (o->unk594 == 2)
          {
            func_00214178(a, s, 0xB);
            func_0022B974(o);
          }
          else
          {
            func_00214178(a, s, 2);
          }
        }
        else
        {
          func_00214178(a, s, 2);
        }
      }
      else
      {
        func_00214178(a, s, 2);
      }
    }

    o->unk788 = 1;
    o->unk78C = 0;
  }
}
