#include "b15_types.h"
typedef struct B15Own { u8 pad[0x774]; Vec3f pos; } B15Own;
void func_00232734(Actor *a, void *b, s32 c);
void func_00267D80(s32 a, Actor *actor, s32 c, Vec3f pos, s32 e)
{
  B15Own *o = (B15Own *) actor->owner;
  void *p = ((u8 *) actor) + 0x170;
  B15Own *new_var;
  int new_var2;
  new_var2 = !actor->owner;
  new_var = o;
  if (new_var2)
  {
    new_var->pos = pos;
    func_00232734(actor, p, e);
  }
  else
  {
    new_var->pos = pos;
    func_00232734(actor, p, e);
  }
}
