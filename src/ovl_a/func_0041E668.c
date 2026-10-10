#include "o03_types.h"
typedef struct Q2Pl { u8 pad0[0x78]; u8 f78; u8 pad79[6]; u8 f7F; u8 f80; u8 f81; u8 pad82[2]; u8 name[0xD]; u8 f91; u8 f92; u8 f93; u8 pad94[2]; } Q2Pl;
typedef struct Q2Cfg { u8 pad0[0xD0]; Q2Pl pl[8]; } Q2Cfg;
extern Q2Cfg D_801462C8[];
extern u8 D_80153F80[];
void func_002A125C(void *d, void *s);
void func_0041E668(void)
{
  s32 idx;
  s32 j;
  s32 off;
  s32 one;
  Q2Pl *e;
  u8 *p;
  Q2Cfg *cfg;
  idx = 7;
  j = 0;
  one = 1;
  off = j;
  cfg = D_801462C8;
  e = &cfg->pl[7];
  top:
  if (idx <= 0)
  {
    goto done;
  }

  if ((*((s32 *) (D_80153F80 + off))) >= 0)
  {
    p = (u8 *) ((idx * 0x96) + ((s32) cfg));
    again:
    if (((Q2Cfg *) p)->pl[0].f78 != one)
    {
      goto found;
    }

    p -= 0x96;
    idx--;
    e--;
    if (idx > 0)
    {
      goto again;
    }
    found:
    if (idx >= 0)
    {
      e->f91 = one;
      e->f78 = one;
      e->f7F = idx;
      idx--;
      e->f80 = D_80153F80[off + 3];
      e->f93 = D_80153F80[off + 7];
      e->f92 = D_80153F80[off + 0xB];
      e->f81 = D_80153F80[off + 0xF];
      func_002A125C(e->name, (D_80153F80 + off) + 0x10);
      e--;
    }

  }
  j++;
  off += 0x1C;
  if (j < 3)
  {
    goto top;
  }
  done:
  return;

}
