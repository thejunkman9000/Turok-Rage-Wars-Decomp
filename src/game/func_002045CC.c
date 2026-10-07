#include "b01_types.h"

extern u8 D_8011FE88[];
void func_00285D80(void *mgr, Actor *actor, s32 flag);
void func_00278DE8(Actor *actor, s32 flags, Actor *actor2);

void func_002045CC(Actor *actor, ActorState *state) {
    func_00285D80(D_8011FE88, actor, 0);
    func_00278DE8(actor, 0x200000, actor);
    state->unk12C.i = 0;
}
