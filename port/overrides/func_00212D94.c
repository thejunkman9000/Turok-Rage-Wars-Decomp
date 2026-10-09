/* port (passthru_fix.py): func_00211020 needs a1 a2 a3, func_00211020 needs a1 a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b03_types.h"

void func_00211020(BrainB *b, u32, u32, u32);
void func_00208410(BrainB *b);
void func_00208AAC(BrainB *b);

void func_00212D94(Actor *actor, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    BrainB *b = (BrainB *)actor->owner->brain;
    s32 v;

    if (b->unk64 == NULL) {
        func_00211020(b, pt_a1, pt_a2, pt_a3);
    } else {
        v = ((BrainB *)b->unk64->owner->brain)->unk4;
        if (v != b->unk10) {
            b->unk10 = v;
        }
        func_00208410(b);
        func_00211020(b, pt_a1, pt_a2, pt_a3);
        func_00208AAC(b);
    }
}
