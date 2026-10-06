#include "b07_types.h"

s32 func_0022C450(Actor *actor)
{
    s16 st = AT(s16, actor, 0x650);

    if (st == 0x15 || st == 0x13 || st == 0x14) {
        return 1;
    }
    return 0;
}
