#include "b07_types.h"

void func_00218464(void *p);

void func_0022DA74(Actor *actor)
{
    func_00218464((u8 *)actor + 0x938);
    AT(s32, actor, 0x11B4) = 0;
}
