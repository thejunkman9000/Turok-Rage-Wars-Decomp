#include "b20_types.h"
Entity *func_0022A404(u8 *p);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 sqrtf(f32 x);
extern u8 D_80145040[];
Entity *func_0028C810(Level *lv)
{
  Vec3f d;
  Entity *tgt;
  Entity *best;
  Entity *e;
  s32 bestd;
  s32 dist;
  int zero;
  s32 i;
  tgt = func_0022A404(D_80145040);
  zero = 0;
  bestd = 0x98967F;
  i = zero;
  best = (Entity *)zero;
  if (lv->n2 > zero)
  {
    do
    {
      e = lv->list2[i];
      func_00271FD8(&d, &e->pos, &tgt->pos);
      dist = (s32) sqrtf(((d.x * d.x) + (d.y * d.y)) + (d.z * d.z));
      if (bestd >= dist)
      {
        best = e;
        bestd = dist;
      }
      i++;
    }
    while (i < lv->n2);
  }
  return best;
}
