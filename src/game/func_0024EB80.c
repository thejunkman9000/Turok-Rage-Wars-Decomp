#include "b11_types.h"
#include "m03_types.h"

extern M03Dl *D_80110634;
extern s32 D_800D297C;
extern f32 D_8013B190;
void func_0026D8F8(void);
void func_00296FF8(void);
s32 *func_0024F6DC(Obj *a, s32 b);
void func_00273744(void *m, f32 a);
void func_002734EC(void *m, f32 a, f32 b, f32 c);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_002725BC(void *p, f32 s);
void func_00273DDC(void *m);
void func_002702EC(void *m, void *dst);
void func_0026DA4C(s32 *a, s32 b, s32 c, s32 d, s32 *e, s32 f);
void func_0024ED80(Obj *a, s32 *b);
void func_002536F4(s32 a, s32 *p);

void func_0024EB80(Obj *a)
{
  u8 m[0x40];
  s32 *h;
  M03Dl *d1;
  M03Dl *d2;
  int new_var;
  M03Dl *d3;
  M03Dl *d4;
  M03Dl *e;
  f32 s;
  func_0026D8F8();
  func_00296FF8();
  if (a->unk1C4 != 0)
  {
    d1 = D_80110634++;
    d1->w0 = 0xDE000000;
    d1->w1 = a->unk1C4;
    return;
  }
  h = func_0024F6DC(a, a->unk1);
  if (h != 0)
  {
    a->unk1C4 = (s32) D_80110634;
    d2 = D_80110634++;
    d2->w0 = 0xDE010000;
    d2->w1 = 0;
    if ((*((s32 *) a->def)) == 8)
    {
      func_00273744(m, D_8013B190);
    }
    else
    {
      func_00273744(m, *((f32 *) (((u8 *) a) + 0x174)));
    }
    func_002734EC(m, a->unk194, a->unk194, a->unk194);
    func_002725BC(&a->pos, 20000.0f);
    func_002734B8(m, a->pos.x, a->pos.y + (*((f32 *) (((u8 *) a) + 0x198))), a->pos.z);
    func_00273DDC(m);
    func_002702EC(m, ((u8 *) a) + ((D_800D297C << 6) + 0x68));
    new_var = 0;
    if ((*((s32 *) a->def)) != 0xC)
    {
      func_0026DA4C(h, (s32) (((u8 *) a) + ((D_800D297C << 6) + 0x68)), new_var, (s32) (((u8 *) a) + 0x1A8), new_var, a->unk3);
      func_0024ED80(a, h);
    }
    d3 = D_80110634++;
    d3->w0 = 0xDF000000;
    d3->w1 = 0;
    e = ((M03Dl **) (&a->unk1C4))[new_var]++;
    e->w0 = 0xDE010000;
    e->w1 = (u32) D_80110634;
    d4 = D_80110634++;
    d4->w0 = 0xDE000000;
    d4->w1 = a->unk1C4;
    func_002536F4(0, h);
  }
}

