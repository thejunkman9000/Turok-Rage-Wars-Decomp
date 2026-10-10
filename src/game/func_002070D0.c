#include "m01_types.h"

typedef struct V16 { f32 x, y, z, w; } V16;
extern f32 D_800C6C18;
extern f32 D_800C6C1C;
extern f32 D_800C6C20;
extern f32 D_800C6C24;
extern f32 D_800C6C28;
extern f32 D_800C6C2C;
extern f32 D_800C6C30;
extern f32 D_800C6C34;
extern f32 D_800C6C38;
extern f32 D_800C6C3C;
extern f32 D_800C6C40;
extern f32 D_800C6C44;
extern f32 D_800C6C48;
extern f32 D_800C6C4C;
extern f32 D_800C6C50;
extern f32 D_800C6C54;
extern f32 D_800C6C58;
extern f32 D_800C6C5C;
extern f32 D_800C6C60;
extern f32 D_800C6C64;
extern f32 D_800C6C68;
extern f32 D_800C6C6C;
extern f32 D_800C6C70;
extern f32 D_800C6C74;
extern f32 D_800D2988;

M1CamRec *func_00219408(u8 *h);
M1CamRec *func_00219434(u8 *h);
void func_002192C0(u8 *h);
void func_00271FD8(V16 *dst, Vec3f *a, Vec3f *b);
void func_002720EC(V16 *v);
void func_00216808(M1Actor *a, M1Cam *c, f32 x, f32 y);
f32 func_00216F44(M1Actor *a, Vec3f pos);

