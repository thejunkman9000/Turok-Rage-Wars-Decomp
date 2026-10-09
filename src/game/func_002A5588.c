

#include "b23_types.h"

typedef struct Def5588 {
    u32 flags;
} Def5588;

typedef struct Actor5588 {
    u8 pad0[4];
    u16 id;
    u8 pad6[0x112];
    Def5588 *def;
    u8 pad11C[0x10];
    s32 key;
    u8 pad130[0xA9];
    u8 unk1D9;
} Actor5588;

typedef struct Owner5588 {
    u8 pad0[0x751C];
    u8 freeList[0xC];
    SSlot *slots;
} Owner5588;

typedef struct Info5588 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ u8 pad4[0xC];
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 pad12[0xD];
    /* 0x1F */ u8 unk1F;
    /* 0x20 */ u8 unk20;
} Info5588;

typedef struct Slot5588 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ struct Slot5588 *next;
    /* 0x08 */ Info5588 *info;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 sub14[8];
    /* 0x1C */ s32 owner;
    /* 0x20 */ s32 id;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 flags;
    /* 0x40 */ u8 sub40[0xC];
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
} Slot5588;

extern s32 D_800D2E40[];
extern u8 D_8011FE88[];

void func_00272848(void *m);
void func_00279520(void *p);
Slot5588 *func_002796AC(void *list);
void func_00283038(void *a, void *b);
Info5588 *func_0028AFC8(void *tbl, void *arg);
void func_00296DDC(void *p, s32 v);
SEnt *func_002A35C0(void *o, Slot5588 *s, void *m);

void func_002A5588(Owner5588 *o, Actor5588 *a, void *arg2)
{
  u8 m[0x40];
  Slot5588 *new_var2;
  Slot5588 *s;
  register Slot5588 *q asm("$5");
  s32 new_var;
  Info5588 *t;
  SEnt *e;
  s32 s3;
  s32 v;
  f32 new_var3;
  s32 key;
  s32 id;
  s32 s4;
  if (a->def->flags & 0x10000)
  {
    key = a->key;
    id = a->id;
    s = 0;
    q = o->slots;
    while (q != 0)
    {
      if (q->owner == key)
      {
        new_var = q->id;
        s = q;
        if (new_var == id)
        {
          break;
        }
      }
      q = q->next;
      s = 0;
    }

  }
  else
  {
    s = 0;
  }
  if (s == 0)
  {
    s = func_002796AC(o->freeList);
    if (s == 0)
    {
      return;
    }
    t = func_0028AFC8(D_8011FE88, arg2);
    s3 = D_800D2E40[t->unk1F];
    s4 = D_800D2E40[t->unk20];
    func_00279520(s->sub40);
    s->flags = 2;
    if (a->def->flags & 0x10000)
    {
      s->flags = 0xA;
      s->owner = a->key;
      s->id = a->id;
    }
    else
    {
      s->owner = (s32) a;
      s->id = -1;
    }
    s->info = t;
    s->unkC = s3;
    s->unk10 = s4;
    new_var3 = t->unk0;
    new_var2 = s;
    s->unk28 = 0;
    s->unk24 = new_var3;
    s->unk34 = t->unk10;
    s->unk4C = 0;
    new_var2->unk50 = 0;
    s->unk2C = 0;
    s->unk30 = 0;
    s->unk38 = -1;
    if (s->unk34 != (-1))
    {
      func_00296DDC(s->sub14, s->unk34);
      if (a != 0)
      {
        func_00283038(a, s->sub14);
      }
    }
    if (s == 0)
    {
      return;
    }
  }
  a->unk1D9 = a->unk1D9 + 1;
  if (a->def->flags & 0x10000)
  {
    func_00272848(m);
    e = func_002A35C0(o, s, m);
    if (e != 0)
    {
      e->unkB0 = a;
    }
  }
}

