#include "b07_types.h"

extern B07Weapon *D_800D052C[];

s32 func_0022BECC(Actor *actor)
{
    return D_800D052C[AT(s16, actor, 0x62E)]->unk8 > 0;
}
