/* port (passthru_fix.py): func_00211020 needs a1 a2 a3, func_00211020 needs a1 a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b03_types.h"

extern EntList D_8013B364[];
extern f32 D_800C71B4;
void func_00211020(BrainB *b, u32, u32, u32);
void func_00208410(BrainB *b);
void func_00208EB0(BrainB *b);
void func_00209874(BrainB *b, s32 mode);
s32 func_0020D1CC(EntList *list, s32 a, s32 b);
f32 func_0027272C(Vec3f *a, Vec3f *b);

void func_00212828(ActorB *actor, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    BrainB *b = actor->owner->brain;
    ActorB *to;
    s32 id;

    if (b->unk64 == NULL) {
        func_00211020(b, pt_a1, pt_a2, pt_a3);
        return;
    }
    to = b->unk64->owner;
    id = to->brain->unk4;
    b->unkC = id;
    if (id != b->unk10) {
        b->unk10 = id;
        if (func_0020D1CC(D_8013B364, b->unk4, id) == 0) {
            func_00209874(b, 1);
            return;
        }
    }
    func_00211020(b, pt_a1, pt_a2, pt_a3);
    func_00208410(b);
    func_00208EB0(b);
    if (func_0027272C(&to->pos, &b->actor->pos) < D_800C71B4 || b->unk4 == b->unkC) {
        func_00209874(b, b->unk230);
    }
}
