#include "b07_types.h"

extern f32 D_800C7E18;

void *func_0024E7CC(s32 id);

void func_0022C070(Actor *actor, s32 id)
{
    void *p = func_0024E7CC(id);

    if (p != NULL) {
        AT(f32, actor, 0x780) += (AT(f32, p, 0x2C) - AT(f32, actor, 0x780)) * D_800C7E18;
    }
}
