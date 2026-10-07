#include "b01_types.h"

void func_00204738(Actor *actor) {
    if (*(f32 *)((u8 *)actor + 0x1B0) > 30.0f) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
}
