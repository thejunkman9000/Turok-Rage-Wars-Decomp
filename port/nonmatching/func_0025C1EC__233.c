#include "b13_types.h"

typedef struct CurveTab { f32 unk0; f32 tab[1]; } CurveTab;

extern f32 D_800C907C;
extern f32 D_800C9080;
extern CurveTab D_800D0B28;

f32 func_0025C1EC(f32 x)
{
  f32 t;
  s32 n;
  int new_var;
  s16 i;
  f32 new_var2;
  f32 r;
  x += D_800C907C;
  t = x * D_800C9080;
  n = (s32) t;
  i = n;
  if (((f32) i) == t)
  {
    r = D_800D0B28.tab[i];
  }
  else
  {
    new_var = n;
    new_var = new_var + 1;
    new_var2 = D_800D0B28.tab[i = i];
    t = (t - ((f32) i)) * (D_800D0B28.tab[(s16) new_var] - new_var2);
    r = D_800D0B28.tab[i] + t;
  }
  return r;
}

