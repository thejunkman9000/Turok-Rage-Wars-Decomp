#include "o05_types.h"
extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];
s32 func_004353C0(void);
void func_002A1724(void *dst, void *src, s32 n);
void func_00433DA8(s32 a);

s32 func_00434B58(s32 k)
{
  s32 r = 0;
  s32 sel = D_800E54A4->plr[k].fAEC;
  s32 found;
  s32 idx;
  s32 i;
  s32 v;
  if (D_800E54A4->plr[k].tabAF0[sel] == 1)
  {
    found = -1;
    for (i = 0; i < 4; i++)
    {
      if (found != (-1))
      {
        break;
      }
      if (D_800E54A4->slot[i].a == (-1))
      {
        found = i;
      }
    }

    idx = found;
    if (idx >= 0)
    {
      v = func_004353C0();
      if (v >= 0)
      {
        D_800E54A4->slot[v].a = 0;
        D_800E54A4->slot[v].b = idx;
        D_800E54A4->slot[v].c = 1;
      }
      func_002A1724(&D_80102B00[found], &D_800E54A4->plr[k].rec[sel], 0x190);
      (*(&D_80102B00[found])).bD = k;
      D_800E54A4->plr[k].f4 = 0;
      func_00433DA8(idx = -1);
      r = 1;
    }
  }
  return r;
}
