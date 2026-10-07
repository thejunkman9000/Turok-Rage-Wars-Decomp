#include "b01_types.h"

void func_00204F78(void *unused, B01State *state, f32 val) {
    if (val == 0.0f || state->unk64 < val) {
        if (state->unk64 == 0.0f) {
            state->unk40 = 0.0f;
        }
        state->unk64 = val;
    }
}
