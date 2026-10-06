#include "p1_types.h"
void func_00209988(Brain *brain);
void func_0021290C(Actor *actor) {
    Brain *brain = actor->owner->brain;
    brain->unk220 = 0;
    func_00209988(brain);
    brain->unk2FC = 0;
    brain->unkC = -1;
}
