#include "b11_types.h"

s32 func_0024DDCC(Obj *a)
{
  ObjDef *d = a->def;
  s32 t = d->type;
  if ((t == 1) || (t == 4))
  {
    return d->flags14 & 0x80;
  }
  if (a->def)
  {
    return 0;
  }
  else
  {
    return 0;
  }
}
