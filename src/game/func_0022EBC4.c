#include "b07_types.h"

s32 func_0024E61C(void *p);
void func_002227D0(Actor *actor, void *obj, s32 kind);

s32 func_0022EBC4(Actor *actor, void *obj)
{
    if (AT(f32, obj, 0x20) <= 0) {
        if (func_0024E61C(obj) != 0) {
            func_002227D0(actor, obj, 2);
            return 1;
        }
    }
    return 0;
}
