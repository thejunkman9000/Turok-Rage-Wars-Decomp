#include "s703_types.h"
extern S7Vtx D_80110160[];
extern s32 D_80110560;
extern S7Gfx *D_80110634;
extern u8 D_8013B1A8[];
S7Lt *func_00268CBC(void *l);
S7Lt *func_00268CC8(void *l, S7Lt *n);
void func_00272908(void *m, S7Vec3 *v, S7Vec3 *o);
void func_00265A00(u8 *mtx)
{
  S7Lt *n;
  S7LtDef *def;
  S7Vec3 v;
  S7Vec3 o;
  s32 i;
  s32 tx;
  s32 ty;
  s32 tz;
  n = func_00268CBC(D_8013B1A8);
  if (n == 0)
  {
    {
      S7Gfx **pp = &D_80110634;
      S7Gfx *d = (*pp)++;
      d->w0 = 0xD9FFFF7F;
      d->w1 = 0;
    }
    D_80110560 += 8;
    return;
  }
  {
    S7Gfx **pp = &D_80110634;
    S7Gfx *d = (*pp)++;
    d->w0 = 0xD9FFFFFF;
    d->w1 = 0x80;
  }
  for (i = 0; i < 8; i++)
  {
    if ((n != 0) && (n->on != 0))
    {
      def = n->def;
      v.x = n->x;
      v.y = n->y;
      v.z = n->z;
      func_00272908(mtx + 0x220, &v, &o);
      tz = -((s32) o.z);
      ty = (s32) o.y;
      tx = -((s32) o.x);
      D_80110160[i + D_80110560].x = -((s32) o.x);
      D_80110160[i + D_80110560].y = ty;
      D_80110160[i + D_80110560].z = tz;
      D_80110160[i + D_80110560].c9 = (u32) (((f32) def->b7) * n->k);
      D_80110160[i + D_80110560].c8 = (u32) (((f32) def->b4) * n->k);
      D_80110160[i + D_80110560].c7 = (u32) (((f32) def->b5) * n->k);
      D_80110160[i + D_80110560].c6 = (u32) (((f32) def->b6) * n->k);
      D_80110160[i + D_80110560].wA = def->w0;
      D_80110160[i + D_80110560].wC = def->w2;
      D_80110160[i + D_80110560].wE = 0x7F80;
    }
    else
    {
      D_80110160[i + D_80110560].wA = -0x8000;
    }
    if (n != 0)
    {
      n = func_00268CC8(D_8013B1A8, n);
    }
    {
      S7Gfx **pp = &D_80110634;
      S7Gfx *d = (*pp)++;
      d->w0 = (((((i + 1) * 2) + 0xA) & 0xFF) << 8) | 0xDC08000A;
      d->w1 = (u32) (&D_80110160[i + D_80110560]);
    }
  }

  D_80110560 += 8;
}
