#include "b07_types.h"
s32 func_0022E5DC(Actor *actor)
{
    if (AT(s16, actor, 0x650) == 3 && (AT(s32, actor, 0x86C) == 0x5E2A || AT(s32, actor, 0x86C) == 0x5E5A)) {
        return 1;
    }
    return AT(s16, actor, 0x650) == 3 && AT(s32, actor, 0x86C) >= 0x7DF && AT(s32, actor, 0x86C) < 0x7E4;
}
