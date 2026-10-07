#include "b03_types.h"

extern f32 D_800C71E0;
void func_00208410(BrainB *b);
void func_00208AAC(BrainB *b);
void func_00209874(BrainB *b, s32 mode);
f32 func_00209948(BrainB *b, s32 id);
void func_00211020(BrainB *b);
s32 func_00274544(void);

void func_0021321C(ActorB *actor) {
    BrainB *b = actor->owner->brain;
    ActorB *a;
    s32 busy;
    s32 t;

    if (b->actor->stats->unk8F == 0) {
        func_00209874(b, 2);
        return;
    }
    func_00211020(b);
    b->unk320 = b->unk320 - 1;
    if (b->unk320 == 0) {
        a = b->actor;
        t = a->unk650;
        t ^= 0xF;
        busy = (a->flags38 & 0x3000) != 0;
        if (t && !busy) {
            a->unk6B0 |= 0x10;
        }
    }
    if (b->unk320 < 0) {
        b->unk320 = (func_00274544() % 5 + 3) * 15;
    }
    if (func_00209948(b, b->unkC) < D_800C71E0) {
        b->actor->unk6B0 |= 0x10;
    }
    func_00208410(b);
    func_00208AAC(b);
}
