#include "b07_types.h"
extern u8 D_800CE7FC[];
extern u8 D_800CE7C0[];
extern u8 D_800CED30[];
void func_00224028(Actor *actor, ActorState *state);
void func_002748E0(void *p, f32 a, f32 b);
void func_002231B0(Actor *actor, ActorState *state, void *tbl);
void func_002233CC(Actor *actor, ActorState *state, void *tbl);
void func_002227D0(Actor *actor, ActorState *state, s32 kind);
void func_0022C8EC(Actor *actor, ActorState *state)
{
  s32 r;
  f32 x;
  f32 z = 0.0f;
  func_00224028(actor, state);
  func_002748E0(((u8 *) actor) + 0x72C, z, 0.25f);
  func_002231B0(actor, state, D_800CE7FC);
  func_002233CC(actor, state, D_800CE7C0);
  if (!((*((u32 *) (((u8 *) actor) + 0x6AC))) & 0x10))
  {
    func_002227D0(actor, state, 2);
    r = 0;
    r = (((*((u8 **) (((u8 *) actor) + 0x13B4))) == D_800CED30) ? (0x5E24) : (1)) ^ r;
  }
  else
  {
    x = *((f32 *) (((u8 *) actor) + 0x6C0));
    do
    {
      if ((x == z) && ((*((f32 *) (((u8 *) actor) + 0x6C4))) == z))
      {
        r = 0xA64;
      }
      else
        if (x < (*((f32 *) (((u8 *) actor) + 0x6C4))))
      {
        if (!((*((f32 *) (((u8 *) actor) + 0x6C4))) > z))
        {
          r = 0xA66;
        }
        else
        {
          r = 0xA67;
        }
      }
      else
        if (!(x > z))
      {
        r = 0xA68;
      }
      else
      {
        r = 0xA65;
      }
    }
    while (0);
  }
  *((s32 *) (((u8 *) actor) + 0x86C)) = r;
}
