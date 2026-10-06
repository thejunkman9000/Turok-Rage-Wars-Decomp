#include "b01_types.h"

extern f32 D_800C6B60;

void func_00204738(Actor *actor) {
    if (*(f32 *)((u8 *)actor + 0x1B0) > D_800C6B60) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
}
