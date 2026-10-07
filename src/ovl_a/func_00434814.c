#include "o05_types.h"

extern O05Lobby *D_800E54A4;
s32 func_00404F58(s32 idx, s32 a, void *buf, s32 n);
s32 func_004057F8(void *p, s32 a, s32 b);
void func_002A1724(void *dst, void *src, s32 n);
void func_00404858(s32 idx, s32 a);

s32 func_00434814(s32 idx, s32 a)
{
  s32 ok = 0;
  O05Rec *buf = D_800E54A4->recs;
  if ((func_00404F58(idx, a, buf, 0x648) == 0) && (func_004057F8(buf, 0x640, 7) == ((s32 *) buf)[0x644 / 4]))
  {
    func_002A1724(D_800E54A4->plr[idx].rec, D_800E54A4->recs, 0x640);
    D_800E54A4->plr[idx].fB64 = D_800E54A4->f3468;
    ok = 1;
  }
  else
    if (D_800E54A4->f3468)
  {
    func_00404858(idx, a);
  }
  else
  {
    func_00404858(idx, a);
  }
  if (ok == 0)
  {
    D_800E54A4->plr[idx].f14 = 2;
    D_800E54A4->plr[idx].state = 2;
  }
  return ok;
}
