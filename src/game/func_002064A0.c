#include "b01_types.h"

extern u8 D_80121990[];
s32 func_00280094(void *mgr, B01Actor *a, B01Actor *b, s32 *p, s32 c, s32 d, Vec3f v1, B01Vec4 v2, Vec3f v3, s32 e, s32 f, s32 g);

void func_002064A0(B01Actor *actor, B01State *state, Vec3f v, s32 p6C, s32 p70) {
    state->unk128.i = state->unk128.i - func_00280094(D_80121990, actor, actor, &state->unk124.i, 0, p70, actor->vec1C, actor->vec5C, v, 0, -1, 0);
}
