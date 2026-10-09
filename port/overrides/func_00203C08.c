/* port (passthru_fix.py): func_00262CA8 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b01_types.h"

void func_00262CA8(u32);

void func_00203C08(Actor *actor, ActorState *state) {
    if (state->unkCB != 0 && (actor->flags & 0x80000)) {
        func_00262CA8(actor);
    }
}
