#include "b03_types.h"

extern f32 D_800C71B8;
void func_00211020(BrainB *b);
void func_00208410(BrainB *b);
void func_00208EB0(BrainB *b);
void func_00209874(BrainB *b, s32 mode);
void func_00212670(BrainB *b);
f32 func_0027272C(Vec3f *a, Vec3f *b);

void func_00212948(ActorB *actor) {
    BrainB *b = actor->owner->brain;
    s32 c;

    if (b->unk64 == NULL) {
        func_00211020(b);
        return;
    }
    c = b->unkC;
    if (c == -1) {
        func_00212670(b);
        if (b->unkC == c || b->unkC == b->unk4) {
            func_00209874(b, 4);
            return;
        }
    }
    if (D_800C71B8 < func_0027272C(&b->unk64->owner->pos, &b->actor->pos)) {
        func_00209874(b, b->unk230);
        return;
    }
    func_00211020(b);
    func_00208410(b);
    func_00208EB0(b);
    if (b->unk4 == b->unkC) {
        b->unkC = -1;
    }
}
