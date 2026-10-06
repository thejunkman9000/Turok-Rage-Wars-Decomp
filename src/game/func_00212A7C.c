#include "b03_types.h"

extern EntList D_8013B364[];
extern f32 D_800C71BC;
void func_0020D014(EntList *list);
void func_0020D1FC(EntList *list);
EntRec *func_0020C994(EntList *list, s32 key);
f32 func_0027272C(Vec3f *a, EntRec *b);
void func_0020D220(EntList *list, s32 key);
void func_0020D0CC(EntList *list, s32 key);
void func_0020D114(EntList *list, void *dst, s32 n);
void func_00211020(BrainB *b);
void func_00208410(BrainB *b);
void func_00208AAC(BrainB *b);
void func_0020FA10(BrainB *b);

void func_00212A7C(ActorB *actor) {
    BrainB *b = actor->owner->brain;
    EntList *L = D_8013B364;
    EntRec *r;
    s32 i;
    s32 busy;
    f32 range;

    if (b->unkC == -1) {
        func_0020D014(L);
        func_0020D1FC(L);
        range = D_800C71BC;
        for (i = 0; i < L->count; i++) {
            r = func_0020C994(L, i);
            if (func_0027272C(&b->actor->pos, r) < range && !(FLD(u32, r, 0xC) & 0x4300000)) {
                func_0020D220(L, i);
            }
        }
        func_0020D0CC(L, b->unk4);
        func_0020D114(L, &b->unk14, 4);
        b->unk28 = b->unkC = L->sel;
    }
    func_00211020(b);
    func_00208410(b);
    func_00208AAC(b);
    busy = (b->actor->flags38 & 0x3000) != 0;
    if (b->unk4 == b->unkC && !busy) {
        func_0020FA10(b);
    }
}
