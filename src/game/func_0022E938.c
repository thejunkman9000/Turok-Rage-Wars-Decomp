#include "b07_types.h"

extern u8 D_801462E5[];

void func_0022E938(Actor *actor)
{
    if (D_801462E5[0] == 0) {
        if (*(s32 *)(D_801462E5 - 0x55) != 0) {
            if (AT(u32, actor, 0x6AC) & 0x20) {
                return;
            }
        }
        if (AT(u32, actor, 0x6B0) & 0x800) {
            if (AT(s32, actor, 0x13D4) != 0) {
                AT(s32, actor, 0x13D4) = 0;
            } else {
                AT(s32, actor, 0x13D4) = 1;
            }
        }
    }
}
