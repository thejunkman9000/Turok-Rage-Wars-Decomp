#include "b01_types.h"

extern u8 D_80135210[];
s32 func_00262D00(void *mgr, s32 a, s32 b, s32 c, s32 d, Vec3f v1, f32 f, Vec3f v2, Vec3f v3, s32 *p);

void func_002063EC(B01Actor *actor, B01State *state, Vec3f v1, Vec3f v2, s32 p68, s32 p6C, s32 p70) {
    if (func_00262D00(D_80135210, p6C, 0, p70, p68, v1, actor->unk6C, actor->vec1C, v2, &state->unk124.i) != 0) {
        state->unk128.i = state->unk128.i - 1;
    }
}
