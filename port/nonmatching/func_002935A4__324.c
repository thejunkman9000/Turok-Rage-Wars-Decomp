#include "b21_types.h"

extern f32 D_800D2988;

void func_002935A4(B21Game *g)
{
  f32 speed;
  f32 kk;
  if (g->unk26DC1 != 0)
  {
    speed = 0.1f;
    if (g->unk26DC0 != 0)
    {
      if (g || D_800D2988)
      {
        speed = 0.5f;
      }
      else
      {
        speed = 0.5f;
      }
    }
    kk = speed;
    if (g->unk26DC1 != 1)
    {
      if (g->unk26DC1 == 2)
      {
        if (0.0f < g->unk26DC4)
        {
          g->unk26DC4 = g->unk26DC4 - (kk * D_800D2988);
          if (g->unk26DC4 < 0.0f)
          {
            g->unk26DC4 = 0.0f;
          }
        }
        else
        {
          g->unk26DC4 = g->unk26DC4 - 1.0f;
        }
        if (g->unk26DC4 < (-4.0f))
        {
          s32 old = g->unk26DB8;
          g->unk26DB8 = 0x14;
          g->unk26DC4 = 0.0f;
          g->unk26DC1 = 1;
          g->unk26DB4 = old;
        }
      }
    }
    else
    {
      g->unk26DC4 = g->unk26DC4 + (speed * ((D_800D2988 < 0.5f) ? (0.5f) : (D_800D2988)));
      if (1.0f <= g->unk26DC4)
      {
        g->unk26DC1 = 0;
        g->unk26DC4 = 1.0f;
        g->unk26DC0 = 0;
      }
    }
  }
}
