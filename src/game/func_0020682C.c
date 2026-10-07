#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00245788(void);
void func_002472E0(Actor *actor);
void func_00285D80(void *mgr, Actor *actor, s32 flag);

void func_0020682C(Actor *actor, ActorState *state) {
    actor->flags |= 0x2100;
    if (func_00245788() != 0) {
        state->flags |= 0x200;
    }
    func_002472E0(actor);
    func_00285D80(D_8011FE88, actor, 0);
}
