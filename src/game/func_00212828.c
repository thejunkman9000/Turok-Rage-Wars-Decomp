#include "b03_types.h"

extern EntList D_8013B364[];
extern f32 D_800C71B4;
void func_00211020(BrainB *b);
void func_00208410(BrainB *b);
void func_00208EB0(BrainB *b);
void func_00209874(BrainB *b, s32 mode);
s32 func_0020D1CC(EntList *list, s32 a, s32 b);
f32 func_0027272C(Vec3f *a, Vec3f *b);

void func_00212828(ActorB *actor) {
    BrainB *b = actor->owner->brain;
    ActorB *to;
    s32 id;

    if (b->unk64 == NULL) {
        func_00211020(b);
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
    func_00211020(b);
    func_00208410(b);
    func_00208EB0(b);
    if (func_0027272C(&to->pos, &b->actor->pos) < D_800C71B4 || b->unk4 == b->unkC) {
        func_00209874(b, b->unk230);
    }
}
