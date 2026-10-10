#include "b13_types.h"
#include "m04_types.h"

extern f32 D_800C905C;
extern f32 D_800C9060;
extern f32 D_800C9064;
extern s32 D_800D0D14[];
extern s32 D_800D0D24[];
s16 alSndpAllocate(void *p, s32 a, void *owner);
void alSndpSetPriority(void *p, s16 id, s32 pri);
void func_00258760(SndMgr *m);
void func_002587C4(SndMgr *m);
s16 func_0025B054(SndVoices *p, s16 a, s16 b, s16 c, s32 d);
s16 func_0025E520(SndInfo *i);
s8 func_0025E538(SndInfo *i);
s8 func_0025E544(SndInfo *i);
s8 func_0025E568(SndInfo *i);
s16 func_0025E598(SndInfo *i);
s32 func_0027458C();

typedef struct M04Bank2 {
    u8 pad0[0xC];
    M04SortTab *tab;
} M04Bank2;

M04Emitter *func_0025B1E8(SndVoices *p, SndInfo *info, int tag, s32 a3)
{
  s16 *snd;
  SndMgr *m3;
  SndMgr *m;
  s32 i;
  s16 idx;
  u8 *core;
  s32 pr;
  M04VP *vp;
  s32 pri;
  unsigned int sv;
  u16 flag;
  f32 f;
  u8 *new_var2;
  SndMgr *m2;
  s16 *new_var;
  s32 r;
  M04Emitter *v;
  pri = func_0025E520(info);
  flag = func_0025E538(info);
  m = p->owner;
  snd = m->snd;
  if (((M04Bank2 *) m->unk7C)->tab->n < pri)
  {
    return 0;
  }
  func_00258760(m);
  new_var = &(*((s16 *) (((u8 *) info) + 2)));
  if ((func_0025E544(info) == 0x64) || ((func_0027458C() % 100) < func_0025E544(info)))
  {
    idx = func_0025B054(p, (s16) tag, pri, (s16) flag, func_0025E598(info));
    if (idx != (-1))
    {
      v = (M04Emitter *) (&p->v[idx]);
      if (idx == 0x10)
      {
        v->w4 = a3;
        v->id = p->owner->unk108++;
        v->w8 = 0x63;
        goto blk16;
      }
      p->owner->unk102 = idx;
      m2 = p->owner;
      new_var2 = m2->player;
      core = ((u8 *) m2) + 0x7C;
      snd[idx] = alSndpAllocate(new_var2, ((M04Bank2 *) m2->unk7C)->tab->v[pri], m2);
      sv = snd[idx];
      if (sv == (-1))
      {
        v->id = sv;
        v->w8 = sv;
        v->vp.s28 = 0;
        p->owner->unk102 = sv;
        fail:
        func_002587C4(p->owner);

        return 0;
      }
      f = ((f32) ((s16) flag)) * D_800C905C;
      (*((u16 *) (core + 0x80)))++;
      v->w4 = a3;
      m3 = p->owner;
      v->id = m3->unk108++;
      v->w8 = snd[idx];
      v->unkA0 = *new_var;
      if (!(D_800C9060 <= f))
      {
        pr = (s32) f;
      }
      else
      {
        pr = (s32) (f - D_800C9060);
        pr = pr | 0x80000000;
      }
      alSndpSetPriority(new_var2, snd[idx], pr & 0xFF);
      blk16:
      v->kind = p->owner->unk2B8C;
      v->resetFlag = p->owner->unk2BAC;
      v->unkBC = 0;
      for (i = 0; i < 4; i++) { if (v->kind == D_800D0D14[i]) { v->unkBC = 1; break; } }
      v->unkC4 = 1;
      for (i = 0; i < 6; i++) { if (v->kind == D_800D0D24[i]) { v->unkC4 = 0; break; } }
      v->unkB4 = p->owner->unk2B90;
      v->unkAC = 0;
      vp = &v->vp;
      v->unkB8 = *((f32 *) (((u8 *) p->owner) + 0x2BBC));
      vp->s28 = flag;
      vp->vol = (vp->wC = 0x7D00);
      vp->v14.i = 0;
      vp->s10 = *((s8 *) (((u8 *) info) + 0xE));
      vp->pan = 0x40;
      vp->s2A = pri;
      vp->s2C = tag;
      vp->w0 = p->owner->unk104;
      vp->f24 = D_800C9064;
      vp->mode = func_0025E568(info);
      v->flags = func_0025E598(info);
      vp->f40 = 0;
      func_002587C4(p->owner);
      return v;
    }
  }
  goto fail;
}
