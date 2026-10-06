#include "b07_types.h"
void func_44ACCC(Actor *actor);
void func_0022D204(Actor *actor)
{
    actor->flags &= ~0x800000;
    AT(s32, actor, 0x11D8) = 0;
    AT(s32, actor, 0x11FC) = 0;
    actor->flags |= 0x1000000;
    func_44ACCC(actor);
}
