#include "p1_types.h"
extern s32 D_801468C4;

s32 func_00203EB0(Actor *actor, ActorState *unused, Actor *other) {
Actor *owner = actor->owner; if (owner == other || other->unk5E4 == 0) return 0; if (D_801468C4 && owner->stats->unk92 == other->stats->unk92) return 0; return 1;
}
