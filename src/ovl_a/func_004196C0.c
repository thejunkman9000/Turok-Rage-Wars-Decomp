#include "o03_types.h"
void func_00413500(void);
s32 func_0041371C(s32 a);
s32 func_00413728(s32 a);
void func_00419510(s32 a);
s32 func_004196C0(s32 a, s32 b)
{
  s32 m;
  s32 new_var;
  s32 r;
  if (a != b)
  {
    if (a || b)
    {
      func_00413500();
    }
    else
    {
      func_00413500();
    }
  }
  b = a;
  new_var = func_0041371C(b);
  r = func_00413728(b);
  a = new_var;
  m = r;
  r = 0;
  if (a > 0)
  {
    r = m > 0x800;
  }
  if ((a == 0) && (m > 0x1000))
  {
    r = 1;
  }
  if (r != 0)
  {
    func_00419510(b);
  }
  return 0;
}
