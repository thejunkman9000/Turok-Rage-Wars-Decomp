#include "b01_types.h"

extern u8 *D_800E4680;
extern u8 D_80131600[];
extern u8 D_801462D5;
extern B01Game D_801468A0[];
B01Actor *func_0028FFB0(void *mgr, s32 *p, s32 id, Vec3f a, Vec3f b, s32 c, s32 d);
void func_00216288(B01Actor *actor, s32 id, Vec3f pos, s32 flag);

void func_002062E0(B01Actor *actor, B01State *state, Vec3f v, s32 p4C, s32 id) {
    B01Actor *p;
    if (id == 0xBD7 && D_801468A0->unk78 != 0 && D_801468A0->unk80 != 0) {
        return;
    }
    if (id == 0x1388 && D_801462D5 == 1) {
        id = *D_800E4680 + 0x1388;
        if (id == 0x1388) {
            return;
        }
    }
    p = func_0028FFB0(D_80131600, &state->unk124.i, id, actor->vec1C, v, p4C, 0);
    if (p != NULL) {
        p->unk1A0 = 0;
        state->unk128.i = state->unk128.i - 1;
        func_00216288(p, 0x11D, p->pos, 0);
    }
}
