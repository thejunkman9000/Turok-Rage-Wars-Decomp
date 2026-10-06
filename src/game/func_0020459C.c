#include "p1_types.h"

s32 func_0020459C(Actor *actor) {
s32 v = actor->def->info.unkC; if (v != 0) actor->flags |= 0x2000; else actor->flags &= ~0x2000; return v;
}
