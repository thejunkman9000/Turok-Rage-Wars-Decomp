#include "b07_types.h"

extern Actor *D_801029F0;
extern s32 D_800D2930;
extern s32 D_800CF228;

void func_44A4C0(Actor *actor);
void func_002227D0(Actor *actor, Actor *state, s32 kind);

void func_0022ECBC(void)
{
    Actor *actor = D_801029F0;

    if (AT(s16, actor, 0x5EA) == 1) {
        func_44A4C0(actor);
    } else {
        func_002227D0(actor, actor, 0x22);
    }
    D_800D2930 = 1;
    D_800CF228 = 0;
}
