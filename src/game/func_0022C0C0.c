#include "b07_types.h"
extern f32 D_800D2988;
void func_0022C0C0(Actor *actor)
{
    if (AT(f32, actor, 0x678) > 0) {
        f32 t = AT(f32, actor, 0x678) - D_800D2988;
        AT(f32, actor, 0x678) = t;
        if (t < 0) {
            AT(f32, actor, 0x678) = 0;
        }
    }
}
