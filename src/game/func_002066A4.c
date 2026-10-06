#include "p1_types.h"
extern f32 D_800C6BD0;
extern u8 D_8011FE88[];
void func_00214178(Actor *actor, ActorState *state, s32 arg2);
s32 func_00285F28(void *p, Actor *actor);
void func_002066A4(Actor *actor, ActorState *state) {
    state->unk124 = actor->def->info.unk4;
    func_00214178(actor, state, 0);
    state->unk128.f = D_800C6BD0;
    state->unk12C.f = D_800C6BD0;
    if (func_00285F28(D_8011FE88, actor) == 1) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
}
