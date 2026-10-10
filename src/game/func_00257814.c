#include "b13_types.h"
#include "m04_types.h"

extern f32 D_800C8FC8;
void alSndpSetPitch(void *p, s32 pitch);
void alSndpSetFXMix(void *p, s32 mix);
void alSndpSetPan(void *p, u8 pan);
void alSndpSetVol(void *p, s16 vol);
void func_002597A4(void *q, s32 a, s32 id);
s32 func_0025B874(void *pool, s16 idx, s32 id);
void func_0025B8DC(void *pool, s16 idx);

#define SLOTF(m, idx, off) (*(u32 *)((u8 *)(m) + (idx) * 0xCC + (off)))


static inline s32 find17(SndMgr *m, s32 id) {
    s32 i;
    SndVoice *vv;
    for (vv = m->pool.v, i = 0; i < 17; i++, vv++) {
        if (vv->unkC == id) {
            return i;
        }
    }
    return -1;
}

s32 func_00257814(SndMgr *m, s32 id)
{
  s16 idx;
  M04VP *p;
  SndVoice *vs;
  u8 *pl;
  s32 mix;
  f32 f;
  u8 *new_var;
  if (id == (-1))
  {
    return -1;
  }
  idx = find17(m, id);
  if (((s16) idx) == (-1))
  {
    return -1;
  }
  if (((s16) idx) == 16)
  {
    func_002597A4(&m->q, 16, id);
    return -1;
  }
  p = (M04VP *) ((u8 *)((((s16) idx) * 0xCC) + (u32) m) + 0x1DCC);
  pl = m->player;
  if (p->vol == 0)
  {
    if (!((*((u32 *) ((((u8 *) m) - (-(((s16) idx) * 0xCC))) + 0x1E60))) & 4))
    {
      *((u32 *) ((((u8 *) m) - (-(((s16) idx) * 0xCC))) + 0x1E60)) |= 8;
      m->unk102 = -1;
      return 0;
    }
  }
  if (func_0025B874(&m->pool, idx, id) == 0)
  {
    alSndpSetPitch(pl, p->v14.i);
    mix = ((p->s10 + m->unk2B9C) < 0x80) ? ((((u8 *) p)[0x11] + (*(((u8 *) m) + 0x2B9F))) & 0xFF) : (0x7F);
    alSndpSetFXMix(pl, mix);
    alSndpSetPan(pl, ((u8 *) (&p->pan))[1]);
    if ((*((u32 *) ((((u8 *) m) - (-(((s16) idx) * 0xCC))) + 0x1E60))) & 0x200)
    {
      f = m->unk2BA8;
    }
    else
    {
      f = m->unk2BA0;
      if (((*((u32 *) ((((u8 *) m) - (-(((s16) idx) * 0xCC))) + 0x1E80))) != 0) && (m->unk2BB8 != 0))
      {
        if (m->unk2BA0)
        {
          f *= D_800C8FC8;
        }
        else
        {
          f *= D_800C8FC8;
        }
      }
    }
    alSndpSetVol(pl, (s16) ((s32) ((((f32) p->vol) * f) * p->scale)));
    if ((*((u32 *) ((((u8 *) m) - (-(((s16) idx) * 0xCC))) + 0x1E5C))) == 0)
    {
      func_0025B8DC(&m->pool, idx);
    }
  }
  m->unk102 = -1;
  return 0;
}
