#include "m05_types.h"

typedef struct M5Rec {
    /* 0x00 */ s32 a[3];
    /* 0x0C */ s32 b[3];
    /* 0x18 */ s32 c[3];
    /* 0x24 */ s32 d24;
    /* 0x28 */ s32 d28;
    /* 0x2C */ u8 pad2C[3];
    /* 0x2F */ u8 b2F;
    /* 0x30 */ u8 pad30[7];
    /* 0x37 */ u8 b37;
    /* 0x38 */ u8 pad38[3];
    /* 0x3B */ u8 b3B;
    /* 0x3C */ u32 u3C;
    /* 0x40 */ u32 u40;
    /* 0x44 */ u32 u44;
    /* 0x48 */ u8 pad48[3];
    /* 0x4B */ u8 b4B;
} M5Rec;

typedef struct M5Fx {
    /* 0x00 */ f32 f0;
    /* 0x04 */ f32 f4;
    /* 0x08 */ f32 f8;
    /* 0x0C */ f32 fC;
    /* 0x10 */ f32 f10;
    /* 0x14 */ u8 pad14[0xA4];
    /* 0xB8 */ u8 bB8;
    /* 0xB9 */ u8 bB9;
    /* 0xBA */ u8 bBA;
    /* 0xBB */ u8 mode;
    /* 0xBC */ u8 padBC;
    /* 0xBD */ u8 bBD;
} M5Fx;

extern f32 D_800C9B50;
extern f32 D_800C9B54;
extern f32 D_800C9B58;
extern f32 D_800C9B5C;
extern f32 D_800C9B60;
extern f32 D_800C9B64;
extern f32 D_800C9B68;
extern f32 D_800C9B6C;
extern f32 D_800C9B70;
extern f32 D_800C9B74;
extern f32 D_800C9B78;
extern f32 D_800C9B7C;
extern f32 D_800C9B88;
extern f32 D_800C9BA0;
extern f32 D_800C9BA4;
extern f32 D_800C9BA8;
extern f32 D_800C9BAC;
extern s32 D_801462C8;

void func_0026EFC8(void *, void *);
void func_00272848(void *);
void func_00272A80(void *, void *, void *);
void func_002734B8(void *, f32, f32, f32);
void func_00273618(void *, f32, f32, f32);
void func_00273930(void *, f32);
void func_00273B08(void *, f32);
void func_00273CD8(void *, f32);
void func_002759C4(void *, s32, void *);

void func_00276D20(M5Fx *o, M5Rec *r)
{
  M5Vec3 a;
  M5Vec3 v;
  M5Vec3 c;
  M5Vec3 pts[8];
  s32 sA0[3];
  M5Vec3 q;
  M5Vec3 p;
  s32 i;
  s32 ok;
  M5Vec3 *out;
  f32 px;
  f32 py;
  f32 pz;
  u8 *m;
  f32 sc;
  register u8 *a0v asm("$4");
  sc = D_800C9B50;
  o->mode = r->b2F;
  a.x = ((f32) r->a[0]) * sc;
  a.y = ((f32) r->a[1]) * sc;
  a.z = ((f32) r->a[2]) * sc;
  if (o->mode != 1)
  {
    v.x = ((f32) r->b[0]) * D_800C9B54;
    v.y = ((f32) r->b[1]) * D_800C9B54;
    v.z = ((f32) r->b[2]) * D_800C9B54;
  }
  else
  {
    do
    {
      sA0[0] = 0;
    }
    while (0);
    if (r)
    {
      ((f32 *) sA0)[1] = D_800C9B58;
      sA0[2] = 0;
      q.x = ((f32) r->b[0]) * D_800C9B5C;
      q.y = ((f32) r->b[1]) * D_800C9B5C;
      q.z = ((f32) r->b[2]) * D_800C9B5C;
      m = ((u8 *) o) + 0x60;
      func_00272848(m);
      func_00273CD8(m, q.x);
      func_00273B08(m, q.y);
      func_00272A80(m, sA0, ((u8 *) o) + 0x14);
      v.x = 0.0f;
      v.y = 0.0f;
      v.z = 0.0f;
    }
    else
    {
      ((f32 *) sA0)[1] = D_800C9B58;
      sA0[2] = 0;
      q.x = ((f32) r->b[0]) * D_800C9B5C;
      q.y = ((f32) r->b[1]) * D_800C9B5C;
      q.z = ((f32) r->b[2]) * D_800C9B5C;
      m = ((u8 *) o) + 0x60;
      func_00272848(m);
      func_00273CD8(m, q.x);
      func_00273B08(m, q.y);
      func_00272A80(m, sA0, ((u8 *) o) + 0x14);
      v.x = 0.0f;
      v.y = 0.0f;
      v.z = 0.0f;
    }
  }
  ok = 1;
  if (v.x < 0.0f)
  {
    if (D_800C9B60 < (-v.x))
    {
      goto z1;
    }
  }
  else
    if (D_800C9B64 < v.x)
  {
    z1:
    ok = 0;

  }
  if (v.y < 0.0f)
  {
    if (D_800C9B68 < (-v.y))
    {
      goto z2;
    }
  }
  else
    if (D_800C9B6C < v.y)
  {
    z2:
    ok = 0;

  }
  if (v.z < 0.0f)
  {
    if (D_800C9B70 < (-v.z))
    {
      goto z3;
    }
  }
  else
    if (D_800C9B74 < v.z)
  {
    z3:
    ok = 0;

  }
  o->bB9 = 0;
  if (ok != 0)
  {
    o->bB9 = 1;
  }
  c.x = ((f32) r->c[0]) * D_800C9B78;
  c.y = ((f32) r->c[1]) * D_800C9B78;
  c.z = ((f32) r->c[2]) * D_800C9B78;
  o->f0 = (2.0f * ((f32) r->d24)) * D_800C9B7C;
  do
  {
    o->f4 = (2.0f * ((f32) r->d28)) * D_800C9B7C;
  }
  while (0);
  if (D_801462C8 & 0x4000)
  {
    o->f8 = 0.0f;
    o->fC = 0.0f;
    o->f10 = 0.0f;
  }
  else
  {
    o->f8 = ((f32) r->u3C) * D_800C9B88;
    o->fC = ((f32) r->u40) * D_800C9B88;
    o->f10 = ((f32) r->u44) * D_800C9B88;
  }
  do
  {
    m = ((u8 *) o) + 0x60;
  }
  while (0);
  o->bB8 = r->b37;
  a0v = m;
  do
  {
    { o->bBA = r->b3B; }
    i = 0;
  }
  while (0);
  o->bBD = r->b4B;
  out = pts;
  func_00272848(a0v);
  func_00273618(m, c.x, c.y, c.z);
  func_00273CD8(m, v.z);
  func_00273B08(m, v.y);
  func_00273930(m, v.x);
  func_002734B8(m, a.x, a.y, a.z);
  func_0026EFC8(((u8 *) o) + 0x20, m);
  do
  {
    px = D_800C9BA0;
    py = px;
    pz = px;
    if (i & 1)
    {
      px = D_800C9BA4;
    }
    if (i & 2)
    {
      py = D_800C9BA8;
    }
    if (i & 4)
    {
      pz = D_800C9BAC;
    }
    p.x = px;
    p.y = py;
    p.z = pz;
    func_00272A80(((u8 *) o) + 0x60, &p, out);
    out++;
    i++;
  }
  while (i < 8);
  func_002759C4(((u8 *) o) + 0xA0, 8, pts);
}
