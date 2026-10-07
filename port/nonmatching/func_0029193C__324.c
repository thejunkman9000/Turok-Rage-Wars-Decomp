/* semantics right (fills two OSTask-like records of a slot, sends them, advances the slot as func_00293038 does -- tail now identical to the EXACT func_00293038); ~149 words differ: the ROM materialises each constant/symbol address right before its store (all through v0), gcc hoists/CSEs them into temps */
#include "b21_types.h"

extern s32 D_801536B4;
extern s32 D_801536B8;
extern u8 D_800DCC40[];
extern u8 D_800DCD10[];
extern u8 D_800E8000[];
extern u8 D_800E0050[];
extern u8 D_800DE0A0[];
extern u8 D_800E0470[];
extern OSMesgQueue D_80146980;
extern u8 D_801469E8[];
extern u32 D_800D2978;
extern u32 D_800E28A0;
extern s32 D_800D2980;
extern s32 D_800D297C;
extern s32 D_801536F4;
extern s32 D_801536F0;
extern s32 D_801536BC;
extern s32 D_801536C0;
void osWritebackDCacheAll(void);
void func_0028FD2C(void *a, void *b);

void func_0029193C(B21Game *g, B21Slot *s)
{
  B21Task *t;
  u32 idx;
  B21Slot *u;
  t = &s->task[0];
  (&s->task[0])->unk40 = s->unk114;
  (&s->task[0])->unk10 = 1;
  (&s->task[0])->unk18 = (s32) D_800DCC40;
  if (1)
  {
    t->unk1C = ((s32) D_800DCD10) - ((s32) D_800DCC40);
    t->unk24 = 0x1000;
    t->unk2C = 0x800;
  }
  t->unk48 = (s32) D_800E8000;
  t->unk4C = 0xC00;
  t->unk20 = (s32) D_800DCD10;
  t->unk28 = (s32) D_800E0050;
  t->unk14 = 0;
  t->unk30 = 0;
  t->unk34 = 0;
  t->unk38 = D_801536B8;
  t->unk3C = D_801536B8 + D_801536B4;
  t->unk44 = s->unk11C;
  t->unk0 = 0;
  t->unk50 = (s32) (&D_80146980);
  t->unk54 = (s32) s->unkF0;
  t->unkC = s->unk110;
  if (s->unk128 != 0)
  {
    t->unk8 = 3;
  }
  else
  {
    t->unk8 = 0x23;
  }
  if (s->unk128 != 0)
  {
    t = &s->task[1];
    t->unk40 = s->unk118;
    t->unk10 = 1;
    t->unk18 = (s32) D_800DCC40;
    t->unk1C = ((s32) D_800DCD10) - ((s32) D_800DCC40);
    t->unk24 = 0x1000;
    t->unk2C = 0x800;
    t->unk48 = (s32) D_800E8000;
    t->unk4C = 0xC00;
    t->unk20 = (s32) D_800DE0A0;
    t->unk28 = (s32) D_800E0470;
    t->unk14 = 0;
    t->unk30 = 0;
    t->unk34 = 0;
    t->unk38 = D_801536B8;
    t->unk3C = D_801536B8 + D_801536B4;
    t->unk44 = s->unk120;
    t->unk0 = 0;
    t->unk8 = 0x23;
    t->unk50 = (s32) (&D_80146980);
    t->unk54 = (s32) s->unkF0;
    t->unkC = s->unk110;
  }
  osWritebackDCacheAll();
  func_0028FD2C(D_801469E8, &s->task[0]);
  if (s->unk128 != 0)
  {
    func_0028FD2C(D_801469E8, &s->task[1]);
  }
  D_800D2978++;
  idx = D_800D2978 % D_800E28A0;
  D_800D2980++;
  D_800D297C ^= 1;
  u = (g->curSlot = &g->slots[idx]);
  u->unk114 = (D_800D297C) ? (D_801536F4) : (D_801536F0);
  u = g->curSlot;
  u->unk118 = (D_800D297C) ? (D_801536BC) : (D_801536C0);
}
