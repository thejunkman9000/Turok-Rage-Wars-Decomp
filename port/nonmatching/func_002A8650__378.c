#include "b24_types.h"

typedef struct Cam24 {
    u8 pad0[0x2A0];
    f32 unk2A0;
} Cam24;

typedef struct Bar24 {
    u8 pad0[8];
    s32 unk8;
    u8 padC[4];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x20];
    s32 unk38;
    u8 pad3C[8];
    s32 unk44;
} Bar24;

typedef struct Menu24 {
    u8 pad0[8];
    s32 unk8;
    u8 padC[4];
    f32 unk10;
    f32 unk14;
    u8 pad18[0x20];
    s32 unk38;
    s32 unk3C;
    u8 pad40[4];
    s32 unk44;
    Bar24 b48;
} Menu24;

extern Cam24 *D_801450A8;
extern s32 D_800E28D0[];
extern u8 D_801462DE[];
s32 func_00245788();
s32 func_002934DC();
s32 func_0040C4F4();
void func_002A8A94(void *);
void func_002A94E8();
void func_002A9F18(s32, s32, s32, s32, s32, s32, f32, f32);
void func_002AA224(s32);
void func_002AB9E4();
void func_002ABA44(s32, s32, s32, s32, s32, s32, s32, s32);
void func_002ABB2C(s32, s32, s32, s32, s32, s32);
void func_002ABB58(f32, f32);
void func_002ABC18(s32, s32, s16, s16, f32, f32, s32);

void func_002A8650(Menu24 *m, s32 which)
{
  f32 k;
  f32 sc;
  f32 fs0;
  f32 fs1;
  f32 fs0f;
  s32 s2;
  s32 s3;
  s32 s1;
  s32 r;
  s32 g;
  s32 b;
  int new_var;
  s32 off;
  s32 v;
  Bar24 *s0;
  if ((func_00245788() == 0) && (func_002934DC() != 0))
  {
    v = func_0040C4F4();
    k = 1.0f;
    if (v == 0)
    {
      k = 0.75f;
    }
    sc = (D_801450A8->unk2A0 / ((f32) D_800E28D0[1])) * k;
    switch (which)
    {
      case 1:
        s0 = (Bar24 *) m;
        r = 0x1D;
        g = 0x53;
        b = 0xE2;
        fs0 = s0->unk44;
        off = 0x1F;
        break;

      case 2:
        r = 0x8B;
        g = 0xB9;
        b = 0x46;
        off = 0x30;
        s0 = &m->b48;
        fs0 = *((s32 *) (((u8 *) m) + 0x8C));
        break;

      default:
        return;

    }

    s2 = s0->unk10;
    s3 = s0->unk14 + (off * sc);
    func_002AB9E4();
    func_002A8A94(s0);
    if (s0->unk8 == 1)
    {
      if (s0->unk38 < fs0)
      {
        s0->unk38 += 8;
        if (fs0 < s0->unk38)
        {
          s0->unk38 = fs0;
        }
      }
      else
        if (fs0 < s0->unk38)
      {
        s0->unk38 -= 4;
        if (s0->unk38 < fs0)
        {
          s0->unk38 = fs0;
        }
      }
    }
    s1 = s2 + 0x50;
    new_var = 0x70;
    func_002ABA44(s1, s3 + (sc * 9.0f), s1 + (((((s2 - new_var) + D_800E28D0[0]) - s1) * s0->unk38) / 100), s3 + (sc * 15.0f), r, g, b, ((D_801462DE[0] * 0xB4) / 255) & 0xFF);
    func_002AA224(D_801462DE[0]);
    if (which == 1)
    {
      fs0f = sc * 27.0f;
      fs0 = sc * 1.5f;
      fs1 = 1.0f;
      func_002ABC18(0x202, 0, s2 + 0x46, s0->unk14 + fs0f, fs1, fs0, which);
      func_002ABC18(0x203, 0, (((u16 *) D_800E28D0)[1] + s2) - 0x6D, s0->unk14 + fs0f, fs1, fs0, which);
      func_002A94E8();
      func_002ABB58(0.4f, sc * 0.4f);
      func_002ABB2C(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
      func_002A9F18(m->unk3C, s1, s3 - 2, D_801462DE[0], 0, 0, fs1, fs1);
    }
    else
    {
      func_002A94E8();
      func_002ABB58(0.4f, sc * 0.4f);
      func_002ABB2C(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
      func_002A9F18(*((s32 *) (((u8 *) m) + 0x84)), s1, s3 - 2, D_801462DE[0], 0, 0, 1.0f, 1.0f);
    }
  }
}
