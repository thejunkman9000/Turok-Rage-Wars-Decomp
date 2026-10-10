#include "o03_types.h"
extern O3Row D_800E3A50[];
extern O3Pj *D_800E42D0;
extern u8 D_80102B57[];
s32 func_00274544();
s32 func_0040EC50(s32 a);
s32 func_0040ECB0(s32 p, s32 id);
s32 func_0041F1FC(s32 key);
s32 func_0041F248(s32 key);
void func_0041CB48(void *o, s32 a, s32 b, s32 c, s32 d, O3Vec3 v, O3V3i w, f32 f, s32 g);
static inline O3Pj *pj(s32 i) { return &D_800E42D0[i]; }
void func_004208C0(s32 idx)
{
  s32 id;
  s32 tries;
  s32 done;
  s32 ch;
  s32 row;
  O3Vec3 v;
  s32 n;
  tries = 0;
  done = 0;
  do
  {
    id = D_800E3A50[func_00274544() % 17].f0;
    if ((func_0040EC50(func_0040ECB0(D_800E42D0->f0, id & 0xFFFF)) != 0) || (pj(idx)->f10 == id))
    {
      tries++;
      if (tries >= 0x1389)
      {
        id = 0x92;
        done = 1;
      }
    }
    else
    {
      done = 1;
    }
  }
  while (done == 0);
  pj(idx)->f10 = id;
  ch = func_0041F248(id);
  row = func_0041F1FC(pj(idx)->f10);
  v.x = D_800E3A50[row].fC[idx];
  v.y = D_800E3A50[row].fC[idx];
  v.z = D_800E3A50[row].fC[idx];
  func_0041CB48(((O3Pj *) ((idx * 0x4C8) + ((s32) D_800E42D0)))->sub, 9, ch + 0x38F, 0x4B, 0x5DC0, v, D_800E3A50[row].v2C[idx], D_800E3A50[row].f1C[idx], D_800E3A50[row].f5C[idx]);
  n = D_80102B57[ch + (idx * 0x190)];
  if (n <= 0)
  {
    n = 1;
  }
  ((O3Pj *) (((u8 *) D_800E42D0) - (-(idx * 0x4C8))))->f18 = func_00274544() % n;
}
