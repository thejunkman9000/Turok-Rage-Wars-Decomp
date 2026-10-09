#include "b07_types.h"

extern f32 D_800C7ED0;
extern f32 D_800C7ED4;
extern f32 D_800C7ED8;
extern f32 D_800C7EDC;
extern f32 D_800C7EE0;
extern f32 D_800C7EE4;

typedef struct F718 { u8 pad[0x718]; f32 f718; s32 f71C; } F718;
void func_002227D0(Actor *actor, ActorState *state, s32 kind);
void func_002748E0(void *p, f32 a, f32 b);

void func_0022DC34(Actor *actor, ActorState *state, s32 unused, u32 *flags)
{
  s32 s1;
  u32 fl;
  f32 v;
  f32 cur;
  f32 d;
  f32 nv;
  fl = (*((u32 *) (((u8 *) state) + 0x38))) & 0xC0000;
  s1 = fl != 0;
  if (((F718 *) actor)->f71C != 0)
  {
    s1 = 1;
    if ((*((s16 *) (((u8 *) actor) + 0x650))) != 4)
    {
      func_002227D0(actor, state, 4);
    }
  }
  v = 0;
  if (s1)
  {
    v = D_800C7ED0;
  }
  cur = ((F718 *) actor)->f718;
  func_002748E0(&cur, v, 0.25f);
  d = cur - ((F718 *) actor)->f718;
  if (d < 0)
  {
    if ((-d) < D_800C7ED4)
    {
      goto zero;
    }
  }
  else
    if (d < D_800C7ED8)
  {
    zero:
    d = 0;

  }
  nv = ((F718 *) actor)->f718 + d;
  d = D_800C7EDC - nv;
  ((F718 *) actor)->f718 = nv;
  if ((D_800C7EE0 <= d) && (d <= D_800C7EE4))
  {
    *flags |= 0x80;
  }
  else
  {
    *flags &= ~0x80;
  }
}
