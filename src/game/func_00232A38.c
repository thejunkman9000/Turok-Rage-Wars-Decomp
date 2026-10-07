#include "b07_types.h"
extern u8 D_800CF298[];
extern f32 D_800C8108;
void func_0022FC10(void);
void func_0023292C(void);
void func_0022FD9C(u8 *a0, ActorState *state);
void func_00232A38(u8 *a0, ActorState *state)
{
    f32 k = D_800C8108;
    state->table = D_800CF298;
    state->fn108 = func_0022FC10;
    state->fn10C = func_0023292C;
    AT(s32, state, 0x124) = 0;
    AT(s32, state, 0x128) = 0;
    AT(s32, state, 0x130) = 0;
    AT(s32, state, 0x138) = 0;
    AT(s32, state, 0x13C) = 1;
    AT(f32, state, 0x12C) = k;
    a0[1] = 0;
    AT(s32, state, 0x148) = 0;
    AT(s32, state, 0x144) = 1;
    AT(s32, state, 0x14C) = 0;
    AT(s32, state, 0x150) = 0;
    func_0022FD9C(a0, state);
}
