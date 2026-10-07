#include "b12_types.h"

extern s32 D_800D2640;
extern u8 D_800D297B;
extern s32 D_800D15E0;
extern f32 D_800D15F0;
extern u8 D_800C8F30[];
s32 func_00250754(B12Obj *o, s32 a1);
s32 func_00250BD4(B12Obj *o, s32 **b);
B12Node *func_00251F0C(s32 a, s32 b, s32 c, s32 d, s32 e, B12Obj *o, void *fn, void *p, s32 i);
void func_00253B5C(s32 a, B12Node *n);
void func_002536F4(s32 a, void *n);
void func_0027899C(void *a, void *b);
void func_0026DA4C(s32 h, void *a, s32 b, s32 c, void *d, s32 e);
void func_0026DC24(s32 h, void *a, s32 b, s32 c, void *d, s32 e);
void func_0025021C(B12Obj *o)
{
  s32 h;
  s32 s4;
  s32 a1;
  s32 e;
  f32 f;
  B12Node *r;
  s32 *blk;
  u8 *data;
  u8 *v1;
  s32 off;
  u8 *src;
  s32 len;
  if (!(o->unkD8 & 0x40))
  {
    B12Def *d = o->def;
    s4 = d->unk12;
    if (o->unkDC >= (d->unk24 * 2))
    {
      e = d->unkF;
    }
    else
    {
      e = d->unkE;
    }
    a1 = e;
    if (a1 == (-1))
    {
 do { if (o->unkE0 <= 0) { return; } D_800D15E0 = 1; D_800D15F0 = (f32) (o->unkE0 << 5); } while (0);
      a1 = o->def->unkE;
    }
    else
    {
      if (o->unkE0 < 8)
      {
        D_800D15E0 = 1;
        f = (f32) (o->unkE0 << 5);
      }
      else
      {
        f = 255.0f;
        D_800D15E0 = 0;
      }
      D_800D15F0 = f;
    }
    h = func_00250754(o, a1);
    if (h)
    {
      r = func_00251F0C(0, o->unkD0 | D_800D2640, h, (s32) o->unk20, 8, o, (void *) func_00250BD4, D_800C8F30, 0);
      if (r)
      {
        func_00253B5C(0, r);
        blk = (s32 *) r->key;
        if (blk[0] == 1)
        {
          off = blk[1];
          len = blk[2];
          data = ((u8 *) blk) + off;
          src = ((u8 *) blk) + len;
          if (o->unkDA != D_800D297B)
          {
            func_0027899C(data, src);
          }
          v1 = data;
        }
        else
        {
          v1 = ((u8 *) blk) + 8;
        }
        if (D_800D15E0)
        {
          func_0026DA4C(h, o->unk28, 0, 0, v1, s4);
        }
        else
        {
          func_0026DC24(h, o->unk28, 0, 0, v1, s4);
        }
        func_002536F4(0, r);
      }
      func_002536F4(0, (void *) h);
      o->unkDA = D_800D297B;
    }
    D_800D15E0 = 0;
    D_800D15F0 = 255.0f;
  }
}
