#include "b07_types.h"
extern B07Game D_801468A0[];
void func_0022E16C(Actor *a, Actor *b, s32 kind)
{
  register s32 *p1 asm("$4");
  s32 *p2;
  s32 x;
  s32 y;
  s32 xs;
  register s32 *t1 asm("$2");
  if (D_801468A0->unk24 == 0)
  {
    return;
  }
  x = a->stats->unk92;
  y = b->stats->unk92;
  if (x < 0)
  {
    return;
  }
  if (x >= 5)
  {
    return;
  }
  xs = x * 4;
  t1 = D_801468A0->cnt2C;
  p1 = (s32 *)((u8 *)t1 + xs);
  p2 = D_801468A0->cnt40 + x;
  switch (kind)
  {
    case 0:
      if (D_801468A0->unk78 == 0)
    {
      if (D_801468A0->unk54 == 0)
      {
        if (y)
        {
          goto dec;
        }
        else
        {
          goto dec;
        }
      }
    }
      break;

    case 1:
      if (y == x)
    {
      break;
    }
      inc:
    *p1 = (*p1) + 1;

      break;

    case 3:
      *p2 += 1;
      break;

    case 2:
      if (y != x)
    {
      goto inc;
    }
      dec:
    *p1 -= 1;

      break;

  }

}
