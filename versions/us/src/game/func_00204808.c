#include "b01_types.h"

extern s32 D_800D15E0;
extern f32 D_800D15F0;
void func_0024A1C0(void);

void func_00204808(Actor *actor, ActorState *state) {
    f32 v = 255.0f - state->unk40 * 8.5f;
    D_800D15E0 = 1;
    if (v < 0.0f) {
        v = 0.0f;
    }
    D_800D15F0 = v;
    func_0024A1C0();
}
