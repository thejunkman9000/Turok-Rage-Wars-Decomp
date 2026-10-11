#include "b09_types.h"

f32 sqrtf(f32);
void func_00271FD8(f32 *, void *, void *);
void func_0027200C(f32 *, f32 *, f32);

f32 func_00241830(B09V3 *a, B09V3 *b, B09V3 *p)
{
  f32 dp[3];
  f32 ds[3];
  f32 t;
  f32 len2;
  func_00271FD8(dp, p, a);
  func_00271FD8(ds, b, a);
  t = ((ds[0] * dp[0]) + (ds[1] * dp[1])) + (ds[2] * dp[2]);
  if (!(t < 0.0f))
  {
    len2 = ((ds[0] * ds[0]) + (ds[1] * ds[1])) + (ds[2] * ds[2]);
    if (!(len2 <= t))
    {
      func_0027200C(ds, ds, t / len2);
    }
    func_00271FD8(dp, dp, ds);
  }
  t = sqrtf(((dp[0] * dp[0]) + (dp[1] * dp[1])) + (dp[2] * dp[2]));
  return t;
}
