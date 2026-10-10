#include "b13_types.h"
#include "m04_types.h"

typedef struct M04Node2 {
    s32 stride;
    u32 cnt;
} M04Node2;

extern f32 D_800C8FCC;
s32 func_00257BD4(SndMgr *m, void *info, M04Vec3 *pos, s32 a3, s32 a4, s32 a5, s32 a6);
s32 func_00265570(void *a, s32 b, s16 id, s32 *lo, s32 *hi);
s32 func_00274544();
f32 func_002745D4(f32 x);
void *func_0028FD94(void *n, s32 i);

s32 func_00257DF4(SndMgr *m, s32 id, M04Vec3 pos, s32 a5, s32 a6)
{
  s32 i;
  s32 i1;
  s32 cnt;
  s32 c6;
  s32 j;
  s32 j2;
  s16 last;
  s32 busy;
  s32 idx;
  s32 sum;
  s32 r;
  s32 lo;
  s32 hi;
  s32 lo2;
  s32 hi2;
  s32 ok;
  s32 w;
  s32 n;
  s32 s0;
  s32 ret;
  s32 sh;
  u8 *vp;
  M04Node2 *nd;
  if (m->unk102 != (-1))
  {
    busy = 1;
    goto chk;
  }
  c6 = 0;
  if (id < 0x100)
  {
    for (i1 = 0; i1 < 17; i1++)
    {
      if ((*((s32 *) ((((u8 *) m) + (i1 * 0xCC)) + 0x1E64))) == id)
      {
        c6++;
      }
    }

    busy = 1;
    if (c6 >= 6)
    {
      goto chk;
    }
  }
  busy = 0;
  chk:
  if (busy != 0)
  {
    return -1;
  }

  if (id < 0x100)
  {
    last = *((u16 *) (((u8 *) m) + 0x132));
    sum = 0;
    if (m->unk2B54 != 0)
    {
      if (func_00265570(m->unk2B58, m->unk2B54, id, &lo, &hi) != 0)
      {
        i = lo;
        if (i != hi)
        {
          for (j = lo; j <= hi; j++)
          {
            sum += m->unk2B5C[j] * 10;
          }

          r = func_00274544() % sum;
          sum = 0;
          for (i = lo; i < hi; i++)
          {
            sum += m->unk2B5C[i] * 10;
            if (sum >= r)
            {
              break;
            }
          }

          if ((((s16) last) != 0) && (i == m->unk130))
          {
            if (i == hi)
            {
              i = i - 1;
            }
            else
            {
              i = i + 1;
            }
          }
        }
        idx = i;
      }
      else
      {
        idx = -1;
      }
    }
    else
    {
      idx = -1;
    }
    m->unk2B94 = (s32) func_002745D4(D_800C8FCC);
  }
  else
  {
    sum = 0;
    if (m->unk2B54 != 0)
    {
      if (func_00265570(m->unk2B58, m->unk2B54, id, &lo2, &hi2) != 0)
      {
        i = lo2;
        if (i != hi2)
        {
          for (j2 = lo2; j2 <= hi2; j2++)
          {
            sum += m->unk2B5C[j2] * 10;
          }

          r = func_00274544() % sum;
          sum = 0;
          for (i = lo2; i < hi2; i++)
          {
            sum += m->unk2B5C[i] * 10;
            if (sum >= r)
            {
              break;
            }
          }

        }
        idx = i;
      }
      else
      {
        idx = -1;
      }
    }
    else
    {
      idx = -1;
    }
  }
  if (idx == (-1))
  {
    return -1;
  }
  sh = (s16) idx;
  m->unk2B88 = func_0028FD94(func_0028FD94(m->tree2B4C, sh), 0);
  m->unk2B8C = id;
  m->unk2B90 = a6;
  nd = (M04Node2 *) func_0028FD94(func_0028FD94(m->tree2B4C, sh), 1);
  cnt = nd->cnt;
  if (cnt != 0)
  {
    SndMgr_Lock(m);
    ret = (m->unk10C = m->unk10C + 1);
    SndMgr_Unlock(m);
    if (id < 0x100)
    {
      m->unk130 = idx;
    }
  }
  else
  {
    ret = -1;
  }
  s0 = 0;
  if (cnt != 0)
  {
    do
    {
      func_00257BD4(m, ((u8 *) nd) + ((s0 * nd->stride) + 8), &pos, idx, ret, 0, a5);
      s0++;
    }
    while (((u32) s0) < ((u32) cnt));
  }
  m->unk2B90 = -1;
  return ret;
}