#include "b03_types.h"

extern u8 D_80145040[];
Actor *func_0022A82C(void *p);
void func_00209874(BrainB *b, s32 mode);
void func_00211020(BrainB *b);
void func_00209948(BrainB *b, s32 v);
void func_00208410(BrainB *b);
void func_00208EB0(BrainB *b);

void func_00212CC4(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    Actor *t = func_0022A82C(D_80145040);

    if (t == 0 || t != b->actor) {
        func_00209874(b, 2);
    } else {
        b = (BrainB *)actor->owner->brain;
        func_00211020(b);
        func_00209948(b, b->unkC);
        func_00208410(b);
        func_00208EB0(b);
    }
}
