#include "b13_types.h"
#include "m04_types.h"

typedef struct M04SynCfg {
    /* 0x00 */ s32 v0;
    /* 0x04 */ s32 v1;
    /* 0x08 */ s32 v2;
    /* 0x0C */ s32 padC;
    /* 0x10 */ s32 v4;
    /* 0x14 */ void *heap;
    /* 0x18 */ s32 pad18;
    /* 0x1C */ s8 v7;
    /* 0x1D */ u8 pad1D[3];
    /* 0x20 */ void *tab;
} M04SynCfg;

typedef struct M04AiCfg {
    s32 rate;
    s32 one;
    s32 size;
} M04AiCfg;

typedef struct M04Bank {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 f4;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ M04SortTab *tab;
} M04Bank;

typedef struct M04Res {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 f4;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ void *fC;
} M04Res;

extern f32 D_800C8FC0;
extern f32 D_800C8FC4;
extern s32 D_800D0960;
extern u8 D_800D0964[];
extern s32 D_800D2B30;
extern s32 D_8010B6A0;
extern u8 D_801462E1[];
extern s32 D_801536B0;
extern s32 D_801536EC;
void alHeapInit(void *h, s32 base, s32 len);
void alSndpNew(void *p, void *cfg);
void func_002567C4(void *l);
void func_002568A0(M04SynCfg *c, s32 a, M04AiCfg *ai);
s32 func_00265984(s32 a);
M04Res *func_0023C77C(s32 a, s32 b, s32 c);
void func_002576AC(SndMgr *m);
void func_0025D864(void *p, SndMgr *m);
void func_002596D4(void *q, SndMgr *m);
void func_0025B778(void *p, SndMgr *m);
void func_0025D178(void *p, SndMgr *m);

void func_00257380(SndMgr *m)
{
  M04SynCfg cfg;
  M04AiCfg ai;
  M04Res *r;
  M04Bank *bk;
  M04SortTab *t;
  s32 i;
  s32 j;
  s32 n;
  u32 a;
  u32 b;
  u8 *e;
  s32 x;
  s32 y;
  func_002567C4(&m->lock);
  SndMgr_Lock(m);
  x = D_801536B0;
  y = D_801536EC;
  *((s32 *) (((u8 *) m) + 0xD8)) = 0;
  alHeapInit(m->heap, x, y);
  cfg.v0 = 0x25;
  cfg.v1 = 0x25;
  cfg.v2 = 0x100;
  cfg.v7 = 6;
  cfg.tab = D_800D0964;
  ai.rate = 0x5622;
  ai.one = 1;
  cfg.v4 = 0;
  cfg.heap = m->heap;
  ai.size = 0x800;
  func_002568A0(&cfg, D_800D2B30, &ai);
  D_8010B6A0 = func_00265984(8);
  r = func_0023C77C(func_00265984(4) - func_00265984(0), 0, func_00265984(0));
  m->seq.unk8 = (s32 *) r->f4;
  bk = (M04Bank *) r->fC;
  *((void **) (((u8 *) m) + 0x80)) = bk;
  m->unk7C = (s32 *) bk->f4;
  func_002576AC(m);
  func_0025D864(&m->seq, m);
  t = ((M04Bank *) m->unk7C)->tab;
  for (i = 0; i < t->n; i++)
  {
    for (j = i + 1; j < t->n; j++)
    {
      a = t->v[j];
      b = t->v[i];
      if (a < b)
      {
        t->v[i] = a;
        t->v[j] = b;
      }
    }

  }

  *((s32 *) (((u8 *) m) + 0x24)) = 0x11;
  *((s32 *) (((u8 *) m) + 0x28)) = 0xC0;
  *((void **) (((u8 *) m) + 0x2C)) = m->heap;
  alSndpNew(m->player, ((u8 *) m) + 0x24);
  for (i = 15; i >= 0; i--)
  {
    m->snd[i] = -1;
  }

  m->unk102 = -1;
  m->unk2B8C = -1;
  m->unk108 = 0;
  m->unk104 = 0;
  m->unk2B88 = 0;
  m->unk2B94 = 0x40;
  m->unk2B98 = 0;
  m->unk2BB8 = 0;
  m->unk2B9C = 0;
  func_002596D4(&m->q, m);
  func_0025B778(&m->pool, m);
  e = D_801462E1;
  m->unk2BA0 = ((f32) e[0]) * D_800C8FC0;
  m->unk2BAC = 0;
  m->unk2BA4 = ((f32) e[-1]) * D_800C8FC0;
  m->unk2BA8 = ((f32) e[1]) * D_800C8FC0;
  m->unk2BB4 = 1;
  *((f32 *) (((u8 *) m) + 0x2BBC)) = D_800C8FC4;
  m->unk2BB0 = e[-2];
  func_0025D178(&m->obj2BC0, m);
  D_800D0960 = 1;
  SndMgr_Unlock(m);
}
