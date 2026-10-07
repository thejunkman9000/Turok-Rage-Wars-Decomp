#include "common.h"

typedef struct {
    u8 pad0[4];
    u32 flags4;
    u32 flags8;
    u8 padC[4];
    s32 unk10;
    u8 task14[0x24];
    s32 unk38;
    u64 *unk3C;
} Job;
typedef struct {
    u8 pad0[0x2F4];
    Job *unk2F4;
    Job *unk2F8;
} Vid;

OSTime osGetTime(void);
void osWritebackDCacheAll(void);
s32 osSpTaskLoad(void *t);
void osSpTaskStartGo(void *t);
extern u64 D_8011F2A8;
extern u64 D_8011F290;
extern u64 D_8011F2A0;
extern u64 D_8011F2B0;
extern s32 D_8011F298;
extern s32 D_800D2960, D_800D2964;

void func_0028FA40(Vid *o, Job *cur, Job *next)
{
  OSTime t;
  u8 *tp;
  if (((next != 0) && (next->flags8 & 0x20)) && (!(next->flags4 & 0x10)))
  {
    t = osGetTime();
    D_8011F2A8 = t;
  }
  if (cur != 0)
  {
    if (cur->unk10 == 2)
    {
      osWritebackDCacheAll();
      tp = ((u8 *) cur) + 0x10;
      t = osGetTime();
      D_8011F290 = t;
      goto start;
    }
    tp = ((u8 *) cur) + 0x10;
    if (cur->flags8 & 0x20)
    {
      t = osGetTime();
      D_8011F2A0 = t;
      if (cur->flags4 & 0x10)
      {
        goto start;
      }
      D_8011F2B0 = t;
      D_8011F298 = 0;
      ;
    }
    start:
    cur->flags4 &= ~0x30;

    osSpTaskLoad(((u8 *) cur) + 0x10);
    osSpTaskStartGo(((u8 *) cur) + 0x10);
    o->unk2F4 = cur;
    if (cur == next)
    {
      o->unk2F8 = next;
    }
  }
  if ((next != 0) && (next != cur))
  {
    osDpSetNextBuffer((void *) next->unk38, *next->unk3C);
    D_800D2960 = 1;
    D_800D2964 = 0;
    o->unk2F8 = next;
  }
}
