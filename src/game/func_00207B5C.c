#include "b01_types.h"

void func_00278DE8(Actor *actor, s32 flags, Actor *actor2);

void func_00207B5C(Actor *actor, u32 *flags) {
    ActorInfo *info = &actor->def->info;
    func_00278DE8(actor, 0x10000, actor);
    if (!(info->flags24 & 0x40)) {
        *flags &= 0xFFFEFFFF;
    }
}
