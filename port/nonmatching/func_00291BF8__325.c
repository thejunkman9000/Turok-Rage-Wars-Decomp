#include "m05_types.h"

typedef struct M5Dl { u32 w0; u32 w1; } M5Dl;
typedef struct M5Gfx { u8 pad0[0x110]; u32 fb; } M5Gfx;

extern M5Dl *D_80110634;
extern M5Gfx *D_8011FE80;
extern s32 D_800E28D0;
extern s32 D_800E28D8;
extern s32 D_801536E8;
void func_0026925C(s32);

#define DL(a, b) { M5Dl **pp = &D_80110634; M5Dl *q = (*pp)++; q->w0 = (a); q->w1 = (b); }

void func_00291BF8(s32 unused, s32 x0, s32 x1, s32 y0, s32 y1, s32 mode)
{
  s32 i;
  {
    M5Dl **pp = &D_80110634;
    M5Dl *q = (*pp)++;
    q->w0 = 0xE7000000;
    q->w1 = 0;
  }
  ;
  func_0026925C(0x14);
  {
    M5Dl **pp = &D_80110634;
    M5Dl *q = (*pp)++;
    q->w0 = ((D_800E28D0 - 1) & 0xFFF) | 0xFF100000;
    q->w1 = D_801536E8;
  }
  ;
  {
    M5Dl **pp = &D_80110634;
    M5Dl *q = (*pp)++;
    q->w0 = 0xE7000000;
    q->w1 = 0;
  }
  ;
  {
    M5Dl **pp = &D_80110634;
    M5Dl *q = (*pp)++;
    q->w0 = 0xE3000A01;
    q->w1 = 0x300000;
  }
  ;
  if (mode == 0)
  {
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xF7000000;
      q->w1 = 0xFFFCFFFC;
    }
    ;
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = ((x1 & 0x3FF) << 14) | (((y1 & 0x3FF) * 4) | 0xF6000000);
      q->w1 = ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) * 4);
    }
    ;
  }
  else
    if (D_800E28D8 == 0)
  {
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xF7000000;
      q->w1 = 0xFFFCFFFC;
    }
    ;
    for (i = y0; i < y1; i += 2)
    {
      mode = (i & 0x3FF) * 4;
      {
        u32 w0 = mode | 0xF6000000;
        w0 |= (x1 & 0x3FF) << 14;
        {
          M5Dl **pp = &D_80110634;
          M5Dl *q = (*pp)++;
          q->w0 = w0;
          q->w1 = ((x0 & 0x3FF) << 14) | mode;
        }
        ;
      }
    }

    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xF7000000;
      q->w1 = 0;
    }
    ;
    for (i = y0 + 1; i < y1; i += 2)
    {
      mode = (i & 0x3FF) * 4;
      {
        u32 w0 = mode | 0xF6000000;
        w0 |= (x1 & 0x3FF) << 14;
        {
          M5Dl **pp = &D_80110634;
          M5Dl *q = (*pp)++;
          q->w0 = w0;
          q->w1 = ((x0 & 0x3FF) << 14) | mode;
        }
        ;
      }
    }

  }
  else
  {
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xF7000000;
      q->w1 = 0xFFFCFFFC;
    }
    ;
    for (i = y0; i < y1; i++)
    {
      if ((i & 3) < 2)
      {
        mode = (i & 0x3FF) * 4;
        {
          u32 w0 = mode | 0xF6000000;
          w0 |= (x1 & 0x3FF) << 14;
          {
            M5Dl **pp = &D_80110634;
            M5Dl *q = (*pp)++;
            q->w0 = w0;
            q->w1 = ((x0 & 0x3FF) << 14) | mode;
          }
          ;
        }
      }
    }

    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xF7000000;
      q->w1 = 0;
    }
    ;
    for (i = y0; i < y1; i++)
    {
      if ((i & 3) >= 2)
      {
        mode = (i & 0x3FF) * 4;
        {
          u32 w0 = mode | 0xF6000000;
          w0 |= (x1 & 0x3FF) << 14;
          {
            M5Dl **pp = &D_80110634;
            M5Dl *q = (*pp)++;
            q->w0 = w0;
            q->w1 = ((x0 & 0x3FF) << 14) | mode;
          }
          ;
        }
      }
    }

  }
  {
    M5Dl **pp = &D_80110634;
    M5Dl *q = (*pp)++;
    q->w0 = ((D_800E28D0 - 1) & 0xFFF) | 0xFF100000;
    q->w1 = D_8011FE80->fb;
  }
  ;
  {
    M5Dl **pp = &D_80110634;
    M5Dl *q = (*pp)++;
    q->w0 = 0xE7000000;
    q->w1 = 0;
  }
  ;
  {
    M5Dl **pp = &D_80110634;
    M5Dl *q = (*pp)++;
    q->w0 = 0xE3000A01;
    q->w1 = 0x100000;
  }
  ;
}
