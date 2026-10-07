#include "b01_types.h"

extern f32 D_800D2988;
extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, B01Actor *actor);
void func_00206A20(B01Actor *actor, B01State *state);
void func_00206DD4(B01Actor *actor, B01State *state);

void func_002079B0(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    if (func_00285F28(D_8011FE88, actor) == 0) {
        actor->flags &= 0xFFFEFFFF;
        actor->flags &= ~0x100;
        return;
    }
    actor->flags |= 0x10000;
    if (state->link != NULL) {
        if (state->link->cb != NULL) {
            state->link->cb(actor, state);
        }
    }
    state->unk13C = state->unk13C + info->unk48 * D_800D2988;
    func_00206A20(actor, state);
    if (state->unk34 != 4) {
        func_00206DD4(actor, state);
    }
}
