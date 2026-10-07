#include "b01_types.h"

extern s32 D_8011FE88[];
void func_002170A0(B01Actor *actor, B01State *state, s32 kind, s32 a, s32 b);
void func_00285D80(void *mgr, B01Actor *actor, s32 flag);
void func_00278DE8(B01Actor *actor, s32 flags, B01Actor *actor2);

void func_00203B60(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    func_002170A0(actor, state, 4, info->unkC.i, info->unk10.i);
    state->fn110 = 0;
    func_00285D80(D_8011FE88, actor, 1);
    func_00278DE8(actor, 1, actor);
    actor->flags &= ~0x10000;
    if (D_8011FE88[0] != 4) {
        actor->flags |= 0x8000000;
    }
}
