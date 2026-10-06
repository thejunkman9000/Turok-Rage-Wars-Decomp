#include "b03_types.h"
void func_00209988(BrainB *b);
s32 func_00274544(void);
void func_00212450(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    b->unk220 = 0;
    func_00209988(b);
    b->unk2D8 = func_00274544() % 4 + 12;
    b->unk2DC = func_00274544() % 2;
    b->unk2E0 = func_00274544() % 250000 + 360000;
    b->unk320 = -1;
    b->unk318 = 0;
    b->unk31C = 0;
}
