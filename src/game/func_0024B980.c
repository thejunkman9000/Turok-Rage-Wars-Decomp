#include "p2_types.h"

extern s32 D_800D297C;
void func_0024AA08();
void func_0026DA4C(void *a, s32 b, s32 c, P2Seg *d, s32 e, s32 f);
void func_0024C444(Actor *a, ActorCmd *c);

void func_0024B980(Actor *a, s32 unused, ActorCmd *c, P2Seg *src)
{
  a->seg[D_800D297C] = *src;
  if (a->f1 != (-1))
  {
    a->f17C = 1 << a->f1;
    if (c->f4 != 0)
    {
      func_0024AA08();
    }
    if (c->f0 != 0)
    {
      if (c->fC)
      {
        func_0026DA4C(c->fC, a->fB4, 1, &a->seg[D_800D297C], 0, a->f3);
        func_0024C444(a, c);
      }
      else
      {
        func_0026DA4C(c->fC, a->fB4, 1, &a->seg[D_800D297C], 0, a->f3);
        func_0024C444(a, c);
      }
    }
  }
}