#include "b06_types.h"

extern u8 *D_800D052C[];
s32 func_0022AB10(Plr *a, s32 i)
{
  u8 *t;
  s16 *p;
  s32 idx;
  s32 f;
  if (i == 1)
  {
    if (a->unk604 != 0)
    {
      return -1;
    }
  }
  t = D_800D052C[i];
  f = a->unk594;
  if (f == 1)
  {
    p = *((s16 **) (((u8 *) t) + 0x20));
  }
  else
  {
    p = *((s16 **) (((u8 *) t) + 0x24));
  }
  idx = -1;
  if (p != ((void *) 0))
  {
    idx = *p;
  }
  if (idx != (-1))
  {
    return a->unk5F4[idx];
  }
  return -1;
}
