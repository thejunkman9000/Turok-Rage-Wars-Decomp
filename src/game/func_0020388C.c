#include "b01_types.h"

extern u8 D_800CD3C0[];
void func_002039F8(B01Actor *actor, B01State *state);
void func_00203E78(B01Actor *actor, B01State *state);
void func_00202E4C(B01Actor *actor, B01State *state);
void func_00203DF0(B01Actor *actor, B01State *state);

void func_0020388C(B01Actor *actor, B01State *state) {
    float new_var;
    state->table = D_800CD3C0;
    state->fn108 = func_002039F8;
    state->fn110 = func_00203E78;
    state->fn11C = func_00202E4C;
    state->fn120 = func_00203DF0;
    if (actor->unkE4 == 0x40C) {
        if (func_00203DF0) {
            new_var = 1.57079649f;
            state->vec130.x = 0.0f;
            state->vec130.z = 0.0f;
            state->unk12C.i = 200;
            state->unk13C = 0.0f;
            state->vec130.y = 1.0f;
            state->unk124.f = -new_var;
        } else {
            new_var = 1.57079649f;
            state->vec130.x = 0.0f;
            state->vec130.z = 0.0f;
            state->unk12C.i = 200;
            state->unk13C = 0.0f;
            state->vec130.y = 1.0f;
            state->unk124.f = -new_var;
        }
    }
}
