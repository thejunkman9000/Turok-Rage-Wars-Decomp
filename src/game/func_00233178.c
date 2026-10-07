#include "b07_types.h"
extern s32 D_801450B8;
void func_00273A34(Actor *actor, f32 v);
void func_00233178(Actor *actor, u8 *obj)
{
  u8 *new_var2;
  f32 v = *((f32 *) (((u8 *) (*((u8 **) (((u8 *) obj) + 0x8)))) + 0x294));
  f32 new_var;
  u8 *new_var3;
  new_var2 = (u8 *) obj;
  if (D_801450B8 == 1)
  {
    new_var3 = new_var2 + 0x4;
    switch (*((s32 *) new_var3))
    {
      case 1:
        func_00273A34(actor, -v);
        break;
        break;

      case 2:
        new_var = v;
        func_00273A34(actor, v + new_var);

    }

  }
  else
  {
    switch (*((s32 *) (((u8 *) obj) + 0x4)))
    {
      case 0:
        v = -v;
        new_var = v;
        func_00273A34(actor, new_var + new_var);
        break;

    }

  }
}
