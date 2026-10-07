#include "b01_types.h"

extern s32 D_800D297C;
void func_0026DC24(s32 a, s32 b, s32 c, B01Seg *seg, s32 d, s32 e);

void func_00205628(B01Actor *obj, ActorState *state, B01Evt *evt) {
    obj->unk17C = 1 << state->unk124;
    if (evt->unk0 != 0) {
        func_0026DC24(evt->unkC, obj->unkB4, 1, &obj->seg[D_800D297C], 0, state->unk128.i);
    }
}
