#include "b03_types.h"

void func_00209988(BrainB *b);

void func_00212A40(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    b->unk220 = 0;
    b->unkC = -1;
    func_00209988(b);
    b->unk2FC = 0;
}
