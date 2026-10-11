#include "b01_types.h"

extern s32 D_auto_800CC390;
extern f32 D_auto_800CC3A0;
void func_0024A1C0(void);

void func_auto_00204808(Actor *actor, ActorState *state) {
    f32 v = 255.0f - state->unk40 * 8.5f;
    D_auto_800CC390 = 1;
    if (v < 0.0f) {
        v = 0.0f;
    }
    D_auto_800CC3A0 = v;
    func_0024A1C0();
}
