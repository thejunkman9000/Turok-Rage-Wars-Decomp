/* PORT override of src/game/func_002631D0.c (controller -> walk / strafe / turn / tilt of a player): unchanged game logic plus native keyboard / mouse controls (port/input.c). */
#include "r05_types.h"
extern f32 D_800C9380;
extern f32 D_800C9384;
extern f32 D_800C9388;
extern f32 D_800C938C;
extern f32 D_800C9390;
extern f32 D_800C9394;
extern f32 D_800C9398;
extern f32 D_800C939C;
extern f32 D_800C93A0;
extern f32 D_800C93A4;
extern f32 D_800C93A8;
extern f32 D_800C93AC;
extern f32 D_800C93B0;
extern f32 D_800C93B4;
extern f32 D_800C93B8;
extern f32 D_800C93BC;
extern f32 D_800C93C0;
extern f32 D_800C93C4;
extern f32 D_800C93C8;
extern f32 D_800C93CC;
extern f32 D_800C93D0;
extern f32 D_800C93D4;
extern f32 D_800C93D8;
extern f32 D_800D2988;
extern R05PadMap D_800D0DB0[];
f32 func_00274810(f32 a, f32 b, R05PadMap *tab, R05PadCtl *c);
int input_native_active(int port);          /* port/input.c (native host code) */
float input_native_get(int port, int what);
void func_002631D0(R05PadOut *s, R05PadOwn *ow)
{
  register R05PadCfg *cfg asm("$17") = ow->cfg;
  f32 dt = D_800C9388 - (ow->f7EC * D_800C9380);
  R05PadCtl *c = s->ctl;
  f32 k;
  R05PadMap *tab;
  s32 mask;
  s32 val;
  s32 b;
  f32 cur;
  f32 fa;
  f32 lim;
  f32 sq;
  f32 r;
  f32 keep = s->f4;      /* PORT: the view tilt before this frame (native controls keep it) */
  k = (((f32) cfg->b7A) * D_800C9384) - D_800C9388;
  k = (k * D_800C9390) + D_800C9388;
  k = k * (D_800D2988 * (dt * D_800C938C));
  { register s32 m asm("$3") = cfg->mode; __asm__ volatile("" : : "r"(m) : "memory"); }
  tab = 0;
  if (cfg->mode < 2)
  {
    if (cfg->mode >= 0)
    {
      if (cfg->b7C == 1)
      {
        tab = D_800D0DB0;
      }
    }
  }
  if (tab != 0)
  {
    s->bits[0] = 0;
    s->bits[1] = 0;
    s->bits[2] = 0;
    s->bits[3] = 0;
    s->bits[4] = 0;
    if (tab->mask != 0)
    {
      loop:
      mask = tab->mask;

      val = tab->val;
      if (c->btn[0] & mask)
      {
        s->bits[0] |= val;
      }
      if (c->btn[1] & mask)
      {
        s->bits[1] |= val;
      }
      if (c->btn[2] & mask)
      {
        s->bits[2] |= val;
      }
      if (c->btn[3] & mask)
      {
        s->bits[3] |= val;
      }
      tab++;
      if (c->btn[4] & mask)
      {
        s->bits[4] |= val;
      }
      if (tab->mask != 0)
      {
        goto loop;
      }
    }
  }
  else
  {
    s->bits[0] = c->btn[0];
    s->bits[1] = c->btn[1];
    s->bits[2] = c->btn[2];
    s->bits[3] = c->btn[3];
    s->bits[4] = c->btn[4];
  }
  switch (cfg->mode)
  {
    case 0:
      b = s->bits[0];
      if (b & 1)
    {
      s->f8 = D_800C9394;
    }
    else
      if (b & 2)
    {
      s->f8 = D_800C9398;
    }
    else
    {
      s->f8 = 0.0f;
    }
      b = s->bits[0];
      s->f0 = ((f32) c->stickX) * D_800C939C;
      if (b & 8)
    {
      if (c->btn)
      {
        s->fC = D_800C93A0;
      }
      else
      {
        s->fC = D_800C93A0;
      }
    }
    else
      if (b & 4)
    {
      s->fC = D_800C93A4;
    }
    else
    {
      s->fC = 0.0f;
    }
      if (cfg->b7D != 0)
    {
      s->f4 = ((f32) c->stickY) * D_800C93A8;
    }
    else
      if (ow->unk11B4 == 0)
    {
      if (c->stickY != 0)
      {
        s->f4 = s->f4 + ((k * D_800C93AC) * ((f32) c->stickY));
      }
      {
        register f32 c0 asm("$f0") = s->f4;
        if (D_800C93B0 < c0)
        {
          s->f4 = D_800C93B0;
        }
        else
          if (c0 < D_800C93B4)
        {
          s->f4 = D_800C93B4;
        }
      }
    }
      break;

    case 1:
      b = s->bits[0];
      s->f0 = ((f32) c->stickX) * D_800C93B8;
      if (b & 1)
    {
 do { s->f8 = D_800C93BC; } while (0);
    }
    else
      if (b & 2)
    {
      s->f8 = D_800C93C0;
    }
    else
    {
      s->f8 = 0.0f;
    }
      if (ow->unk11B4 == 0)
    {
      s->fC = ((f32) c->stickY) * D_800C93C4;
    }
    else
    {
      s->fC = 0.0f;
    }
      b = s->bits[0];
      if (!(b & 0x10))
    {
      if (s->bits[0] & 8)
      {
        cur = s->f4 + (k * D_800C93C8);
        lim = D_800C93CC;
        if (lim < cur)
        {
          cur = lim;
        }
        s->f4 = cur;
      }
      else
        if (s->bits[0] & 4)
      {
        cur = s->f4 - (k * D_800C93D0);
        lim = D_800C93D4;
        if (cur < lim)
        {
          cur = lim;
        }
        s->f4 = cur;
      }
      else
        if (cfg->b7D != 0)
      {
        fa = s->fC;
        if ((fa != 0.0f) && (ow->unk7E8 == 0))
        {
          fa = fa * (dt * D_800C93D8);
          if (fa < 0.0f)
          {
            fa = -fa;
          }
          s->f4 = func_00274810(s->f4, fa, tab, c);
        }
      }
    }
      break;

  }

  sq = s->f8;
  cur = sq * sq;
  if (cur < 0.0f)
  {
    r = sq * (-cur);
  }
  else
  {
    r = sq * cur;
  }
  sq = s->f0;
  cur = sq * sq;
  s->f1C = r;
  if (cur < 0.0f)
  {
    s->f14 = sq * (-cur);
  }
  else
  {
    s->f14 = sq * cur;
  }
  s->f20 = s->fC;
  s->f18 = s->f4;
  {   /* PORT: native keyboard / mouse controls (port/input.c, native_controls).  The C-button inputs walk and strafe whatever the control style (they are taken
       * out of the pad data the game sees), and the view tilt belongs to the mouse: the game's look spring (style 0) and C-button tilt / auto-centring (style 1)
       * would pull it back every frame.  The pad stick keeps tilting in style 0. */
    s32 port = (c != 0) ? (s32)((s8 *)c)[4] : -1;
    if (input_native_active(port)) {
      f32 v;
      if (cfg->mode == 1) {
        s->f4 = keep;
      } else if (cfg->mode == 0 && cfg->b7D != 0) {
        v = keep;
        if (c->stickY != 0) {
          v = v + (k * D_800C93AC) * ((f32) c->stickY);
        }
        if (v > 1.0f) v = 1.0f;
        if (v < -1.0f) v = -1.0f;
        s->f4 = v;
      }
      s->f18 = s->f4;
      v = input_native_get(port, 0);
      if (v != 0.0f) s->f20 = v;
      v = input_native_get(port, 1);
      if (v != 0.0f) s->f1C = v;
    }
  }
}
