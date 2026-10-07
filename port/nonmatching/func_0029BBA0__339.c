#include "b22_types.h"
extern double D_800CA850;
#define HI(x) (((u32 *)&(x))[0])
#define LO(x) (((u32 *)&(x))[1])
double func_0029BBA0(double x, s32 n);
double func_0029BBA0(double x, s32 n)
{
  u32 hx;
  u32 k;
  u32 t;
  u32 s;
  u32 v0;
  u32 v1;
  double h;
  u32 *p;
  hx = ((u32 *) (&x))[0];
  p = (u32 *) (&x);
  k = hx >> 20;
  k = k & 0x7FF;
  if (k != 0)
  {
    if (k < 0x7FF)
    {
      k += n;
      if (k != 0)
      {
        if (k < 0x7FF)
        {
          v1 = hx;
          v1 = v1 & 0x800FFFFF;
          v0 = (k & 0x7FF) << 20;
          goto join;
        }
        if (n >= 0)
        {
          overflow:
          t = p[0];

          s = t;
          t = t & 0x7FFFFFFF;
          h = D_800CA850;
          x = h;
          p[0] = t | ((s >> 31) << 31);
          return h;
        }
        if (k < ((u32) (-0x35)))
        {
          x = 0.0;
          v1 = ((u32 *) (&x))[0];
          v1 = v1 & 0x7FFFFFFF;
          goto sign;
        }
      }
      k = k - 1;
      p[0] = (p[0] & 0x800FFFFF) | 0x100000;
      x = x * func_0029BBA0(1.0, k);
      return x;
    }
    if (((hx & 0xFFFFF) != 0) || (((u32 *) (&x))[1] != 0))
    {
      goto ret;
    }
    if (n >= 0)
    {
      goto overflow;
    }
    v1 = 0x7FFFFFFF;
    v1 = hx & v1;
    sign:
    v0 = (hx >> 31) << 31;

    join:
    ((u32 *) (&x))[0] = v1 | v0;

    ret:
    return x;

  }
  if (((hx & 0xFFFFF) == 0) && (((u32 *) (&x))[1] == 0))
  {
    return x;
  }
  return func_0029BBA0(x * func_0029BBA0(1.0, 0x35), n - 0x35);
}
