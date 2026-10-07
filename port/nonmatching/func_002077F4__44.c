#include "b01_types.h"
extern u8 D_800CD8F0[];
void func_002079B0(B01Actor *actor, B01State *state);
void func_00207910(B01Actor *actor, B01State *state);


void func_002077F4(B01Actor *actor, B01State *state) {
    B01Def *def = actor->def;
    B01Info *info;
    state->table = D_800CD8F0;
    state->fn108 = func_002079B0;
    state->fn11C = func_00207910;
    state->vec130.y = 0.0f;
    state->vec130.z = 0.0f;
    info = B01_INFO(def);
    state->unk64 = info->unk40.f;
    state->unk124.i = 0;
    state->unk128.i = 0;
    state->unk12C.i = 0;
    state->vec130.x = 0.0f;
    state->unk13C = info->unk40.f * 6.2831855f;
    state->unk140 = 0;
    state->unk144 = 0;
    state->unk148 = 0;
    state->unk14C = 0;
    state->unk168 = 0;
    state->unk16C = 0;
    if (def->flags14 & 4) {
        actor->flags &= ~0x2000;
    }
}