void func_002070D0(M1Actor *actor, M1Cam *cam)
{
  Vec3f A;
  V16 D;
  V16 P;
  M1CamRec *rec;
  M1CamRec *s2;
  u8 *h;
  f32 fs0;
  f32 dist;
  f32 v;
  register f32 sp asm("$f12");
  f32 vf;
  Vec3f *p1;
  Vec3f *p2;
  u16 fl;
  f32 w1;
  f32 w2;
  f32 w3;
  f32 w4;
  f32 w5;
  f32 w6;
  f32 w7;
  f32 w8;
  f32 w9;
  f32 w10;
  f32 w11;
  f32 w12;
  f32 w13;
  f32 w14;
  f32 w15;
  f32 w16;
  f32 w17;
  f32 w18;
  h = ((u8 *) cam) + 0x94;
  rec = func_00219408(h);
  A = rec->pos;
  func_00271FD8(&D, &A, &actor->pos);
  s2 = func_00219434(h);
  dist = sqrtf(((D.x * D.x) + (D.y * D.y)) + (D.z * D.z));
  v = rec->f1C;
  fs0 = s2->f20;
  if (v < (vf = D_800C6C18))
  {
    v = D_800C6C18;
  }
  if (dist <= (v * D_800C6C1C))
  {
    cam->f14C = 0.0f;
    s2->fw.hu[0] = s2->fw.hu[0] & 0x7FFF;
    func_002192C0(h);
    cam->f140 = cam->f150;
    cam->f144 = cam->f154;
    cam->f148 = cam->f158;
    cam->f15C = cam->f134;
    cam->f160 = actor->f6C;
    cam->f164 = cam->f138;
    return;
  }
  if (s2->fw.hu[0] & 2)
  {
    if (cam->f14C <= 0.0f)
    {
      cam->f14C = fs0;
    }
    else
    {
      w1 = cam->f14C + fs0;
      cam->f14C = w1;
      if (D_800C6C20 < w1)
      {
        cam->f14C = D_800C6C20;
      }
    }
    if (s2 == rec)
    {
      func_00271FD8(&P, (Vec3f *) s2, &actor->pos);
    }
    else
    {
      func_00271FD8(&P, (Vec3f *) rec, (Vec3f *) s2);
    }
    func_002720EC(&P);
    ;
    P.x = cam->f140 + (cam->f14C * (P.x - cam->f140));
    w3 = cam->f144;
    P.y = w3 + (cam->f14C * (P.y - w3));
    w4 = cam->f148;
    P.z = w4 + (cam->f14C * (P.z - w4));
    func_002720EC(&P);
    if (cam->f14C >= D_800C6C24)
    {
      goto set140;
    }
  }
  else
  {
    func_002720EC(&D);
    ;
    P.x = cam->f140 + (fs0 * (D.x - cam->f140));
    w6 = cam->f144;
    P.y = w6 + (fs0 * (D.y - w6));
    w7 = cam->f148;
    P.z = w7 + (fs0 * (D.z - w7));
    func_002720EC(&P);
    set140:
    cam->f140 = P.x;

    cam->f144 = P.y;
    cam->f148 = P.z;
  }
  cam->f150 = P.x;
  cam->f154 = P.y;
  cam->f158 = P.z;
  fl = s2->fw.hu[0];
  if (fl & 1)
  {
    if ((cam->f168 > 0.0f) && (!(fl & 0x8000)))
    {
      sp = s2->f30; fs0 = D_800C6C28; sp = fs0 - sp; sp *= D_800C6C2C; vf = cam->f168 + ((cosf(sp) + fs0) * ((-cam->f168) * D_800C6C30));
      if (vf <= D_800C6C34)
      {
        cam->f16C = s2->f34 * D_800C6C38;
        vf = 0.0f;
        s2->fw.hu[0] = s2->fw.hu[0] | 0x8000;
      }
    }
    else
    {
      if (cam->f16C > 0.0f)
      {
        vf = 0.0f;
        cam->f16C = cam->f16C - D_800D2988;
        if (cam->f16C <= 0.0f)
        {
          cam->f16C = 0.0f;
        }
      }
      else
        if (cam->f16C == 0.0f)
      {
        sp = s2->f30; fs0 = D_800C6C3C; sp = fs0 - sp; sp *= D_800C6C40; vf = cam->f168 + ((cosf(sp) + fs0) * ((s2->f24 - cam->f168) * D_800C6C44));
      }
      else
      {
        vf = 0.0f;
      }
    }
  }
  else
  {
    vf = cam->f168 + ((cosf(D_800C6C48) + D_800C6C50) * ((s2->f24 - cam->f168) * D_800C6C4C));
  }
  if (actor->flags38 & 8)
  {
    vf = 0.0f;
  }
  cam->f168 = vf;
  cam->p54.x = actor->pos.x + ((P.x * vf) * D_800D2988);
  cam->p54.y = actor->pos.y + ((P.y * vf) * D_800D2988);
  cam->p54.z = actor->pos.z + ((P.z * vf) * D_800D2988);
  if (s2->fw.hu[0] & 8)
  {
    if ((s2->fw.i & 0x420000) == 0x420000)
    {
      w13 = cam->f160;
      actor->f6C = w13 + (cam->f14C * ((s2->f10 * D_800C6C54) - w13));
    }
    else
    {
      w14 = actor->f6C;
      actor->f6C = w14 + (((s2->f10 * D_800C6C58) - w14) * D_800C6C5C);
    }
  }
  else
  {
    func_00216808(actor, cam, 10.0f, func_00216F44(actor, cam->p54));
  }
  if (s2->fw.hu[0] & 4)
  {
    if ((s2->fw.i & 0x220000) == 0x220000)
    {
      w15 = cam->f15C;
      cam->f134 = w15 + (cam->f14C * ((s2->f28 * D_800C6C60) - w15));
    }
    else
    {
      w16 = cam->f134;
      cam->f134 = w16 + (((s2->f28 * D_800C6C64) - w16) * D_800C6C68);
    }
  }
  if (s2->fw.hu[0] & 0x10)
  {
    if ((s2->fw.i & 0x820000) == 0x820000)
    {
      w17 = cam->f164;
      cam->f138 = w17 + (cam->f14C * ((s2->f2C * D_800C6C6C) - w17));
      return;
    }
    w18 = cam->f138;
    cam->f138 = w18 + (((s2->f2C * D_800C6C70) - w18) * D_800C6C74);
  }
}
