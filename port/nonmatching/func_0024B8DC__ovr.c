/* port (passthru_fix.py): func_0024AA08 needs a0 a1 a2 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "p2_types.h"
extern s32 D_800D297C;
extern u32 D_800D297C_u;
void func_0024AA08();
void func_0026DA4C(void *a, s32 b, s32 c, P2Seg *d, s32 e, s32 f);
void func_0024C444(Actor *a, ActorCmd *c);

void func_0024B8DC(Actor *a, s32 unused, ActorCmd *c)
{
  unsigned int new_var2;
  ActorCmd *new_var;
  if (a->f1 != (-(new_var2 = 1)))
  {
    a->f17C = 1 << a->f1;
    if (c->f4 != 0)
    {
      func_0024AA08(a, unused, c);
    }
    new_var = c;
    if (new_var->f0 != 0)
    {
      if (c->f4)
      {
        func_0026DA4C(c->fC, a->fB4, 1, a->seg + D_800D297C, 0, a->f3);
        func_0024C444(a, c);
      }
      else
      {
        func_0026DA4C(c->fC, a->fB4, 1, a->seg + D_800D297C, 0, a->f3);
        func_0024C444(a, c);
      }
    }
  }
}
