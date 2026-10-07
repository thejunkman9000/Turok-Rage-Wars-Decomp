#include "b14_types.h"
extern B14Mgr D_8010FC40[];
extern s32 D_80145070;
extern u8 D_8011FE88[];
extern s32 D_8013B2BC;
typedef struct { u8 pad[0x1D]; u8 f1D; } B14G2;
extern B14G2 D_801462C8[];
typedef struct { u8 pad[0x5EC]; s32 f5EC; u8 pad2[0x650 - 0x5F0]; u16 f650; } B14Pl;
s32 func_002934DC();
void func_00264D00();
B14Pl *func_0022A404(void *g);
void func_00264A40(void)
{
  s32 ok;
  B14Pl *p;
  B14Mgr *m = D_8010FC40;
  ok = func_002934DC() != 0;
  if (D_80145070 == 0)
  {
    ok = 0;
  }
  if (D_8011FE88 == ((void *) 0))
  {
    ok = 0;
  }
  if (ok != 0)
  {
 do { if (m->b != 1) { if (m->b >= 2) { m->b = 0; } else if (m->b != 0) { m->b = 0; } else { m->b = 1; } } else { m->b = 2; } } while (0);
    func_00264D00();
    m->d = D_8013B2BC;
    if (D_801462C8->f1D == 0)
    {
      p = func_0022A404(((u8 *) D_801462C8) - 0x1288);
      if (p != ((void *) 0))
      {
        if ((m->b == 1) && ((D_8013B2BC != p->f5EC) || (((u32) (p->f650 - 0x16)) < 0xC)))
        {
          m->b = 2;
        }
        m->d = p->f5EC;
      }
    }
  }
  else
  {
    m->b = 0;
  }
  if (m->b != 0)
  {
    m->c = 0xF0;
    m->a = 1;
    return;
  }
  m->c = 0;
  m->a = 0;
}
