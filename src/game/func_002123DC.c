#include "p1_types.h"
void func_00209988(Brain *brain);
s32 func_00274544();
void func_002123DC(Actor *actor) {
    Brain *brain = actor->owner->brain;
    brain->unk220 = 0;
    func_00209988(brain);
    brain->unk2D8 = func_00274544() % 4 + 12;
    brain->unk2DC = func_00274544() % 2;
}
