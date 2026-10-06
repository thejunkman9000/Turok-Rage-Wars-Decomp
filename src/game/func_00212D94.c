#include "b03_types.h"

void func_00211020(BrainB *b);
void func_00208410(BrainB *b);
void func_00208AAC(BrainB *b);

void func_00212D94(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    s32 v;

    if (b->unk64 == NULL) {
        func_00211020(b);
    } else {
        v = ((BrainB *)b->unk64->owner->brain)->unk4;
        if (v != b->unk10) {
            b->unk10 = v;
        }
        func_00208410(b);
        func_00211020(b);
        func_00208AAC(b);
    }
}
