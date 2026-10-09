#include "p1_types.h"
/* The MIPS code leaves a0..a3 untouched for the handler, and the callers rely on that: func_0028CCB8
 * (and the recompiled func_00266830) pass a third argument, a scratch buffer, that func_00219A40 - the
 * usual fn110 target - reads as its own third parameter.  The 2-parameter decomp drops it, so on x86
 * the callee read stack garbage (attract-demo crash in func_00219A40 +0x320). */
void func_002171FC(Actor *actor, ActorState *state, unsigned int a2, unsigned int a3) {
    if (state->fn110 != NULL) {
        ((void (*)(Actor *, ActorState *, unsigned int, unsigned int))state->fn110)(actor, state, a2, a3);
    }
}
