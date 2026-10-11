
#include "b24_types.h"

typedef struct ColB {
    u8 pad[3];
    u8 v;
} ColB;

typedef struct TxtGlob {
    u8 pad0[0xA0];
    ColB c[6];
    f32 f0;
    f32 f1;
    s32 unkC0;
    s32 unkC4;
} TxtGlob;

extern DlCmd *D_80110634;
extern TxtGlob D_8013B7B8[];
extern u32 D_8014D3D0;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_8011FE88[];
extern u8 D_8013B880[];
extern u8 D_8013B980[];
s32 func_0028BE88(u8 *, s32, s32, s32);
f32 func_0044239C(s32, s32, f32, f32);
void func_002AB19C(s32, s32, s16, s16, f32, f32, s32);
void func_002536F4(s32, s32);

#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

static inline f32 sw_val(void) {
    f32 r;
    switch (D_8014D3D0) {
    case 0: r = 24.0f; break;
    case 1: r = 12.0f; break;
    case 3: r = 6.0f; break;
    case 4: case 5: r = 16.0f; break;
    case 2: case 6: r = 8.0f; break;
    default: r = 1.0f; break;
    }
    return r;
}
#define SW(dst) dst = sw_val();

void func_002A98E0(u8 *str, f32 x, f32 y, f32 w, f32 h, s32 flag, s32 alpha, s32 mode)
{
  TxtGlob *g = D_8013B7B8;
  s32 sfx = 0;
  s32 font;
  s32 hd;
  s32 c;
  s32 gl;
  s32 nx;
  s32 ysh;
  s32 new_var;
  f32 kA;
  f32 kB;
  f32 adv;
  f32 sx;
  f32 sy;
  s32 ys;
  {
    DlCmd *_g = D_80110634++;
    _g->w0 = 0xE7000000;
    _g->w1 = 0;
  }
  if (flag != 0)
  {
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xFB000000;
      _g->w1 = (((u32) alpha) & ((0x01 << 8) - 1)) << 0;
    }
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xFA000000;
      _g->w1 = 0xFF;
    }
    x += (f32) (g->unkC0 * (D_800E28D0 / 284));
    y += (f32) (g->unkC4 * (D_800E28D4 / 222));
  }
  else
  {
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xFB000000;
      _g->w1 = ((((((u32) g->c[0].v) & ((0x01 << 8) - 1)) << 24) | ((((u32) g->c[1].v) & ((0x01 << 8) - 1)) << 16)) | ((((u32) g->c[2].v) & ((0x01 << 8) - 1)) << 8)) | ((((u32) alpha) & ((0x01 << 8) - 1)) << 0);
    }
    {
      DlCmd *_g = D_80110634++;
      _g->w0 = 0xFA000000;
      _g->w1 = ((((((u32) g->c[3].v) & ((0x01 << 8) - 1)) << 24) | ((((u32) g->c[4].v) & ((0x01 << 8) - 1)) << 16)) | ((((u32) g->c[5].v) & ((0x01 << 8) - 1)) << 8)) | ((((u32) 0xFF) & ((0x01 << 8) - 1)) << 0);
    }
  }
  switch (mode)
  {
    default:
      font = 2;
      break;

    case 0:
      font = 2;
      break;

    case 1:
      font = 1;
      sfx = font;
      break;

    case 2:

    case 3:
      font = 6;
      break;

    case 4:

    case 5:
      font = 5;
      break;

    case 6:
      font = 7;
      break;

  }

  hd = func_0028BE88(D_8011FE88, font, 0x10, 1);
  if (hd != 0)
  {
    if (str != ((void *) 0))
    {
      c = *str;
      asm("" : "+r"(c));
      if (c != 0)
      {
        s32 ff = 0xFF;
        while (1)
        {
          if (c == '\n')
          {
            break;
          }
          nx = str[1];
          switch (mode)
          {
            default:

            case 0:
              new_var = nx;
              gl = D_8013B980[c & 0xFF];
              kA = sw_val();
              kB = sw_val();
              adv = func_0044239C(c, new_var, kA, kB);
              break;

            case 1:
              gl = D_8013B880[c & 0xFF];
              adv = sw_val();
              break;

            case 2:
              gl = D_8013B880[c & 0xFF];
              adv = sw_val();
              break;

            case 3:
              gl = D_8013B880[c & 0xFF];
              adv = sw_val();
              break;

            case 4:
              gl = c;
              if (c == ff)
            {
              gl = 0xFF;
            }
              adv = sw_val();
              break;

            case 5:
              gl = c;
              if (c == ff)
            {
              gl = 0xFF;
            }
              adv = sw_val();
              break;

            case 6:
              gl = c;
              if (c == ff)
            {
              gl = 0xFF;
            }
              adv = sw_val();
              break;

          }

          sx = w;
          sy = h;
          if (sfx != 0)
          {
            if ((((gl & 0xFF) == 0x25) || ((gl & 0xFF) == 0x2B)) || ((gl & 0xFF) == 0x3D))
            {
              sx = ((f32) D_800E28D0) * 0.0035211267f;
              sy = ((f32) D_800E28D4) * 0.0045045046f;
            }
          }
          if ((gl & 0xFF) != ff)
          {
            {
              s32 yq = ((s32) y) << 16;
              func_002AB19C(hd, gl & 0xFF, (s32) x, yq >> 16, sx, sy, 1);
            }
          }
          x += adv * sx;
          str++;
          if (str == ((void *) 0))
          {
            break;
          }
          c = *str;
          asm("" : "+r"(c));
          if (c == 0)
          {
            break;
          }
        }

      }
    }
    func_002536F4(0, hd);
  }
}



