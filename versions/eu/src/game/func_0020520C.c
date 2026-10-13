#include "p1_types.h"
extern u8 D_800CD670[];
void func_002052C4();
void func_00205628();
void func_00205094();
void func_0020520C(u8 *arg0, ActorState *state) {
    state->table = D_800CD670;
    state->fn108 = func_002052C4;
    state->fn10C = func_00205628;
    state->fn110 = func_00205094;
    state->unk124 = 0;
    state->unk128.i = (s8)arg0[3];
}
