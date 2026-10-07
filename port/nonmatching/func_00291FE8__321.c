#include "m05_types.h"

typedef struct M5Dl { u32 w0; u32 w1; } M5Dl;
typedef struct M5Gfx { u8 pad0[0x110]; u32 fb; } M5Gfx;

extern M5Dl *D_80110634;
extern M5Gfx *D_8011FE80;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_8013B878[];

void func_00291BF8(s32, s32, s32, s32, s32, s32);
void func_002A94E8();
void func_002ABB2C(s32, s32, s32, s32, s32, s32);
void func_002ABB58(f32, f32);
void func_002A9F18(char *, s32, s32, s32, s32, s32, f32, f32);

#define DL(a, b) { M5Dl **pp = &D_80110634; M5Dl *q = (*pp)++; q->w0 = (a); q->w1 = (b); }

void func_00291FE8(s32 unused, s32 bg, char **names, s32 x, s32 y, s32 lineh, f32 sx, f32 sy)
{
  M5Gfx *g = D_8011FE80;
  char **p;
  char *new_var;
  int new_var2;
  f32 s;
  y = (y * D_800E28D4) / 222;
  if (((long long) bg) != 0)
  {
    func_00291BF8(0, 0, D_800E28D0, 0, D_800E28D4, 0);
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xED000000;
      q->w1 = ((((s32) (((f32) (D_800E28D0 - 1)) * 4.0f)) & 0xFFF) << 12) | (((s32) (((f32) (D_800E28D4 - 1)) * 4.0f)) & 0xFFF);
    }
    ;
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = ((D_800E28D0 - 1) & 0xFFF) | 0xFF100000;
      q->w1 = g->fb;
    }
    ;
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xE3000A01;
      q->w1 = 0x300000;
    }
    ;
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xFCFFFFFF;
      q->w1 = 0xFFFE793C;
    }
    ;
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xE200001C;
      q->w1 = 0;
    }
    ;
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      q->w0 = 0xF7000000;
      q->w1 = 0x10001;
    }
    ;
    {
      M5Dl **pp = &D_80110634;
      M5Dl *q = (*pp)++;
      new_var2 = 0xF6000000;
      q->w0 = ((D_800E28D0 & 0x3FF) << 14) | (((D_800E28D4 & 0x3FF) * 4) | new_var2);
      q->w1 = 0;
    }
    ;
  }
  func_002A94E8();
  s = 0xFF;
  func_002ABB2C(0xFF, 0xFF, s, 0xC8, 0xC8, 0xC8);
  sx = (sx * ((f32) D_800E28D0)) * 0.0035211267f;
  sy = (sy * ((f32) D_800E28D4)) * 0.0045045046f;
  sx = sx * ((D_800E28D4 >= 0xDF) ? (0.8f) : (0.85f));
  sy = sy * 0.5f;
  func_002ABB58(sx, sy);
  D_8013B878[0] = 1;
  D_8013B878[1] = 1;
  if ((*names) != 0)
  {
    sx = 1.0f;
    p = names;
    do
    {
      new_var = *p;
      func_002A9F18(new_var, x, y, 0xFF, 1, 1, sx, sx);
      p++;
      y = (s32) (((f32) y) + (((f32) lineh) * sy));
    }
    while ((*p) != 0);
  }
}
