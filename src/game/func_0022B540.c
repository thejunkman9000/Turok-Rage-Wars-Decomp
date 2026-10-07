#include "b06_types.h"

extern f32 D_800C7E00;
void func_0022B540(Plr *a, f32 x, f32 y, s32 c, s32 d)
{
  s32 i;
  PlrEnt *e;
  for (i = 0; i < 5; i++)
  {
    if (x)
    {
      e = &a->ent[i];
    }
    else
    {
      e = &a->ent[i];
    }
    if (e->unk4 <= 0.0f)
    {
      e->unk8 = c;
      e->unkC = x;
      e->unk10 = 0.0f;
      e->unk14 = d;
      e->unk4 = y * D_800C7E00;
      e->unk0 = x / e->unk4;
      return;
    }
  }

}
