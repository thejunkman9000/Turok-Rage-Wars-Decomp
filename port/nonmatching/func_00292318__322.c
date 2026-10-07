#include "r07_types.h"

extern R07Slot *D_8014AD98;
extern R07Slot *D_8011FE80;
extern s32 D_800D297C;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800E28E0;
extern DlCmd *D_80110634;
extern u32 D_800D2AD4;
extern s32 D_80146968;
extern OSMesgQueue D_80146980;
extern f32 D_800D29A8;
extern f32 D_800D2988;
extern void (*D_800D29E0[][3])(B21Game *);

void func_0025398C(s32 a, s32 b, R07Slot *c);
void func_00296FF8(void);
void func_0026D844(void);
void func_002917E8(B21Game *g);
void func_00265DF0(void);
void func_00263C44(void);
void func_00236864(void *p);
void func_0029324C(B21Game *g);
void func_00293100(B21Game *g, u8 *col, s32 a, s32 b, s32 c, s32 d);
void func_40C11C(void);
void func_00291BF8(B21Game *g, s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_00253A74(s32 a);
void func_0029193C(B21Game *g, R07Slot *s, s32 a);
void func_002450BC(void);

#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_00292318(B21Game *g)
{
  u64 t0;
  u64 us;
  u8 col[4];
  s32 v;
  f32 t;
  f32 k;
  u32 len;
  u32 mx;
  t0 = osGetTime();
  func_0025398C(0, D_800D297C, D_8014AD98 = D_8011FE80);
  func_00296FF8();
  func_0026D844();
  func_002917E8(g);
  func_00265DF0();
  func_00263C44();
  func_00236864(g->sub255C8);
  func_0029324C(g);
  if (D_800D29E0[g->unk26DB8][0] != 0)
  {
    D_800D29E0[g->unk26DB8][0](g);
  }
  if (D_8014AD98->unk128 == 0)
  {
    col[0] = 0;
    col[2] = (col[1] = 0);
    t = g->unk26DC4;
    if (t < 0.0f)
    {
      goto c255;
    }
    if (1.0f < t)
    {
      v = 0;
      goto done;
    }
    if (t < 0.0f)
    {
      c255:
      v = 255;

    }
    else
    {
      v = ~((s32) (t * 255.0f));
    }
    done:
    ;

    ;
    col[3] = v;
    func_00293100(g, col, 0, 0, D_800E28D0, D_800E28D4);
  }
  if (D_800E28E0 != 0)
  {
    if (D_800E28E0 == 0x14)
    {
      func_40C11C();
    }
    func_00291BF8(g, 0, 0x1E0, 0, 0x168, 0);
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xED000000;
      _g->w1 = 0x77C59C;
    }
    ;
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xFF1001DF;
      _g->w1 = D_8014AD98->unk110;
    }
    ;
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xE3000A01;
      _g->w1 = 0x300000;
    }
    ;
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xFCFFFFFF;
      _g->w1 = 0xFFFE793C;
    }
    ;
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xE200001C;
      _g->w1 = 0;
    }
    ;
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xF7000000;
      _g->w1 = 0x10001;
    }
    ;
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xF67805A0;
      _g->w1 = 0;
    }
    ;
    D_800E28E0--;
  }
  {
    DlCmd *_g = D_80110634++;
    _g->w0 = 0xE9000000;
    _g->w1 = 0;
  }
  ;
  {
    DlCmd *_g = D_80110634++;
    _g->w0 = 0xDF000000;
    _g->w1 = 0;
  }
  ;
  len = ((u32) D_80110634) - D_8014AD98->unk114;
  D_8014AD98->unk11C = len;
  mx = D_800D2AD4;
  if (mx < len)
  {
    mx = len;
  }
  D_800D2AD4 = mx;
  D_8014AD98->unk128 = 0;
  D_8014AD98->unk124 = D_80146968;
  us = ((osGetTime() - t0) * 64) / 3;
  D_800D29A8 = ((f32) us) * 0.000001f;
  if (func_00253A74(0) != 0)
  {
    func_0029193C(g, D_8014AD98, 1);
  }
  else
  {
    osSendMesg(&D_80146980, (OSMesg) (((u8 *) D_8014AD98) + 0xF0), 1);
  }
  if (g->unk26DC1 != 0)
  {
    k = 0.1f;
    if (g->unk26DC0 != 0)
    {
      k = 0.5f;
    }
    switch (g->unk26DC1)
    {
      case 2:
        if (0.0f < g->unk26DC4)
      {
        g->unk26DC4 = g->unk26DC4 - (k * D_800D2988);
 do { if (g->unk26DC4 < 0.0f) { g->unk26DC4 = 0.0f; } } while (0);
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
        break;

      case 1:
        g->unk26DC4 = g->unk26DC4 + (k * ((D_800D2988 < 0.5f) ? (0.5f) : (D_800D2988)));
        if (1.0f <= g->unk26DC4)
      {
        g->unk26DC1 = 0;
        g->unk26DC4 = 1.0f;
        g->unk26DC0 = 0;
      }
        break;

    }

  }
  func_002450BC();
}
