#include "b03_types.h"

void func_00209988(BrainB *b);

void func_auto_002131E0(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    b->unk220 = 0;
    func_00209988(b);
    b->unk320 = -1;
    b->unk2FC = 0;
}
