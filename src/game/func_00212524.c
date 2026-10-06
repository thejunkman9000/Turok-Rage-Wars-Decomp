#include "b03_types.h"

void func_00209988(BrainB *b);
s32 func_00274544(void);

void func_00212524(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    b->unk220 = 0;
    b->unk2D8 = func_00274544() % 4 + 2;
    b->unk2DC = func_00274544() % 2;
    b->unk2E0 = func_00274544() % 32400 + 10000;
    func_00209988(b);
    b->unk318 = 0;
    b->unk31C = 0;
    b->unk320 = -1;
}
