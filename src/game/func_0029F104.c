#include "span_1000/code_8029EB74.h"
#include "span_C76B0/data.h"

#include "types.h"
/* Normalizes an offset angle, using double remainder for large magnitudes and repeated single-precision adjustments otherwise. */

extern f64 func_8029B278_de(f64 arg0, f64 arg1);
inline static f32 wrap(f32 arg0)
{
  f32 new_var3;
  f32 value;
  
  f32 new_var2;
  value = arg0;
  new_var2 = value;
  if (1)
  {
    if (((long long) (D_800C5C64 < new_var2)) || (new_var2 < D_800C5C68_de))
    {
      value = (f32) func_8029B278_de((f64) value, D_800C5C70_de);
    }
    else
    {
      if (D_800C5C78_de < value)
      {
        new_var3 = D_800C5C78_de;
        do
        {
          value -= new_var3;
          if (1)
          {
          }
        }
        while (new_var3 < value);
      }
      if (value < 0.0f)
      {
        do
        {
          value += D_800C5C7C;
        }
        while (value < (new_var3 = 0.0f));
      }
    }
  }
  return value;
}

f32 func_8029E104_de(f32 x)
{
  f32 new_var;
  float new_var3;
  f32 new_var2;
  new_var = D_800C5C60_de;
  new_var2 = x + new_var;
  {
    new_var3 = new_var2;
  }
  new_var2 = wrap(new_var3);
  return new_var2 - D_800C5C80_de;
}
