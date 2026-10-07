#include "b07_types.h"
extern u8 *D_800D052C[];
s32 func_0022E8C0(s16 idx, s32 kind)
{
  switch (kind)
  {
    case 0:
      if ((*((u32 *) (((u8 *) D_800D052C[idx]) + 0x14))) & 1)
    {
      return 1;
    }
      break;

    case 1:
      if ((*((u32 *) (((u8 *) D_800D052C[idx]) + 0x14))) & 2)
    {
      return 1;
    }
      break;

    return 0;
    default:

  }

  return 0;
}
