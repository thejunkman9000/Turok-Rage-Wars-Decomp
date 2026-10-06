#include "b01_types.h"

extern u8 D_8011FE88[];
void func_00214178(Actor *actor, ActorState *state, s32 event);
void func_00285D80(void *mgr, void *arg, s32 flag);

void func_00205694(Actor *actor, ActorState *state) {
    func_00214178(actor, state, 1);
    func_00285D80(D_8011FE88, actor, 1);
}
