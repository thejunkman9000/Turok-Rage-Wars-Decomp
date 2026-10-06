#include "p1_types.h"
void func_00214178(Actor *actor, u32 *state, s32 arg2);
void func_00207E74(Actor *actor, u32 *state) {
    actor->flags |= 0x2100;
    *state |= 0x20000;
    func_00214178(actor, state, 3);
}
