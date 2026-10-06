#include "p1_types.h"

void func_0022B10C(Actor *actor, s32 amount) {
u16 v = actor->unk16D8 + amount; actor->unk16D8 = v; if (v > 100) v = 100; actor->unk16D8 = v;
}
