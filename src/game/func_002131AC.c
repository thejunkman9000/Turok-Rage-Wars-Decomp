#include "b03_types.h"

void func_00209988(BrainB *b);

void func_002131AC(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    b->unk68 = 0;
    b->unk238 = 0;
    b->unk220 = 0;
    func_00209988(b);
}
